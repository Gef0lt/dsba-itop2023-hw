#include "drawlogo.h"

DrawLogo::DrawLogo(QWidget* parent) : QWidget(parent) {
    setFixedSize(200, 200);

    logoPixmap = QPixmap(":/files/Logo.png");
}

void DrawLogo::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(20, 50, logoPixmap);
}
