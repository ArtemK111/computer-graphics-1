#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include "paintingwidgetrgb.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void onChooseButtonClicked();
    void onRedValueChanged(int i);
    void onGreenValueChanged(int i);
    void onBlueValueChanged(int i);

private:
    PaintingWidgetRGB *pwRGB;
    QLabel *redLabel, *greenLabel, *blueLabel;
    QLabel *hueLabel, *satLabel, *valLabel;
    QLabel *cLabel, *mLabel, *yLabel, *kLabel;
    QSpinBox *redEdit, *greenEdit, *blueEdit;
    QSpinBox  *hueEdit, *satEdit, *valEdit;
    QSpinBox  *cEdit, *mEdit, *yEdit, *kEdit;
    QPushButton *chooseButton;
    QLineEdit *colorNameEdit;
    QComboBox *comboBox1, *comboBox2, *comboBox3;

    void changeHSV(int red, int green, int blue);
    void changeCMYK(int red, int green, int blue);

};
#endif // WIDGET_H
