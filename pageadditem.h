#pragma once
#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QTableView>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QSqlQuery>
#include <QtDebug>

class pageadditem : public QWidget
{
    Q_OBJECT

public:
    explicit pageadditem(QWidget *parent);

    QFormLayout *layout_page;
    QLineEdit *sex_line;;
    QLineEdit *style_line;
    QLineEdit *model_line;
    QLineEdit *size_line;
    QLineEdit *color_line;
    QLineEdit *year_line;
    QLineEdit *quantity_line;
    QLineEdit *costBuy_line;
    QLineEdit *costSell_line;
    QLineEdit *note_line;
    QLineEdit *owner_line;
    QLineEdit *acc_sex_line;
    QLineEdit *acc_style_line;
    QLineEdit *acc_model_line;
    QLineEdit *acc_type_line;
    QLineEdit *acc_quantity_line;
    QLineEdit *acc_costBuy_line;
    QLineEdit *acc_costSell_line;
    QLineEdit *acc_owner_line;
    QPushButton *button_add;
    QPushButton *button_add_acc;

public slots:
    void AddItem();
    void AddAccessory();

private:


};
