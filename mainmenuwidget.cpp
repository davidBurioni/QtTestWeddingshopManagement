#include "mainmenuwidget.h"

MainMenuWidget::MainMenuWidget()
{
    qDebug()<<"enter";
    widget = new QWidget;
    up_rect= new QHBoxLayout;
    button_inventory= new QPushButton{"Inventory"};
    button_clients= new QPushButton{"Clients"};
    button_payments= new QPushButton{"Payments"};
    qDebug()<<"Create a buttons";
    up_rect->setAlignment(Qt::AlignCenter);
    qDebug()<<"set alignment";
    up_rect->addWidget(button_inventory);
    up_rect->addWidget(button_clients);
    up_rect->addWidget(button_payments);
    qDebug()<<"add button at rect";
    widget->setLayout(up_rect);
    qDebug()<<"set layout at widget";
}
