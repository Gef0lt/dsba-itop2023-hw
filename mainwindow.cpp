#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about_window.h"
#include "addnew.h"
#include "searchreq.h"
#include <QTableView>
#include <QString>
#include <QFile>
#include <QStandardItemModel>
#include <QDebug>
#include "choosefield.h"
#include "chooseorder.h"
#include "choosetype.h"
#include <QList>
#include <QStandardPaths>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QStringList> listOfAll;
    reset_table();
    connect(ui->pushButton_Help, SIGNAL(clicked()), this, SLOT(Help_clicked()));
    connect(ui->pushButton_AddNew, SIGNAL(clicked()), this, SLOT(AddNew_clicked()));
    connect(ui->pushButton_Sort, SIGNAL(clicked()), this, SLOT(Sort_clicked()));
    connect(ui->pushButton_Search, SIGNAL(clicked()), this, SLOT(Search_clicked()));
    connect(ui->pushButton_Reset, SIGNAL(clicked()), this, SLOT(reset_table()));
    connect(ui->Table->model(), &QAbstractItemModel::dataChanged, this, &MainWindow::onDataChanged);

    ui->Table->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->Table, &QTableView::customContextMenuRequested, this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deleteRow()
{
    QModelIndex index = ui->Table->currentIndex();
    if (index.isValid()) {
        ui->Table->model()->removeRow(index.row());
        listOfAll.remove(index.row());
    }
}

void MainWindow::showContextMenu(const QPoint& pos)
{
    QModelIndex index = ui->Table->indexAt(pos);
    if (index.isValid()) {
        QMenu contextMenu(this);

        QAction* deleteAction = new QAction("Delete", this);
        connect(deleteAction, &QAction::triggered, this, &MainWindow::deleteRow);
        contextMenu.addAction(deleteAction);
        contextMenu.exec(ui->Table->viewport()->mapToGlobal(pos));
    }
}

void MainWindow::Help_clicked()
{
    About_window about;
    about.setModal(true);
    about.exec();
}

void MainWindow::AddNew_clicked()
{
    AddNew adding;
    adding.setModal(true);
    adding.exec();
    QStringList NewRow = adding.getNewRow();
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->Table->model());
    int row = model->rowCount(), col = 0;
    int rowsInModel = listOfAll.length();
    QStandardItem *item = new QStandardItem(QString::number(rowsInModel));
    model->setItem(row, col, item);
    col = 1;
    for (QString cell : NewRow)
    {
        QStandardItem *item = new QStandardItem(cell);
        model->setItem(row, col, item);
        col++;
    }
    save_model_after_adding_row(NewRow);
}

void MainWindow::Sort_clicked()
{
    ChooseType chooseType;
    chooseType.setModal(true);
    chooseType.exec();
    QStringList TypesToFilter = chooseType.applyTypes_clicked();

    ChooseField chooseField;
    chooseField.setModal(true);
    chooseField.exec();
    QString fieldToSort = chooseField.apply_field_clicked();

    ChooseOrder chooseOrder;
    chooseOrder.setModal(true);
    chooseOrder.exec();
    bool order = chooseOrder.apply_order();


    QList<QStringList> allCells;
//    QString path = ":/files/starbucks.csv";
//    QFile file(path);
//    QStringList ListOfRows, items, values;

//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Display an error message if the file cannot be opened
//        qDebug() << "Failed to open the file: " << file.errorString();
//    }

//    QTextStream stream(&file);
    int i = 1;
    bool isTitle = true;
    for (QStringList rrow : listOfAll)
    {
//        QString line = stream.readLine();
//        values = line.split(',');
        if (isTitle)
        {
            isTitle = false;
            QStringList emptyList;
            allCells.push_back(emptyList);
            for (QString title : rrow)
            {
                allCells[0].push_back(title);
            }
        }
        if (TypesToFilter.contains(rrow[rrow.length() - 1]))
        {
            QStringList emptyList;
            allCells.push_back(emptyList);
            for (int j = 0; j < rrow.length(); j++)
            {
                QString val = rrow[j];
                allCells[i].push_back(val);
            }
            i++;
        }
//        ListOfRows.push_back(line);
    }

    int col = 0;
    for (QString name : allCells[0])
    {
        if (name == fieldToSort)
            break;
        col++;
    }

    QList<QStringList> sortedList;
    sortedList.push_back(allCells[0]);

    if (!order)
    {
        if (col == 2)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
                      return list1[2] < list2[2];
                  });
        }
        if (col == 3)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
                      return list1[3] < list2[3];
                  });
        }
        if (col == 4)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
                      return list1[4] < list2[4];
                  });
        }
        if (col == 5)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
                      return list1[5] < list2[5];
                  });
        }
        if (col == 6)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
                      return list1[6] < list2[6];
                  });
        }
    } else if (order)
    {
        if (col == 2)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
            return list1[2] > list2[2];
                  });
        }
        if (col == 3)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
            return list1[3] > list2[3];
                  });
        }
        if (col == 4)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
            return list1[4] > list2[4];
                  });
        }
        if (col == 5)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
            return list1[5] > list2[5];
                  });
        }
        if (col == 6)
        {
        std::sort(allCells.begin() + 1, allCells.end(),
                  [](const QStringList& list1, const QStringList& list2) {
            return list1[6] > list2[6];
                  });
        }
    }
    QStandardItemModel *model = new QStandardItemModel(this);
    int r = 0, c = 0;

    for(QStringList row: allCells)
    {
        for (QString cell: row)
        {
            QStandardItem *item = new QStandardItem(cell);
            model->setItem(r, c, item);
            c++;
        }
        r++;
        c = 0;
    }

    ui->Table->setModel(model);
}


void MainWindow::Search_clicked()
{
    QString req = ui->lineSearchReq->text();
    bool found = false;
    QStringList vals;
    for (QStringList line : listOfAll)
    {
        vals = line;
        for (QString val : line)
        {
            if (val.contains(req))
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
        }


//    file.close();

    if (found)
    {
        SearchReq sReq;
        sReq.setModal(true);
        sReq.set_values(vals);
        sReq.exec();
    }
    else
    {
        qDebug() << "Item not found";
    }
}

int MainWindow::reset_table()
{
    listOfAll.clear();
    QString path = ":/files/starbucks.csv";
    QFile file(path);
    QStringList ListOfRows;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Display an error message if the file cannot be opened
        qDebug() << "Failed to open the file: " << file.errorString();
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        ListOfRows.push_back(line);
    }

    file.close();

    QStandardItemModel *model = new QStandardItemModel(this);
    int row = 0, col = 0;

    for (QString line : ListOfRows)
    {
        QStringList values = line.split(',');
        QStringList empty;
        listOfAll.push_back(empty);
        for (QString val : values)
        {
                if (val[0] == '"')
                {
                    val = val.mid(1, val.length() - 2);
                }
                QStandardItem *item = new QStandardItem(val);
                model->setItem(row, col, item);
                listOfAll[row].push_back(val);
                col++;
        }
        col = 0;
        row++;
    }

    ui->Table->setModel(model);

    return row-1;
}

void MainWindow::on_actionSave_table_triggered()
{


    // Open a file dialog to choose the save path
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text Files (*.csv)");

    if (!filePath.isEmpty()) {
            qDebug() << "Save path: " << filePath;
    } else {
            qDebug() << "Save operation canceled";
    }

    QAbstractItemModel* model = ui->Table->model();
    QFile file(filePath);
    QTextStream stream(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QStringList headers;
    for (int column = 0; column < model->columnCount(); ++column) {
            headers << model->headerData(column, Qt::Horizontal).toString();
    }
    stream << headers.join(",") << '\n';

    for (int row = 0; row < model->rowCount(); ++row) {
            QStringList rowData;
            for (int column = 0; column < model->columnCount(); ++column) {
                QString value = model->data(model->index(row, column)).toString();
                rowData << value;
            }
            stream << rowData.join(",") << '\n';
    }

    file.close();

}

void MainWindow::save_model_after_adding_row(QStringList row)
{
    QStringList newlist;
    newlist.push_back(QString::number(listOfAll.length()));
    for (QString s : row)
    {
        newlist.push_back(s);
    }

    listOfAll.push_back(newlist);
    qDebug() << listOfAll;
}


void MainWindow::on_actionSave_table_without_filter_triggered()
{
    // Open a file dialog to choose the save path
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text Files (*.csv)");

    if (!filePath.isEmpty()) {
        qDebug() << "Save path: " << filePath;
    } else {
        qDebug() << "Save operation canceled";
    }

//    QAbstractItemModel* model = ui->Table->model();
    QFile file(filePath);
    QTextStream stream(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QStringList headers;
    for (int column = 0; column < listOfAll[0].length(); ++column)
    {
        headers << listOfAll[0];
    }
    stream << headers.join(",") << '\n';

    for (int row = 0; row < listOfAll.length(); ++row) {
        QStringList rowData;
        for (int column = 0; column < listOfAll[row].length(); ++column)
        {
                QString value = listOfAll[row][column];
                rowData << value;
        }
        stream << rowData.join(",") << '\n';
    }

    file.close();
}

void MainWindow::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles)
{
    Q_UNUSED(topLeft);
    Q_UNUSED(bottomRight);
    Q_UNUSED(roles);

    // Update the QString with the modified data
    // You can access the modified data using the model and the provided indexes
    // Perform the necessary logic to update the QString
    // For example, if you are using a QStandardItemModel:
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->Table->model());

    QModelIndex index = ui->Table->currentIndex(); // Assuming the first item in the model
    QString modifiedData = model->data(index).toString();
    listOfAll[index.row()][index.column()] = modifiedData;

}
