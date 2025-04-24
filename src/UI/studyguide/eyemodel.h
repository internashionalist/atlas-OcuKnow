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
#include <QAudioOutput>

#include "ui_eyemodel.h"

namespace Ui
{
	class EyeModel;
}
class EyeModel : public QWidget
{
    Q_OBJECT
public:
    explicit EyeModel(QWidget *parent = nullptr);
    ~EyeModel();

private:
    Ui::EyeModel *ui;
};

#endif
