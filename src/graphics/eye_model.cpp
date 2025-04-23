#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>


QPixmap pixmap(":/images/half image eye.jpg");
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


    playlist->addMedia(QUrl("Vibin-chosic favorite.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop); // Loops continuously

    player->setPlaylist(playlist);
    player->setVolume(50);
    player->play();

    QToolButton *toolButton = new QToolButton(this);
    toolButton->setText("Insert Text");
    toolButton->setPopupMode(QToolButton::MenuButtonPopup);

    QMenu *menu = new QMenu(toolButton);
    menu->addAction("Bold Text", this, SLOT(insertBoldText()));
    menu->addAction("Italic Text", this, SLOT(insertItalicText()));
    menu->addAction("Underlined Text", this, SLOT(insertUnderlinedText()));
    toolButton->setMenu(menu);

    void DropMenu::insertBoldText() {
        yourTextWidget->setText("<b>Bold Text</b>");
    }
    
    void DropMenu::insertItalicText() {
        yourTextWidget->setText("<i>Italic Text</i>");
    }
    
    void DropMenu::insertUnderlinedText() {
        yourTextWidget->setText("<u>Underlined Text</u>");
    }