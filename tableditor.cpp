#include "tableditor.h"

TableEditor::TableEditor(const QString &tableName,int Type, QWidget *parent)
    : QWidget(parent)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    type=Type;

    if(type==0)
    {
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("sex"));
        model->setHeaderData(2, Qt::Horizontal, tr("style"));
        model->setHeaderData(3, Qt::Horizontal, tr("model"));
        model->setHeaderData(4, Qt::Horizontal, tr("color"));
        model->setHeaderData(5, Qt::Horizontal, tr("year"));
        model->setHeaderData(6, Qt::Horizontal, tr("quantity"));
        model->setHeaderData(7, Qt::Horizontal, tr("costBuy"));
        model->setHeaderData(8, Qt::Horizontal, tr("costSell"));
        model->setHeaderData(9, Qt::Horizontal, tr("note"));
        model->setHeaderData(10, Qt::Horizontal, tr("owner"));
    }
    else if(type==1)
    {
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("sex"));
        model->setHeaderData(2, Qt::Horizontal, tr("brand"));
        model->setHeaderData(3, Qt::Horizontal, tr("model"));
        model->setHeaderData(4, Qt::Horizontal, tr("type"));
        model->setHeaderData(5, Qt::Horizontal, tr("quantity"));
        model->setHeaderData(6, Qt::Horizontal, tr("costBuy"));
        model->setHeaderData(7, Qt::Horizontal, tr("costSell"));
        model->setHeaderData(8, Qt::Horizontal, tr("owner"));
    }

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();

    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    refreshButton = new QPushButton(tr("Refresh"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(refreshButton, QDialogButtonBox::RejectRole);

    connect(refreshButton, &QPushButton::clicked, this, &TableEditor::reloadData);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Cached Table"));
}

void TableEditor::submit()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}

void TableEditor::reloadData(){

    if(type==0)
    {
        model->setTable("weddingDress");
        model->select();
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("sex"));
        model->setHeaderData(2, Qt::Horizontal, tr("style"));
        model->setHeaderData(3, Qt::Horizontal, tr("model"));
        model->setHeaderData(4, Qt::Horizontal, tr("color"));
        model->setHeaderData(5, Qt::Horizontal, tr("year"));
        model->setHeaderData(6, Qt::Horizontal, tr("quantity"));
        model->setHeaderData(7, Qt::Horizontal, tr("costBuy"));
        model->setHeaderData(8, Qt::Horizontal, tr("costSell"));
        model->setHeaderData(9, Qt::Horizontal, tr("note"));
        model->setHeaderData(10, Qt::Horizontal, tr("owner"));
    }
    else if(type==1)
    {
        model->setTable("accessory");
        model->select();
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("sex"));
        model->setHeaderData(2, Qt::Horizontal, tr("brand"));
        model->setHeaderData(3, Qt::Horizontal, tr("model"));
        model->setHeaderData(4, Qt::Horizontal, tr("type"));
        model->setHeaderData(5, Qt::Horizontal, tr("quantity"));
        model->setHeaderData(6, Qt::Horizontal, tr("costBuy"));
        model->setHeaderData(7, Qt::Horizontal, tr("costSell"));
        model->setHeaderData(8, Qt::Horizontal, tr("owner"));
    }
}
