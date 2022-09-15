#include <QVBoxLayout>
#include <QColorDialog>
#include <QGridLayout>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pwRGB = new PaintingWidgetRGB(this);
    pwRGB -> setFixedSize(200, 200);

    chooseButton = new QPushButton("Выбор цвета");

    colorNameEdit = new QLineEdit();

    comboBox1 = new QComboBox(this);
    comboBox1 -> addItem("RGB");
    comboBox1 -> addItem("HSV");
    comboBox1 -> addItem("CMYK");
    comboBox1 -> addItem("LAB");
    comboBox1 -> addItem("XYZ");
    comboBox1 -> addItem("HLS");

    comboBox2 = new QComboBox(this);
    comboBox2 -> addItem("HSV");
    comboBox2 -> addItem("RGB");
    comboBox2 -> addItem("CMYK");
    comboBox2 -> addItem("LAB");
    comboBox2 -> addItem("XYZ");
    comboBox2 -> addItem("HLS");

    comboBox3 = new QComboBox(this);
    comboBox3 -> addItem("CMYK");
    comboBox3 -> addItem("RGB");
    comboBox3 -> addItem("HSV");
    comboBox3 -> addItem("LAB");
    comboBox3 -> addItem("XYZ");
    comboBox3 -> addItem("HLS");

    redEdit = new QSpinBox();
    //redEdit -> setMaximumSize(45, 22);
    redEdit->setRange(0, 255);
    greenEdit = new QSpinBox();
    greenEdit->setRange(0, 255);
    blueEdit = new QSpinBox();
    blueEdit->setRange(0, 255);
    redLabel = new QLabel("R");
    greenLabel = new QLabel("G");
    blueLabel = new QLabel("B");

    hueLabel = new QLabel("H");
    hueEdit = new QSpinBox();
    hueEdit -> setRange(0, 100);
    satLabel = new QLabel("S");
    satEdit = new QSpinBox();
    satEdit -> setRange(0, 100);
    valLabel = new QLabel("V");
    valEdit = new QSpinBox();
    valEdit -> setRange(0, 100);

    cLabel = new QLabel("C");
    cEdit = new QSpinBox();
    mLabel = new QLabel("M");
    mEdit = new QSpinBox();
    yLabel = new QLabel("Y");
    yEdit = new QSpinBox();
    kLabel = new QLabel("K");
    kEdit = new QSpinBox();


    QHBoxLayout *layout1 = new QHBoxLayout();

    layout1 -> addWidget(pwRGB);
    layout1 -> addSpacing(-50);
    layout1 -> addWidget(colorNameEdit);

    //QGridLayout *gridLayout = new QGridLayout();
    //gridLayout ->columnMinimumWidth(45);
    //gridLayout ->setColumnStretch(1, 10);
    //gridLayout -> setRowStretch(0, 10);

    /*gridLayout -> addWidget(redLabel, 0, 0);
    gridLayout -> addWidget(redEdit, 0, 1);
    gridLayout -> addWidget(greenLabel, 1, 0);
    gridLayout -> addWidget(greenEdit, 1, 1);
    gridLayout -> addWidget(blueLabel, 2, 0);
    gridLayout -> addWidget(blueEdit, 2, 1);

    gridLayout -> addWidget(hueLabel, 0, 2);
    gridLayout -> addWidget(hueEdit, 0, 3);
    gridLayout -> addWidget(satLabel, 1, 2);
    gridLayout -> addWidget(satEdit, 1, 3);
    gridLayout -> addWidget(valLabel, 2, 2);
    gridLayout -> addWidget(valEdit, 2, 3);

    gridLayout -> addWidget(cLabel, 0, 4);
    gridLayout -> addWidget(cEdit, 0, 5);
    gridLayout -> addWidget(mLabel, 1, 4);
    gridLayout -> addWidget(mEdit, 1, 5);
    gridLayout -> addWidget(yLabel, 2, 4);
    gridLayout -> addWidget(yEdit, 2, 5);
    gridLayout -> addWidget(kLabel, 3, 4);
    gridLayout -> addWidget(kEdit, 3, 5);*/

    QGridLayout *gridLayout1 = new QGridLayout();
    //gridLayout1 -> setHorizontalSpacing(-50);
    //gridLayout1 -> setRowStretch(0, 200);
    gridLayout1 -> rowStretch(-50);
    gridLayout1 -> addWidget(comboBox1, 0, 1);
    //gridLayout1 -> addWidget(redLabel, 1, 0);
    gridLayout1 -> addWidget(redEdit, 1, 1);
    //gridLayout1 -> addWidget(greenLabel, 2, 0);
    gridLayout1 -> addWidget(greenEdit, 2, 1);
    //gridLayout1 -> addWidget(blueLabel, 3, 0);
    gridLayout1 -> addWidget(blueEdit, 3, 1);

    QGridLayout *gridLayout2 = new QGridLayout();
    //gridLayout2 -> setHorizontalSpacing(50);
    gridLayout2 -> addWidget(comboBox2, 0, 1);
    //gridLayout2 -> addWidget(hueLabel, 1, 0);
    gridLayout2 -> addWidget(hueEdit, 1, 1);
    //gridLayout2 -> addWidget(satLabel, 2, 0);
    gridLayout2 -> addWidget(satEdit, 2, 1);
    //gridLayout2 -> addWidget(valLabel, 3, 0);
    gridLayout2 -> addWidget(valEdit, 3, 1);

    QGridLayout *gridLayout3 = new QGridLayout();
    gridLayout3 -> addWidget(comboBox3, 0, 1);
    //gridLayout3 -> addWidget(cLabel, 1, 0);
    gridLayout3 -> addWidget(cEdit, 1, 1);
    //gridLayout3 -> addWidget(mLabel, 2, 0);
    gridLayout3 -> addWidget(mEdit, 2, 1);
    //gridLayout3 -> addWidget(yLabel, 3, 0);
    gridLayout3 -> addWidget(yEdit, 3, 1);
    //gridLayout3 -> addWidget(kLabel, 4, 0);
    gridLayout3 -> addWidget(kEdit, 4, 1);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout -> addLayout(gridLayout1);
    hLayout -> addLayout(gridLayout2);
    hLayout -> addLayout(gridLayout3);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout -> addLayout(layout1);
    mainLayout -> addSpacing(-75);
    mainLayout -> addLayout(hLayout);
    mainLayout -> addWidget(chooseButton);

    this->setLayout(mainLayout);

    connect(chooseButton, SIGNAL(clicked()), SLOT(onChooseButtonClicked()));
    connect(redEdit, SIGNAL(valueChanged(int)), SLOT(onRedValueChanged(int)));
    connect(greenEdit, SIGNAL(valueChanged(int)), SLOT(onGreenValueChanged(int)));
    connect(blueEdit, SIGNAL(valueChanged(int)), SLOT(onBlueValueChanged(int)));
}

Widget::~Widget()
{
}

void Widget::onChooseButtonClicked()
{
    QColor color = QColorDialog::getColor();
    int r, g, b;
    color.setRgb(r, g, b);

    /*color.setRed(r);
    color.setGreen(g);
    color.setBlue(b);*/

    pwRGB ->setRed(r);
    pwRGB ->setGreen(g);
    pwRGB ->setBlue(b);
    pwRGB ->update();


}

void Widget::onRedValueChanged(int i)
{
    colorNameEdit ->setText(QString::number(i));
    pwRGB ->setRed(i);
    pwRGB->update();

    changeHSV(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeCMYK(redEdit->value(), greenEdit->value(), blueEdit->value());
}

void Widget::onGreenValueChanged(int i)
{
    colorNameEdit ->setText(QString::number(i));
    pwRGB ->setGreen(i);
    pwRGB-> update();

    changeHSV(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeCMYK(redEdit->value(), greenEdit->value(), blueEdit->value());
}

void Widget::onBlueValueChanged(int i)
{
    colorNameEdit ->setText(QString::number(i));
    pwRGB ->setBlue(i);
    pwRGB-> update();

    changeHSV(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeCMYK(redEdit->value(), greenEdit->value(), blueEdit->value());
}

void Widget::changeHSV(int red, int green, int blue)
{
    int h = red;
    int s = green;
    int v = blue;
    hueEdit ->setValue(h);
    satEdit ->setValue(s);
    valEdit ->setValue(v);

}

void Widget::changeCMYK(int red, int green, int blue)
{
    int c = red;
    int m = green;
    int y = green;
    int k = blue;

    /*int redK = 1 - red / 255;
    int greenK = 1 - green / 255;
    int blueK = 1 - blue / 255;

    int k = redK;

    if (greenK < k)
    {
         k = greenK;
         if (blueK < k)
         {
             k = blueK;
         }
    }
    if (blueK < k)
    {
        k = blueK;0
    }

    int c =(1 - red / 255 - k) / (1 - k);
    int m = (1 - green / 255 - k) / (1 - k);
    int y = (1 - blue / 255 - k) / (1 - k);*/

    cEdit -> setValue(c);
    mEdit -> setValue(m);
    yEdit -> setValue(y);
    kEdit -> setValue(k);

}

