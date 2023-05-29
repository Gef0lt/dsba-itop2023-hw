#include "searchreq.h"
#include "ui_searchreq.h"

SearchReq::SearchReq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchReq)
{
    ui->setupUi(this);
}

SearchReq::~SearchReq()
{
    delete ui;
}

void SearchReq::set_values(QStringList listForReq)
{
    ui->label_cell->setText(listForReq[0]);
    ui->label_name->setText(listForReq[1]);
    ui->label_cal->setText(listForReq[2]);
    ui->label_fat->setText(listForReq[3]);
    ui->label_carb->setText(listForReq[4]);
    ui->label_fib->setText(listForReq[5]);
    ui->label_pro->setText(listForReq[6]);
    ui->label_type->setText(listForReq[7]);
}
