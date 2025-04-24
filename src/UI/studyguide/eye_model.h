#ifndef EYE_MODEL_H
#define EYE_MODEL_H

#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>


class Eye_model : public QWindow
{
    Q_OBJECT
public:
    explicit Eye_model(QWidget *parent = nullptr);
    ~Eye_model();

private slots:
    void insertBoldText();
    void insertItalicText();
    void insertUnderlinedText();

};

#endif
