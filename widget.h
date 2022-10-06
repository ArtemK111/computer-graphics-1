#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include "paintingwidgetrgb.h"
#include "stdlib.h"

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
    void onColorNameChanged(const QString&);

private:
    PaintingWidgetRGB *pwRGB;
    //QLabel *redLabel, *greenLabel, *blueLabel,
    //QLabel *hueLabel, *satLabel, *valLabel;
    //QLabel *cLabel, *mLabel, *yLabel, *kLabel;
    QLabel *helpColorLabel;
    QLabel *rgbLabel, *hsvLabel, *cmykLabel, *labLabel, *xyzLabel, *hlsLabel;
    QSpinBox *redEdit, *greenEdit, *blueEdit;
    QSpinBox  *hueEdit, *satEdit, *valEdit;
    QSpinBox  *cEdit, *mEdit, *yEdit, *kEdit;
    QSpinBox  *lEdit, *aEdit, *bEdit;
    QSpinBox  *xEdit, *y1Edit, *zEdit;
    QSpinBox  *hEdit, *l1Edit, *sEdit;
    QPushButton *chooseButton;
    QLineEdit *colorNameEdit;
    QComboBox *comboBox1, *comboBox2, *comboBox3;

    void changeRGB(double red, double green, double blue);
    void changeHSV(double red, double green, double blue);
    void changeCMYK(double red, double green, double blue);
    void changeLAB(double red, double green, double blue);
    void changeXYZ(double red, double green, double blue);
    void changeHSL(double red, double green, double blue);

    std::string decToHex(int n);


};
#endif // WIDGET_H
