#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about_window.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QStringList> listOfAll;

private:
    Ui::MainWindow *ui;
    About_window *about_window;

private slots:
    void Help_clicked();
    void Sort_clicked();
    void AddNew_clicked();
    void Search_clicked();
    int reset_table();
    void deleteRow();
    void showContextMenu(const QPoint& pos);
    void on_actionSave_table_triggered();
    void save_model_after_adding_row(QStringList row);
    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);
    void on_actionSave_table_without_filter_triggered();

public slots:
};
#endif // MAINWINDOW_H
