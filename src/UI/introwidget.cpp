#include "introwidget.h"
#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>
#include <QStackedLayout>

IntroWidget::IntroWidget(QWidget *parent) : QWidget(parent)
{
    /* set-up for layout of both widgets */
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QStackedLayout *stack = new QStackedLayout();
    stack->setStackingMode(QStackedLayout::StackAll);
    mainLayout->addLayout(stack);

    /* background widget */
    QLabel *background = new QLabel(this);
    QMovie *movie = new QMovie(":/splash.gif");
    background->setMovie(movie);
    movie->start();
    background->setScaledContents(true);
    background->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    stack->addWidget(background);

    /* overlay widget for buttons */
    QWidget *overlay = new QWidget(this);
    overlay->setAttribute(Qt::WA_TranslucentBackground);
    QVBoxLayout *overlayLayout = new QVBoxLayout(overlay);
    overlayLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    overlayLayout->setContentsMargins(0, 500, 0, 80);

    /* buttons */
    enterStudyGuideButton = new QPushButton("Enter Study Guide");
    takeQuizButton = new QPushButton("Take Quiz");
    creditsButton = new QPushButton("Credits");

    QString style = R"(
    QPushButton {
        background-color: rgba(255, 255, 255, 180);
        color: #4FA3E3;
        font-size: 20px;
        font-family: 'Orbitron', sans-serif;
        border: 2px solid #4FA3E3;
        border-radius: 10px;
        padding: 5px 20px;
    }
    QPushButton:hover {
        background-color: rgba(255, 255, 255, 210);
    })";

    enterStudyGuideButton->setStyleSheet(style);
    takeQuizButton->setStyleSheet(style);
    creditsButton->setStyleSheet(style);

    overlayLayout->addWidget(enterStudyGuideButton);
    overlayLayout->addWidget(takeQuizButton);
    overlayLayout->addWidget(creditsButton);
    overlayLayout->addStretch();

    stack->addWidget(overlay);
    overlay->raise();

    /* signals */
    connect(enterStudyGuideButton, &QPushButton::clicked, this, &IntroWidget::handleEnterStudyGuide);
    connect(takeQuizButton, &QPushButton::clicked, this, &IntroWidget::handleTakeQuiz);
    connect(creditsButton, &QPushButton::clicked, this, &IntroWidget::handleCredits);
}

void IntroWidget::handleEnterStudyGuide()
{
	emit enterStudyGuideClicked();
}

void IntroWidget::handleTakeQuiz()
{
	emit takeQuizClicked();
}

void IntroWidget::handleCredits()
{
	emit creditsClicked();
}
