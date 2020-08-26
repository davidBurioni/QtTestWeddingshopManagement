#include "mainwindow.h"
#include "mainmenuwidget.h"
#include "buttonsevents.h"
#include "inventorywidget.h"
#include <QLabel>
#include <QApplication>
#include <QtSql/QSqlQuery>
#include <QtDebug>

struct myLabel:QLabel{
    myLabel(QString name)
    {
        this->setText(name);
        QFont font = this->font();
        font.setPointSize(16);
        //font.setBold(true);
        this->setFont(font);
    }
};


void init_database()
{
    qDebug()<<"start";
    QSqlDatabase db;
    db= QSqlDatabase::addDatabase("QSQLITE");
    // QDir::currentPath();
    db.setDatabaseName("C:/Sqlite/db.sqlite");
    // QString qasd=QDir::currentPath();
    // std::cout <<qasd.toStdString();
    // qDebug()<<"problem open db: "<<qasd;

    if(!db.open())
    {
        qDebug()<<"problem open db";
    }

    QString query= "CREATE TABLE IF NOT EXISTS weddingDress("
                   "ID integer PRIMARY KEY,"
                   "sex VARCHAR(20),"
                   "style VARCHAR(20),"
                   "model VARCHAR(20),"
                   "size integer,"
                   "color VARCHAR(20),"
                   "year integer,"
                   "quantity integer,"
                   "costBuy double,"
                   "costSell double,"
                   "note VARCHAR(100),"
                   "owner VARCHAR(20))";


    QSqlQuery qry;
    if(!qry.exec(query))
    {
        qDebug()<<"error creating table";
    }

    QString query2= "CREATE TABLE IF NOT EXISTS accessory("
                    "ID integer,"
                    "sex VARCHAR(20),"
                    "brand VARCHAR(20),"
                    "model VARCHAR(20),"
                    "type VARCHAR(20),"
                    "quantity integer,"
                    "costBuy double,"
                    "costSell double,"
                    "owner VARCHAR(20))";


    QSqlQuery qry2;
    if(!qry2.exec(query2))
    {
        qDebug()<<"error creating table";
    }

    QString query3="CREATE TABLE IF NOT EXISTS weddingDress_find("
                   "ID integer,"
                   "sex VARCHAR(20),"
                   "style VARCHAR(20),"
                   "model VARCHAR(20))";


    QSqlQuery qry3;
    if(!qry3.exec(query3))
    {
        qDebug()<<"error creating table";
    }


    db.close();
    qDebug()<<"end<";
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    init_database();

    auto* mainMenu= new MainMenuWidget();
    auto* inventoryMenu= new InventoryWidget();
    QWidget *thirdPageWidget = new QWidget;


    QStackedWidget *stackedWidget = new QStackedWidget;
    //add page at stackedWidget
    stackedWidget->addWidget(mainMenu->widget);
    stackedWidget->addWidget(inventoryMenu->widget);
    stackedWidget->addWidget(thirdPageWidget);

    //create a layout for give widget
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);

    auto *firstMenu_wdg= new QWidget();
    firstMenu_wdg->setLayout(layout);


    ButtonsEvents  b(stackedWidget);
    stackedWidget->setCurrentIndex(b.value());
    w.setCentralWidget(firstMenu_wdg);


    w.connect(mainMenu->button_inventory,&QPushButton::clicked,&b, &ButtonsEvents::goto_inventory);
    w.connect(inventoryMenu->button_back,&QPushButton::clicked,&b, &ButtonsEvents::goto_mainMenu);

    return a.exec();
}



