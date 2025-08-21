#ifndef EYE_MODEL_H
#define EYE_MODEL_H

<<<<<<< HEAD
#include <QWidget>
#include "ui_eyemodel.h"

class EyeModel : public QWidget
=======
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>

class EyeModel : public QDialog
<<<<<<< HEAD
>>>>>>> parent of b71e307 (get like me)
{
	Q_OBJECT
=======
{
    Q_OBJECT
>>>>>>> parent of b71e307 (get like me)
public:
	explicit EyeModel(QWidget *parent = nullptr);
	~EyeModel();

signals:
	void takeQuizClicked();
	void creditsClicked();
	void returnToIntro();

private slots:
	void handleTakeQuiz();
	void handleCredits();

signals:
	void takeQuizClicked();
	void creditsClicked();
	void returnToIntro();

private slots:
	void handleTakeQuiz();
	void handleCredits();

private:
	Ui::EyeModel *ui;
<<<<<<< HEAD
<<<<<<< HEAD
=======
	QPushButton *takeQuizButton;
	QPushButton *creditsButton;

>>>>>>> parent of b71e307 (get like me)
=======
	QPushButton *takeQuizButton;
	QPushButton *creditsButton;

>>>>>>> parent of b71e307 (get like me)
};

#endif // EYE_MODEL_H