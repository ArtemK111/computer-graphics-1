#include <QPainter>
#include "paintingwidgetrgb.h"

PaintingWidgetRGB::PaintingWidgetRGB(QWidget *parent)
    : QWidget{parent}
{
    red = green = blue = 0;
}
void PaintingWidgetRGB::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QColor color(red, green, blue);
    QBrush brush(color);
    painter.setBrush(brush);
    painter.drawRect(10, 10, 100, 100);


}
