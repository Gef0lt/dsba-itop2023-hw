#include "choosefield.h"
#include "ui_choosefield.h"

ChooseField::ChooseField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseField)
{
    ui->setupUi(this);

    connect(ui->ApplyField, &QPushButton::clicked, this, &ChooseField::accept);

}

ChooseField::~ChooseField()
{
    delete ui;
}

QString ChooseField::apply_field_clicked()
{
    QString ret;
    if (ui->radioButton_Cal->isChecked())
        ret = "calories";
    else if (ui->radioButton_Carb->isChecked())
        ret = "carb";
    else if (ui->radioButton_Fat->isChecked())
        ret = "fat";
    else if (ui->radioButton_Fib->isChecked())
        ret = "fiber";
    else if (ui->radioButton_Pro->isChecked())
        ret = "protein";

    return ret;
}
