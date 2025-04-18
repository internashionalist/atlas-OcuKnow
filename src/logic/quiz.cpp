#include "mainwindow.h"
#include "./ui_mainwindow.h"

QFont headerFont("Arial", 24, QFont::Bold);
QFont questionFont("Arial", 18, QFont::Normal);
QFont textFont("Arial", 12, QFont::Normal);

QVector<Question> MainWindow::loadQuestions()
{
    QVector<Question> questions;
    Question newQuestion;
    char sep = ':';

    QFile file(":/questions.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open questions.txt";
        return questions;
    }

    while (!file.atEnd())
    {
        QString line = file.readLine();
        if (line.startsWith("Question")) {
            newQuestion.questionText = line.mid(9).trimmed();
            newQuestion.choices.clear();
        } else if (line.startsWith("Choice")) {
            newQuestion.choices.append(line.mid(8).trimmed());
        } else if (line.startsWith("Answer")) {
            newQuestion.correctAnswer = line.mid(7).trimmed().at(0).toLatin1();
            questions.append(newQuestion);
        }
    }

    return questions;
}

QWidget* MainWindow::buildQuizSplashPage()
{
    QWidget *quizSplashPage = new QWidget;

    //Declare splashPage, initialize and set properties
    QLabel *splashPageHeader = new QLabel("Eye Quizlette");
    QLabel *splashPageInstruction = new QLabel("Over the next 100 pages you will be asked to answer multiple questions on the eye.\nClick 'Start' to being!");
    splashPageStart = new QPushButton("Start");
    splashPageHeader->setAlignment(Qt::AlignCenter);
    splashPageHeader->setFont(headerFont);
    splashPageInstruction->setWordWrap(true);
    splashPageInstruction->setFont(textFont);
    splashPageInstruction->setAlignment(Qt::AlignCenter);
    splashPageStart->setFont(textFont);

    QVBoxLayout *splashLayout = new QVBoxLayout(quizSplashPage);
    splashLayout->addWidget(splashPageHeader);
    splashLayout->addWidget(splashPageInstruction);
    splashLayout->addWidget(splashPageStart);

    return quizSplashPage;
}

void MainWindow::goToNextQuestion() {
    int nextIndex = quizPages->currentIndex() + 1;
    if (nextIndex < quizPages->count()) {
        quizPages->setCurrentIndex(nextIndex);
    } else {
        QWidget *scorePage = buildQuizScorePage();
        setCentralWidget(scorePage);
        // quizPages->setCurrentIndex(quizPages->count() - 1); // Show score page
    }
}

void MainWindow::onStartButtonClicked() {
    quizPages->setCurrentIndex(1);
}

QWidget* MainWindow::buildQuizQuestionPage(const Question& question, int questionIndex, MainWindow* mainWindow) {
    QWidget *page = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(page);

    // Header - centered
    QLabel *header = new QLabel("Question " + QString::number(questionIndex + 1));
    header->setAlignment(Qt::AlignCenter);
    header->setFont(headerFont);
    mainLayout->addWidget(header);

    // Question text - centered
    QLabel *questionLabel = new QLabel(question.questionText);
    questionLabel->setFont(questionFont);
    questionLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(questionLabel);

    // Create a container widget for the radio buttons
    QWidget *choicesContainer = new QWidget;
    QVBoxLayout *choicesLayout = new QVBoxLayout(choicesContainer);

    // Create radio buttons
    QVector<QRadioButton*> choiceButtons;
    QButtonGroup *buttonGroup = new QButtonGroup(page);
    for (int i = 0; i < question.choices.size(); ++i) {
        QRadioButton *radio = new QRadioButton(question.choices[i]);
        choicesLayout->addWidget(radio);
        buttonGroup->addButton(radio, i);
        choiceButtons.append(radio);
    }

    // Remove margins to make it look better
    choicesLayout->setContentsMargins(0, 0, 0, 0);

    // Create a horizontal layout to center the choices container
    QHBoxLayout *centeringLayout = new QHBoxLayout;
    centeringLayout->addStretch(); // Add stretch on the left
    centeringLayout->addWidget(choicesContainer); // Add the choices in the middle
    centeringLayout->addStretch(); // Add stretch on the right

    // Add the centering layout to the main layout
    mainLayout->addLayout(centeringLayout);

    // Feedback label - centered
    QLabel *feedbackLabel = new QLabel("");
    feedbackLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(feedbackLabel);

    // Next button - centered
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *nextButton = new QPushButton("Next");
    nextButton->setEnabled(false);
    buttonLayout->addStretch();
    buttonLayout->addWidget(nextButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // Connect signals and slots as before
    QObject::connect(buttonGroup, QOverload<int>::of(&QButtonGroup::idClicked), [=](int id){
        // Check if correct
        char selected = 'A' + id;
        if (selected == question.correctAnswer) {
            feedbackLabel->setText("Correct!");
            feedbackLabel->setStyleSheet("color: green;");
            mainWindow->score++;
        } else {
            feedbackLabel->setText(QString("Incorrect! Correct answer: %1").arg(question.correctAnswer));
            feedbackLabel->setStyleSheet("color: red;");
        }
        nextButton->setEnabled(true);
    });

    QObject::connect(nextButton, &QPushButton::clicked, mainWindow, [=]() {
        mainWindow->goToNextQuestion();
    });

    return page;
}

QWidget* MainWindow::buildQuizScorePage()
{
    QWidget *scorePage = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(scorePage);
    QLabel *header = new QLabel("Quiz Final Score");
    QLabel *scoreText = new QLabel();
    QPushButton *restartButton = new QPushButton("Restart Quiz");

    layout->addWidget(header);
    layout->addWidget(scoreText);
    layout->addWidget(restartButton);

    scoreText->setText(QString("You successfully answered %1 out of %2!").arg(score).arg(numQuestions));
    header->setAlignment(Qt::AlignCenter);
    header->setFont(headerFont);

    scoreText->setAlignment(Qt::AlignCenter);
    scoreText->setFont(textFont);
    scoreText->setWordWrap(true);

    //Add Flavor Text with Percantage and Grade

    QObject::connect(restartButton, &QPushButton::clicked, this, &MainWindow::runQuiz);

    return scorePage;
}

void MainWindow::resetQuiz()
{
    score = 0;
    quizPages->setCurrentIndex(0);
}

void MainWindow::runQuiz()
{
    score = 0;

    QVector<Question> questions = loadQuestions();
    numQuestions = questions.count();
    // Create individual Quiz Pages
    QWidget *quizSplashPage = buildQuizSplashPage();

    //Create stacked widget and insert quiz pages as widgets
    quizPages = new QStackedWidget(this);
    quizPages->addWidget(quizSplashPage);
    for (int i = 0; i < numQuestions; i++)
        quizPages->addWidget(buildQuizQuestionPage(questions[i], i, this));

    //set quizSplashPage to the first widget
    quizPages->setCurrentWidget(quizSplashPage);

    //Create Main Layout, set it to the centrawidget, and load everything in
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(quizPages);

    //set initial centralWidget to centralWidget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    //starts the whole shebang and hopefully takes care of itself
    connect(splashPageStart, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    runQuiz();
}

//5 anatomical and 5 anatomical questions

MainWindow::~MainWindow()
{
    delete ui;
}
