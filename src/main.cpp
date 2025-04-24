#include <QApplication>
#include <QDialog>
#include <QWidget>
#include "UI/credits/creditswidget.h"
#include "UI/intro/introwidget.h"
#include "UI/quiz/quiz.h"
#include "UI/studyguide/ui_eyemodel.h"
#include "UI/studyguide/eyemodel.h"

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
        intro.hide();
    });

    QObject::connect(&intro, &IntroWidget::enterStudyGuideClicked, [&]() {
        EyeModel *studyGuide = new EyeModel();
        studyGuide->setWindowTitle("Study Guide");
        studyGuide->setAttribute(Qt::WA_DeleteOnClose);
        studyGuide->show();
        intro.hide();
    });

    QObject::connect(&intro, &IntroWidget::creditsClicked, [&]() {
        CreditsWidget *credits = new CreditsWidget();
        credits->setWindowTitle("Credits");

        QObject::connect(credits, &CreditsWidget::returnToIntro, [&]() { intro.show(); });

        credits->show();
        intro.hide();
    });

    return app.exec();
}
