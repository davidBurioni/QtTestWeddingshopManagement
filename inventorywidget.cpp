#include "inventorywidget.h"

InventoryWidget::InventoryWidget()
{
    stile_find= new QLineEdit;
    button_find= new QPushButton("FIND");

    //make a widget for add item
    widget_add_item= new QWidget;

    pag= new pageadditem(widget_add_item);
    widget_page_merried= new QWidget();

    boxH_page_merried= new QHBoxLayout();
    boxV_page_merried= new QVBoxLayout();


    weddingDress_edit= new TableEditor("weddingDress",0);
    weddingDress_find_edit= new TableEditor("weddingDress_find",1);

    boxH_page_merried->addWidget(weddingDress_edit);
    boxH_page_merried->addLayout(boxV_page_merried);
    widget_page_merried->setLayout(boxH_page_merried);

    accessory_edit= new TableEditor("accessory",1);


    layout_for_find_box= new QFormLayout();
    layout_for_find_box->addRow(new QLabel("Style : "),stile_find);
    layout_for_find_box->addRow(new QLabel("Model : "),new QLineEdit);
    layout_for_find_box->addRow(new QLabel("Sex : "),new QLineEdit);
    layout_for_find_box->addRow(button_find);

    boxV_page_merried->addLayout(layout_for_find_box);
    boxV_page_merried->addWidget(weddingDress_find_edit);
    auto *ceremony_page= new QLabel("sfdss");

    //TAB MENU LAYOUT PAGE INVENTORY
    tab_layout_inventory= new QTabWidget();
    tab_layout_inventory->addTab(widget_page_merried,"Merried");
    tab_layout_inventory->addTab(accessory_edit,"Accessory");
    tab_layout_inventory->addTab(ceremony_page,"Ceremony");
    tab_layout_inventory->addTab(widget_add_item,"Add Item");

    button_back= new QPushButton{"Back"};
    button_back->resize(50,50);

    background_box= new QHBoxLayout();
    background_box->addWidget(tab_layout_inventory);
    background_box->addWidget(button_back);

    widget= new QWidget();
    widget->setLayout(background_box);

    connect(button_find,&QPushButton::clicked,this,&InventoryWidget::FindMerriedTable);
}

//incomplete function
void InventoryWidget::FindMerriedTable()
{

    // QString string= stile_find->text();
    //
    //
    // QSqlRecord rec = q.record();
    //
    // qDebug() << "Number of columns: " << rec.count();
    //
    // int styleCol = rec.indexOf("style"); // index of the field "name"
    // int sexCol = rec.indexOf("sex"); // index of the field "name"
    //     int idCol = rec.indexOf("ID"); // index of the field "name"
    // QSqlQuery q("select * from weddingDress"
    //             "WHERE ID = "
    //             );
    //
    // while (q.next())
    // {
    //      qDebug() << q.value(styleCol).toString(); // output all names
    //      qDebug() << q.value(sexCol).toString(); // output all names
    // }
    //
    //
    //
    // if(!q.exec())
    // {
    //     qDebug()<< "error a exec query find";
    // }
}
