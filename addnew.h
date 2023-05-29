#ifndef ADDNEW_H
#define ADDNEW_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class AddNew;
}

class AddNew : public QDialog
{
    Q_OBJECT

public:
    explicit AddNew(QWidget *parent = nullptr);
    ~AddNew();

private:
    Ui::AddNew *ui;

public slots:
    QStringList getNewRow();
};

#endif // ADDNEW_H
