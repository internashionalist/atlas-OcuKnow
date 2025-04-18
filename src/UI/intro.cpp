#include "intro.h"
#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>
#include <QStackedLayout>

Intro::Intro(QWidget *parent) : QWidget(parent)
{
	QLabel *background = new QLabel(this);
	QMovie *movie = new QMovie(":/splash.gif");
	background->setMovie(movie);
	movie->start();
	background->setScaledContents(true);

	QWidget *overlay = new QWidget(this);
	overlay->setAttribute(Qt::WA_TranslucentBackground);
	QVBoxLayout *layout = new QVBoxLayout(overlay);
	layout->setAlignment(Qt::AlignCenter);

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
			padding: 10px 20px;
		}
		QPushButton:hover {
			background-color: rgba(255, 255, 255, 210);
		}
	)";

	enterStudyGuideButton->setStyleSheet(style);
	takeQuizButton->setStyleSheet(style);
	creditsButton->setStyleSheet(style);

	layout->addSpacing(350);
	layout->addWidget(enterStudyGuideButton);
	layout->addWidget(takeQuizButton);
	layout->addWidget(creditsButton);

	connect(enterStudyGuideButton, &QPushButton::clicked, this, &Intro::handleEnterStudyGuide);
	connect(takeQuizButton, &QPushButton::clicked, this, &Intro::handleTakeQuiz);
	connect(creditsButton, &QPushButton::clicked, this, &Intro::handleCredits);

	QStackedLayout *stack = new QStackedLayout(this);
	stack->addWidget(background);
	stack->addWidget(overlay);
	setLayout(stack);
}

void Intro::handleEnterStudyGuide()
{
	emit enterStudyGuideClicked();
}

void Intro::handleTakeQuiz()
{
	emit takeQuizClicked();
}

void Intro::handleCredits()
{
	emit creditsClicked();
}
