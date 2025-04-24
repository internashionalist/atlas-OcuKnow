#ifndef EYE_MODEL_H
#define EYE_MODEL_H

#include <QWidget>
#include "ui_eyemodel.h"

class EyeModel : public QWidget
{
	Q_OBJECT
public:
	explicit EyeModel(QWidget *parent = nullptr);
	~EyeModel();

private:
	Ui::EyeModel *ui;
};

#endif // EYE_MODEL_H