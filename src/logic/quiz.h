#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QStackedWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QRadioButton>
#include <QMessageBox>
#include <QStringTokenizer.h>
#include <QButtonGroup>
#include <QDirIterator>
#include <QDir>
// #include <QAbstractButton>

struct Question {
    QString questionText;
    QVector<QString> choices;
    char correctAnswer;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onStartButtonClicked();

private:
    void runQuiz();
    QWidget* buildQuizQuestionPage(const Question& question, int questionIndex, MainWindow* mainWindow);
    QWidget *buildQuizSplashPage();
    QVector<Question> loadQuestions();
    QWidget* buildQuizScorePage();
    void goToNextQuestion();
    void resetQuiz();

    int score, numQuestions;
    QStackedWidget *quizPages;
    QPushButton *splashPageStart;
    Ui::MainWindow *ui;

// private slots:
    // void onStartButtonClicked();
};
#endif // MAINWINDOW_H
