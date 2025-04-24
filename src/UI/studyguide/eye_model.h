#ifndef EYE_MODEL_H
#define EYE_MODEL_H

#include <QDialog>
#include "ui_eye_model.h"

class Eye_model : public QDialog
{
	Q_OBJECT

public:
	explicit Eye_model(QWidget *parent = nullptr);
	~Eye_model();

private:
	Ui::Dialog *ui;
private slots:
	void insertBoldText();
	void insertItalicText();
	void insertUnderlinedText();
};

#endif /* EYE_MODEL_H */
