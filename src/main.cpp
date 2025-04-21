#include <QApplication>
#include "UI/introwidget.h"
#include "logic/quiz.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    // Quiz q; //starts directly with Quiz (for quiz debugging)
    // q.show();

    IntroWidget intro;
    intro.resize(2000, 300);
    intro.show();

	return app.exec();
}
