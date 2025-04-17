#include <QPixmap>
#include <QLabel>

QPixmap pixmap(":/images/half image eye.jpg");
QPixmap pixmap = QPixmap::frontImage(image);
    ui->label->setPixmap(pixmap);

if (pixmap.isNull())
    {
        qDebug() << "Error";
    } else {
    ui->label->setPixmap(pixmap);
    qDebug() << "Success";
    }

