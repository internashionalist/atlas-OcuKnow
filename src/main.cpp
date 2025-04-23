#include <QApplication>
#include "UI/intro/introwidget.h"
#include "UI/quiz/quiz.h"
#include "UI/credits/creditswidget.h"
#include "ui_eyemodel.h"
#include <QDialog>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// Quiz q; //starts directly with Quiz (for quiz debugging)
	// q.show();

	IntroWidget intro;
	intro.show();

	QObject::connect(&intro, &IntroWidget::takeQuizClicked, [&]() {
		Quiz *quiz = new Quiz();
		quiz->show();
		intro.close();
    });

    QObject::connect(&intro, &IntroWidget::enterStudyGuideClicked, [&]() {
        QDialog *studyGuide = new QDialog();
        Ui::Dialog *ui = new Ui::Dialog();
        ui->setupUi(studyGuide);
        studyGuide->setWindowTitle("Study Guide");
        studyGuide->setAttribute(Qt::WA_DeleteOnClose);
        studyGuide->show();
        intro.close();
    });

    QObject::connect(&intro, &IntroWidget::creditsClicked, [&]() {
		CreditsWidget *credits = new CreditsWidget();
		credits->setWindowTitle("Credits");
		credits->show();
		intro.close();
    });

    return app.exec();
}
