#include "choosetype.h"
#include "ui_choosetype.h"
#include <QList>
#include <QStringList>
ChooseType::ChooseType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseType)
{
    ui->setupUi(this);

    connect(ui->pushButton_chooseType, &QPushButton::clicked, this, &ChooseType::accept);
}

ChooseType::~ChooseType()
{
    delete ui;
}

QStringList ChooseType::applyTypes_clicked()
{
    QStringList chosenTypes;
    if (ui->checkBakery->isChecked())
        chosenTypes.append("bakery");
    if (ui->checkBistroBox->isChecked())
        chosenTypes.append("bistro box");
    if (ui->checkBreakfast->isChecked())
        chosenTypes.append("hot breakfast");
    if (ui->checkPetite->isChecked())
        chosenTypes.append("petite");
    if (ui->checkSalad->isChecked())
        chosenTypes.append("salad");
    if (ui->checkSandw->isChecked())
        chosenTypes.append("sandwich");
    if (ui->checkPerfait->isChecked())
        chosenTypes.append("parfait");

    return chosenTypes;
}
