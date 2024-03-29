#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QDialog>
#include "drawlogo.h"


namespace Ui {
class About_window;
}

class About_window : public QDialog
{
    Q_OBJECT

public:
    explicit About_window(QDialog *parent = nullptr);
    ~About_window();

private:
    Ui::About_window *ui;
    DrawLogo *logo;
};

#endif // ABOUT_WINDOW_H
