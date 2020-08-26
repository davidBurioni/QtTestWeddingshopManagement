#pragma once
#include <QObject>
#include <QStackedWidget>
#include <iostream>

 class QStackedWidget;

class ButtonsEvents:  public QObject
{
    Q_OBJECT

public:
    ButtonsEvents(QStackedWidget *Widget);

    int value() const { return m_value; }

public slots:
    void goto_inventory();
    void goto_mainMenu();

signals:
    void valueChanged(int newValue);

private:
    int m_value;
    QStackedWidget *widget;
};
