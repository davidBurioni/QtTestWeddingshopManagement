#pragma once
#include <QWidget>
#include <pageadditem.h>
#include <tableditor.h>
#include <QTabWidget>

class InventoryWidget :public QWidget
{
    Q_OBJECT

public:
    InventoryWidget();

    InventoryWidget(const InventoryWidget& other)=delete;
    InventoryWidget(InventoryWidget&& other)=delete;

    InventoryWidget &operator=(const InventoryWidget& other)=delete;
    InventoryWidget &operator=(InventoryWidget&& other)=delete;

    QWidget* widget;
    QPushButton* button_back;

public slots:
    void FindMerriedTable();

private:
    QWidget* widget_add_item;
    QWidget* widget_page_merried;
    QHBoxLayout *boxH_page_merried;
    QVBoxLayout *boxV_page_merried;
    TableEditor* weddingDress_edit;
    TableEditor* weddingDress_find_edit;
    TableEditor* accessory_edit;
    QFormLayout* layout_for_find_box;
    QTabWidget* tab_layout_inventory;
    QHBoxLayout* background_box;
    pageadditem* pag;
    QPushButton* button_find_merried;
    QLineEdit* stile_find;
    QPushButton* button_find;
};

