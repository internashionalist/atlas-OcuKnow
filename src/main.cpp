#include <QApplication>
#include "UI/introwidget.h"
#include "logic/quiz.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// Quiz q; //starts directly with Quiz (for quiz debugging)
	// q.show();

	IntroWidget intro;
	intro.show();

	QObject::connect(&intro, &IntroWidget::takeQuizClicked, [&]()
					 {
	Quiz *quiz = new Quiz();
	quiz->show();
	intro.close(); });

	return app.exec();
}
