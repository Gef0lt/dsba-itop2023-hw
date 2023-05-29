#ifndef CHOOSEFIELD_H
#define CHOOSEFIELD_H

#include <QDialog>

namespace Ui {
class ChooseField;
}

class ChooseField : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseField(QWidget *parent = nullptr);
    ~ChooseField();

private:
    Ui::ChooseField *ui;

public slots:
    QString apply_field_clicked();
};

#endif // CHOOSEFIELD_H
