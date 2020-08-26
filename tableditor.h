#pragma once
#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QTableView>
#include <QHBoxLayout>
#include <iostream>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <qDebug>

class TableEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TableEditor(const QString &tableName,int Yype, QWidget *parent = nullptr);

private slots:
    void submit();
    void reloadData();

private:
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *refreshButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    int type;
};
