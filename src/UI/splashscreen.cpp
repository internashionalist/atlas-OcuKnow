#include "SplashScreen.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

SplashScreen::SplashScreen(QWidget *parent) : QWidget(parent), timer(new QTimer(this))
{
	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *title = new QLabel("OcuKnow", this);
	title->setStyleSheet("font-size: 32px; font-weight: bold; color: navy;");
	title->setAlignment(Qt::AlignCenter);

	QLabel *tagline = new QLabel("Discover the Eye – Interactive Anatomy at Your Fingertips.", this);
	tagline->setAlignment(Qt::AlignCenter);

	QPushButton *enterButton = new QPushButton("Enter", this);
	connect(enterButton, &QPushButton::clicked, this, &SplashScreen::onTimeout);

	layout->addWidget(title);
	layout->addWidget(tagline);
	layout->addWidget(enterButton);
	setLayout(layout);

	timer->setSingleShot(true);
	connect(timer, &QTimer::timeout, this, &SplashScreen::onTimeout);
	timer->start(3000); // auto-transition after 3 seconds
}

void SplashScreen::onTimeout()
{
	emit splashFinished();
}
