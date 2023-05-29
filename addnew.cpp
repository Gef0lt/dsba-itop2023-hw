#include "addnew.h"
#include "ui_addnew.h"
#include <QDialogButtonBox>
//#include "mainwindow.h"
#include <QDebug>
#include <QString>

AddNew::AddNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNew)
{
    ui->setupUi(this);

    connect(ui->buttonBox_AddNew, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

AddNew::~AddNew()
{
    delete ui;
}

QStringList AddNew::getNewRow()
{

    QStringList NewRow;
    NewRow.push_back(ui->lineItem->text());
    NewRow.push_back(ui->lineCal->text());
    NewRow.push_back(ui->lineFat->text());
    NewRow.push_back(ui->lineCarb->text());
    NewRow.push_back(ui->lineFib->text());
    NewRow.push_back(ui->linePro->text());
    NewRow.push_back(ui->lineType->text());

    return NewRow;
}



