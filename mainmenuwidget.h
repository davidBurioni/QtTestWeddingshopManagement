#pragma once
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <iostream>
#include <QtDebug>

class MainMenuWidget
{
public:

    MainMenuWidget();
    MainMenuWidget(const MainMenuWidget& other)=delete;
    MainMenuWidget(MainMenuWidget&& other)=delete;

    MainMenuWidget &operator=(const MainMenuWidget& other)=delete;
    MainMenuWidget &operator=(MainMenuWidget&& other)=delete;

    QWidget* widget;
    QPushButton* button_inventory;

private:
    QPushButton* button_clients;
    QPushButton* button_payments;
    QHBoxLayout* up_rect;
};
