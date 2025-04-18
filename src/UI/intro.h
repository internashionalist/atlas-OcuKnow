#ifndef INTRO_H
#define INTRO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMovie>

class Intro : public QWidget
{
	Q_OBJECT

public:
	explicit Intro(QWidget *parent = nullptr);

signals:
	void enterStudyGuideClicked();
	void takeQuizClicked();
	void creditsClicked();

private slots:
	void handleEnterStudyGuide();
	void handleTakeQuiz();
	void handleCredits();

private:
	QPushButton *enterStudyGuideButton;
	QPushButton *takeQuizButton;
	QPushButton *creditsButton;
};

#endif /* INTRO_H */
