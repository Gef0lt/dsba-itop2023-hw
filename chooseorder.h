#ifndef CHOOSEORDER_H
#define CHOOSEORDER_H

#include <QDialog>

namespace Ui {
class ChooseOrder;
}

class ChooseOrder : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseOrder(QWidget *parent = nullptr);
    ~ChooseOrder();

private:
    Ui::ChooseOrder *ui;

public slots:
    bool apply_order();
};

#endif // CHOOSEORDER_H
