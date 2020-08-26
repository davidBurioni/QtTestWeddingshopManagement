#include "buttonsevents.h"

ButtonsEvents::ButtonsEvents(QStackedWidget *Widget)
{
    m_value = 0;
    widget=Widget ;
}

void ButtonsEvents::goto_inventory()
{
    m_value = 1;
    widget->setCurrentIndex(m_value);
    std::cout<<"value: "<<m_value<<"\n";
}

void ButtonsEvents::goto_mainMenu()
{
    m_value = 0;
    widget->setCurrentIndex(m_value);
    std::cout<<"value: "<<m_value<<"\n";
}


