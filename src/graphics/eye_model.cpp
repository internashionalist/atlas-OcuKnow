#include <QPixmap>
#include <QLabel>
#include <QDebug>

QPixmap pixmap(":/images/half image eye.jpg");
ui->label->setPixmap(pixmap);

if (pixmap.isNull())
    {
        qDebug() << "Error";
    } else {
    	ui->label->setPixmap(pixmap);
    	qDebug() << "Success";
    }

