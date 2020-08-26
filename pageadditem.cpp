#include "pageadditem.h"

pageadditem::pageadditem(QWidget *parent)
{
    sex_line= new QLineEdit;
    style_line=new QLineEdit;
    model_line=new QLineEdit;
    size_line=new QLineEdit;
    color_line=new QLineEdit;
    year_line=new QLineEdit;
    quantity_line=new QLineEdit;
    costBuy_line=new QLineEdit;
    costSell_line=new QLineEdit;
    note_line=new QLineEdit;
    owner_line =  new QLineEdit;
    layout_page= new QFormLayout;
    acc_sex_line= new QLineEdit;
    acc_style_line= new QLineEdit;
    acc_model_line= new QLineEdit;
    acc_type_line= new QLineEdit;
    acc_quantity_line= new QLineEdit;
    acc_costBuy_line= new QLineEdit;
    acc_costSell_line= new QLineEdit;
    acc_owner_line= new QLineEdit;

    button_add=new QPushButton{"ADD!"};
    button_add_acc=new QPushButton{"ADD!"};
    layout_page->addRow(new QLabel{"Add weddingdress"});
    layout_page->addRow(new QLabel{"Sex"},sex_line);
    layout_page->addRow(new QLabel("Style : "),style_line);
    layout_page->addRow(new QLabel("Model : "),model_line);
    layout_page->addRow(new QLabel("Size : "),size_line);
    layout_page->addRow(new QLabel("Color: "),color_line);
    layout_page->addRow(new QLabel("Year : "),year_line);
    layout_page->addRow(new QLabel("Quantity : "),quantity_line);
    layout_page->addRow(new QLabel("CostBuy : "),costBuy_line);
    layout_page->addRow(new QLabel("CostSell : "),costSell_line);
    layout_page->addRow(new QLabel("Note : "),note_line);
    layout_page->addRow(new QLabel("Owner : "),owner_line); 
    layout_page->addWidget(button_add);

    layout_page->addRow(new QLabel{"Add Accessory"});
    layout_page->addRow(new QLabel{"Sex: "},acc_sex_line);
    layout_page->addRow(new QLabel{"brand: "},acc_style_line);
    layout_page->addRow(new QLabel{"model: "},acc_model_line);
    layout_page->addRow(new QLabel{"type: "},acc_type_line);
    layout_page->addRow(new QLabel{"quantity: "},acc_quantity_line);
    layout_page->addRow(new QLabel{"costBuy: "},acc_costBuy_line);
    layout_page->addRow(new QLabel{"costSell: "},acc_costSell_line);
    layout_page->addRow(new QLabel{"owner: "},acc_owner_line);
    layout_page->addRow(button_add_acc);

    parent->setLayout(layout_page);

    connect(button_add,&QPushButton::clicked,this,&pageadditem::AddItem);
    connect(button_add_acc,&QPushButton::clicked,this,&pageadditem::AddAccessory);

}

void pageadditem::AddItem()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO weddingDress ("
                "sex,"
                "style,"
                "model,"
                "size,"
                "color,"
                "year,"
                "quantity,"
                "costBuy,"
                "costSell,"
                "note,"
                "owner)"
                "VALUES (?,?,?,?,?,?,?,?,?,?,?);");//:ID
    QString sex=sex_line->text();
    QString style=style_line->text();
    QString model=model_line->text();
    QString size=size_line->text();
    QString color=color_line->text();
    QString year=year_line->text();
    QString quantity=quantity_line->text();
    QString costBuy=costBuy_line->text();
    QString costSell=costSell_line->text();
    QString note=note_line->text();
    QString owner=owner_line->text();

    qDebug()<<"model: "<<sex;

    qry.addBindValue(sex);
    qry.addBindValue(style);
    qry.addBindValue(model);
    qry.addBindValue(size);
    qry.addBindValue(color);
    qry.addBindValue(year);
    qry.addBindValue(quantity);
    qry.addBindValue(costBuy);
    qry.addBindValue(costSell);
    qry.addBindValue(note);
    qry.addBindValue(owner);

    if(!qry.exec())
    {
        qDebug()<<"error adding value to db";
    }

}

void pageadditem::AddAccessory()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO accessory ("
                "sex,"
                "brand,"
                "model,"
                "type,"
                "quantity,"
                "costBuy,"
                "costSell,"
                "owner)"

                "VALUES (?,?,?,?,?,?,?,?);");
    QString sex=acc_sex_line->text();
    QString brand=acc_style_line->text();
    QString model=acc_model_line->text();
    QString type=acc_type_line->text();
    QString quantity=acc_quantity_line->text();
    QString costBuy=acc_costBuy_line->text();
    QString costSell=acc_costSell_line->text();
    QString owner=acc_owner_line->text();

    qDebug()<<"model: "<<sex;

    qry.addBindValue(sex);
    qry.addBindValue(brand);
    qry.addBindValue(model);
    qry.addBindValue(type);
    qry.addBindValue(quantity);
    qry.addBindValue(costBuy);
    qry.addBindValue(costSell);
    qry.addBindValue(owner);

    if(!qry.exec())
    {
        qDebug()<<"error adding value to db"<<qry.lastError();
    }
}


