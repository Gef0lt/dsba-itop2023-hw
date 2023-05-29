#include "chooseorder.h"
#include "ui_chooseorder.h"

ChooseOrder::ChooseOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseOrder)
{
    ui->setupUi(this);

    connect(ui->ApplyOrder, &QPushButton::clicked, this, &ChooseOrder::accept);
}

ChooseOrder::~ChooseOrder()
{
    delete ui;
}

bool ChooseOrder::apply_order()
{
    if (ui->radio_False->isChecked())
        return false;
    return true;
}
