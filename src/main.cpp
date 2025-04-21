#include <QApplication>
#include "UI/introwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    IntroWidget intro;
    intro.resize(2000, 300);
    intro.show();

    return app.exec();
}
