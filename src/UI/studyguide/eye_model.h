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
#include <QWidget>

#include "ui_eye_model.h"

class Eye_model : public QWidget
{
	Q_OBJECT

public:
	explicit Eye_model(QWidget *parent = nullptr);
	~Eye_model();

private:
	Ui::Eye_model *ui;

private slots:
	void insertBoldText();
	void insertItalicText();
	void insertUnderlinedText();
};

#endif
