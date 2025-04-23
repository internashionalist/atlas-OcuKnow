#include <QPixmap>
#include <QLabel>
#include <QDebug>

QPixmap pixmap(":/assets/halfeyeimage.jpg");
ui->label->setPixmap(pixmap);

if (pixmap.isNull())
    {
        qDebug() << "Error";
    } else {
    	ui->label->setPixmap(pixmap);
    	qDebug() << "Success";
    }

    // buttons adjust as needed
    struct EyePart {
        QString name;
        int x, y, width, height;
    };
    
    EyePart eyeParts[] = {
        {"Cornea", 100, 150, 80, 40}, 
        {"Retina", 200, 250, 80, 40},
        {"Lens", 150, 180, 70, 40},
        {"Optic Nerve", 300, 280, 90, 40},
        {"Sclera", 50, 130, 100, 40},
        {"Pupil", 170, 170, 50, 50},
        {"Iris", 160, 160, 60, 60},
        {"Ciliary Body", 140, 200, 80, 40},
        {"Macula", 240, 260, 80, 40},
        {"Fovea", 250, 270, 60, 40},
        {"Choroid", 80, 160, 100, 50},
        {"Vitreous Body", 180, 210, 120, 60}
    };
    
    //buttons
    for (const auto& part : eyeParts) {
        QGraphicsEllipseItem* item = scene->addEllipse(part.x, part.y, part.width, part.height, QPen(), QBrush(Qt::transparent));
        
        item->setFlag(QGraphicsItem::ItemIsSelectable);
        QObject::connect(scene, &QGraphicsScene::selectionChanged, this, [=]() {
            if (item->isSelected()) {
                qDebug() << "Clicked: " << part.name;
            }
        });
    }
    
    
    //for single button -- reuse if needing menu button
    
    // //Overlay
    // QPushButton* corneaButton = QPushButton("Cornea", this);
    // corneaButton->setGeometry(100, 150, 80, 40); //x, y width and height adjust as needed
    
    // //Control
    // QGraphicsProxyWidget* buttonProxy = scene->addWidget(new QPushButton("Cornea"));
    // buttonProxy->setPos(100, 150);
    
    // //Scale dynamically
    // int imaageWidth = pixmap.width();
    // int imageHeight = pixmap.height();
    
    // //adjust button position
    // corneraButton->move(imageWidth * 0.3, imageHeight * 0.4);
    
    // //hover
    // corneaButton->setStyleSheet("QPushButton:hover { background-color: grey; }");
    
    // //click event
    // connect(corneaButton, &QPushButton::clicked, this, []() {
    //     qDebug() << "Cornea button clicked!";
    // });