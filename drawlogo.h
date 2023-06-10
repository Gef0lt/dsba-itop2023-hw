#ifndef DRAWLOGO_H
#define DRAWLOGO_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

class DrawLogo : public QWidget {
    Q_OBJECT
public:
    explicit DrawLogo(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPixmap logoPixmap;
};

#endif // DRAWLOGO_H
