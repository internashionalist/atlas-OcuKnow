#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QObject>
#include <QEvent>


// Intro image -- Away will go with this image
QGraphicsScene* scene = new QGraphicsScene();
QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap("OcuKnow banner final.mp3"));
scene->addItem(item);
ui->graphicsView->setScene(scene);

QMediaPlayer* player = new QMediaPlayer();
player->setMedia(QUrl::fromLocalFile("Meydan-Away Background.mp3"));
player->play();


// set image for eye model -- vibin will go with this image
QGraphicsScene* scene = new QGraphicsScene();
QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap("half eye image.jpg"));
scene->addItem(item);
ui->graphicsView->setScene(scene);


// will figure out were else to put this if it gets too crowded here
QGraphicsScene* scene = new QGraphicsScene();
QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap("half eye image.jpg"));
scene->addItem(item);
ui->graphicsView->setScene(scene);


// snippet for background sound
QMediaPlayer* player = new QMediaPlayer();
player->setMedia(QUrl::fromLocalFile("Vibin-chosic favorite.mp3"));
player->play();

// block for clicking layers
void EyeLayer::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    qDebug() << "Clicked on " << layerName;
    emit layerClicked(layerName);
}
