#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include <QWidget>
#include "eye_model.h"
// #include "ui_eye_model.h"

Eye_model::Eye_model(QWidget *parent) : QWidget(parent),
    ui(new Ui::Eye_model)
{
    QPixmap pixmap("/halfeyeimage.jpg");
    ui->label->setPixmap(pixmap);

    if (pixmap.isNull())
    {
        qDebug() << "Error";
    } else {
    	ui->label->setPixmap(pixmap);
    	qDebug() << "Success";
    }


QMediaPlayer *player = new QMediaPlayer(this);
QMediaPlaylist *playlist = new QMediaPlaylist(player);


playlist->addMedia(QUrl("/Vibin-chosic favorite.mp3"));
playlist->setPlaybackMode(QMediaPlaylist::Loop); // Loops continuously

player->setPlaylist(playlist);
player->setVolume(50);
player->play();


    ui->setupUi(this);
    ui->Iris->setToolTip("Iris"
"<ul>"
"<li>ir/o - iris</li>"
"<li>irid/o - iris</li>"
"<li>iridal - pertaining to the iris</li>"
"<li>iridectomy - excision of the iris</li>"
"<li>regulates the amount of light that enters your eye by controlling dilation and constriction.
It is the coloured, visible part of your eye in front of the lens.
Located behind the cornea and in front of the chrystalline lens, this structure separates the anterior and posterior chambers of the eye.</li>"
"</ul>")


    ui->Pupil->setToolTip("Pupil"
"<ul>"  
"<li>pupill/o - pupil</li>"
"<li>pupillary - pertaining to the pupil</li>"
"<li>pupilloplasty - surgical repair of the pupil</li>"
"<li>Regulates how much light enters the eye.
It's size is automatically varied to regulate the amount of light entering the eye.
It is the dark center in the middle of the iris.</li>")

    ui->Cornea->setToolTip("Cornea"
"<ul>"
"<li>corne/o - cornea</li>"
"<li>kerat/o - cornea</li>"
"<li>corneal - pertaining to the cornea</li>"
"<li>keratitis - inflammation of the cornea</li>"
"<li>keratoplasty - surgical repair of the cornea</li>"
"corneal - pertaining to the cornea
Transparent circular part of the front eye, refracts the light entering the eye onto the lens and then onto the retina.\nContains no blood vessels and extremely sensitive to pain"
"<ul>")

    ui->Sclera->setToolTip("Sclera"
"<ul>"
"<li>scler/o - sclera</li>"
"<li>scleral - pertaining to the sclera</li>"
"<li>scleritis - inflammation of the sclera</li>"
"<li>sclerotomy - incision of the sclera</li>"
"<li>White part of the eye, protects the inner structures of the eye and maintains the shape of the eyeball.</li>"
"<ul>")

    ui->Choroid->setToolTip("Choroid"
"<ul>"
"<li>choroid/o - choroid</li>"
"<li>choroidal - pertaining to the choroid</li>"
"<li>choroiditis - inflammation of the choroid</li>"
"<li>choroidopathy - disease of the choroid</li>"
"<li>choroidectomy - excision of the choroid</li>"
"<li>Middle layer of the eye, contains blood vessels and connective tissue.\nIt is located between the sclera and retina.</li>"
"<ul>")

    ui->Lens->setToolTip("Lens"
"<ul>"
"<li>phac/o - lens</li>"
"<li>phak/o - lens</li>"
"<li>lenticular - pertaining to the lens</li>"
"<li>phacitis - inflammation of the lens</li>"
"<li>phacoemulsification - process of using ultrasound to break up a lens</li>"
"<li>Transparent structure located behind the iris and pupil, refracts light onto the retina.\n
It is flexible and can change shape to focus on objects at different distances.</li>"
"<ul>")

    ui->Retina->setToolTip("Retina"
"<ul>"
"<li>retin/o - retina</li>"
"<li>retinal - pertaining to the retina</li>"
"<li>retinitis - inflammation of the retina</li>"
"<li>retinopathy - disease of the retina</li>"
"<li>retinal detachment - separation of the retina from the underlying tissue</li>"
"<li>Inner layer of the eye, contains photoreceptor cells (rods and cones) that convert light into electrical signals.\nThese signals are sent to the brain via the optic nerve.</li>"
"<ul>")

    ui->Vitreous Body->setToolTip("Vitreous Body"
"<ul>"
"<li>vitre/o - vitreous</li>"
"<li>vitreous humor - clear gel-like substance that fills the space between the lens and retina</li>"
"<li>vitrectomy - surgical removal of the vitreous humor</li>"
"<li>vitreous body - the clear gel-like substance that fills the space between the lens and retina</li>"
"<li>vitreous cavity - the space filled with vitreous humor</li>"
"<li>Vitreous humor is a clear gel-like substance that fills the space between the lens and retina.\nIt helps maintain the shape of the eye and provides support to the retina.</li>"
"<ul>")

    ui->Optic Disk->setToolTip("Optic Disk"
"<ul>"
"<li>papill/o - optic disk</li>"
"<li>Known as the blind spot, located on the retina. Visible point where the optic nerve leaves the eyeball and where retinal blood vessels enter and leave.</li>"
"<ul>")
    
        ui->Optic Nerve->setToolTip("Optic Nerve")

}


// Prob don't need this

// QToolButton *toolButton = new QToolButton(this);
// toolButton->setText("Insert Text");
// toolButton->setPopupMode(QToolButton::MenuButtonPopup);

