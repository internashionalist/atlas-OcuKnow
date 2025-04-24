#include "introwidget.h"

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

    /* set up the background music */
    QSoundEffect *effect = new QSoundEffect(this);
    effect->setSource(QUrl("qrc:/assets/meydan_away_wav.wav"));  // Note: Convert your OGG to WAV first
    // effect->setSource(QUrl::fromLocalFile("C:/Users/snewb/OneDrive/Documents/GitHub/OcuKnow/src/assets/meydan_away_wav.wav"));
    effect->setLoopCount(QSoundEffect::Infinite);
    effect->setVolume(0.35);
    effect->play();

    // Connect to status signal to check if it's working
    connect(effect, &QSoundEffect::statusChanged, [=]() {
        qDebug() << "Sound effect status:" << effect->status();
    });

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
		background-color: #4FA3E3;
		color: white;
		font-size: 20px;
		font-family: 'Orbitron', sans-serif;
		border: 2px solid white;
		border-radius: 10px;
		padding: 5px 20px;
	}
	QPushButton:hover {
		background-color: white;
		color: #4FA3E3;
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
