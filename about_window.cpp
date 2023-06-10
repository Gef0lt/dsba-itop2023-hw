#include "about_window.h"
#include "ui_about_window.h"
#include <QPixmap>

About_window::About_window(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::About_window)
{
    ui->setupUi(this);
    ui->textBrowser->setText("The application allows you to work with \"Starbucks Nutrients\" dataSet."
                             "\nYou can add, edit or delete a row. \nUsing sort menu you will choose menu "
                             "categories that you want to see after sorting, field to sort and the sorting order."
                             "\nAlso, you may search a row in the bottom of Main Page even by the part of Item name."
                             "\nYou can reset the table and save the data to a new one."
                             "\nTo delete row press \"RMC - remove\" ");
}

About_window::~About_window()
{
    delete ui;
}
