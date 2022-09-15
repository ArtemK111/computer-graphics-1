#ifndef PAINTINGWIDGETRGB_H
#define PAINTINGWIDGETRGB_H

#include <QWidget>

class PaintingWidgetRGB : public QWidget
{
    Q_OBJECT
public:
    explicit PaintingWidgetRGB(QWidget *parent = nullptr);

    void setRed(int red_)
    {
        red = red_;
    }
    void setGreen(int green_)
    {
        green = green_;
    }
    void setBlue(int blue_)
    {
        blue = blue_;
    }

signals:

protected:
    void paintEvent(QPaintEvent *event);
private:
    int red, green, blue;
};

#endif // PAINTINGWIDGETRGB_H
