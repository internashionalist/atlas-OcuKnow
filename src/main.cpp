#include <QApplication>
#include "UI/intro/introwidget.h"
#include "UI/quiz/quiz.h"
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
    QDialog *dialog = new QDialog();
    Ui::Dialog *ui = new Ui::Dialog();
    ui->setupUi(dialog);
    dialog->setWindowTitle("Study Guide");
    intro.close();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->exec();
    });

    return app.exec();
}
