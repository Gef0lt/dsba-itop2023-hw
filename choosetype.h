#ifndef CHOOSETYPE_H
#define CHOOSETYPE_H

#include <QDialog>
#include <QStringList>


namespace Ui {
class ChooseType;
}

class ChooseType : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseType(QWidget *parent = nullptr);
    ~ChooseType();

private:
    Ui::ChooseType *ui;

public slots:
    QStringList applyTypes_clicked();
};

#endif // CHOOSETYPE_H
