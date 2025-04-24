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


class EyeModel : public QWindow
{
    Q_OBJECT
public:
    explicit EyeModel(QWidget *parent = nullptr);
    ~EyeModel();

private slots:
    void insertBoldText();
    void insertItalicText();
    void insertUnderlinedText();

};

#endif
