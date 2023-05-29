#ifndef SEARCHREQ_H
#define SEARCHREQ_H

#include <QDialog>

namespace Ui {
class SearchReq;
}

class SearchReq : public QDialog
{
    Q_OBJECT

public:
    explicit SearchReq(QWidget *parent = nullptr);
    ~SearchReq();

private:
    Ui::SearchReq *ui;
public slots:
    void set_values(QStringList listForReq);
};

#endif // SEARCHREQ_H
