#include <QVBoxLayout>
#include <QColorDialog>
#include <QGridLayout>
#include "widget.h"
#include "stdlib.h"
#include <iostream>
#include <QMessageBox>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pwRGB = new PaintingWidgetRGB(this);
    pwRGB -> setFixedSize(200, 200);

    chooseButton = new QPushButton("Выбор цвета");

    colorNameEdit = new QLineEdit("#000000");
    helpColorLabel = new QLabel();

    rgbLabel = new QLabel("RGB");
    hsvLabel = new QLabel("HSV");
    cmykLabel = new QLabel("CMYK");
    labLabel = new QLabel("LAB");
    xyzLabel = new QLabel("XYZ");
    hlsLabel = new QLabel("HLS");

    //QMessageBox messageBox(this);
    //messageBox.warning()


    /*comboBox1 = new QComboBox(this);
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
    comboBox3 -> addItem("HLS");*/

    redEdit = new QSpinBox();
    redEdit->setRange(0, 255);
    greenEdit = new QSpinBox();
    greenEdit->setRange(0, 255);
    blueEdit = new QSpinBox();
    blueEdit->setRange(0, 255);

    hueEdit = new QSpinBox();
    hueEdit -> setRange(0, 100);
    //satLabel = new QLabel("S");
    satEdit = new QSpinBox();
    satEdit -> setRange(0, 100);
    //valLabel = new QLabel("V");
    valEdit = new QSpinBox();
    valEdit -> setRange(0, 100);

    //cLabel = new QLabel("C");
    cEdit = new QSpinBox();
    cEdit -> setRange(0, 100);
    //mLabel = new QLabel("M");
    mEdit = new QSpinBox();
    mEdit -> setRange(0, 100);
    //yLabel = new QLabel("Y");
    yEdit = new QSpinBox();
    //kLabel = new QLabel("K");
    kEdit = new QSpinBox();

    lEdit = new QSpinBox();
    lEdit -> setRange(0, 100);
    aEdit = new QSpinBox();
    aEdit -> setRange(-128, 127);
    bEdit = new QSpinBox();
    bEdit -> setRange(-128, 127);

    xEdit = new QSpinBox();
    xEdit -> setRange(0, 95);
    y1Edit = new QSpinBox();
    y1Edit -> setRange(0, 100);
    zEdit = new QSpinBox();
    zEdit -> setRange(0, 108);

    hEdit = new QSpinBox();
    hEdit -> setRange(0, 360);
    l1Edit = new QSpinBox();
    l1Edit -> setRange(0, 120);
    sEdit = new QSpinBox();
    sEdit -> setRange(0, 240);


    QHBoxLayout *layout1 = new QHBoxLayout();

    layout1 -> addWidget(pwRGB);
    layout1 -> addSpacing(-50);
    layout1 -> addWidget(helpColorLabel);
    layout1 -> addWidget(colorNameEdit);

    /*QVBoxLayout *layout1 = new QVBoxLayout();
    //layout1 -> addSpacing(100);
    layout1 -> addWidget(helpColorLabel);
    layout1 -> addSpacing(-150);
    layout1 -> addWidget(colorNameEdit);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2 -> addWidget(pwRGB);
    layout2 -> addSpacing(-50);
    layout2 -> addLayout(layout1);*/

    QVBoxLayout *layoutRGB = new QVBoxLayout();
    layoutRGB -> addWidget(rgbLabel);
    layoutRGB ->addSpacing(-50);
    layoutRGB -> addWidget(redEdit);
    layoutRGB -> addWidget(greenEdit);
    layoutRGB -> addWidget(blueEdit);

    QVBoxLayout *layoutHSV = new QVBoxLayout();
    layoutHSV -> addWidget(hsvLabel);
    layoutHSV ->addSpacing(-50);
    layoutHSV -> addWidget(hueEdit);
    layoutHSV -> addWidget(satEdit);
    layoutHSV -> addWidget(valEdit);

    QVBoxLayout *layoutLAB = new QVBoxLayout();
    layoutLAB -> addWidget(labLabel);
    layoutLAB ->addSpacing(-50);
    layoutLAB -> addWidget(lEdit);
    layoutLAB -> addWidget(aEdit);
    layoutLAB -> addWidget(bEdit);

    QVBoxLayout *layoutXYZ = new QVBoxLayout();
    layoutXYZ -> addWidget(xyzLabel);
    layoutXYZ ->addSpacing(-50);
    layoutXYZ -> addWidget(xEdit);
    layoutXYZ -> addWidget(y1Edit);
    layoutXYZ -> addWidget(zEdit);

    QVBoxLayout *layoutHSL = new QVBoxLayout();
    layoutHSL -> addWidget(hlsLabel);
    layoutHSL ->addSpacing(-50);
    layoutHSL -> addWidget(hEdit);
    layoutHSL -> addWidget(sEdit);
    layoutHSL -> addWidget(l1Edit);

    QVBoxLayout *layoutCMYK = new QVBoxLayout();
    layoutCMYK -> addWidget(cmykLabel);
    layoutCMYK ->addSpacing(-25);
    layoutCMYK -> addWidget(cEdit);
    layoutCMYK -> addWidget(mEdit);
    layoutCMYK -> addWidget(yEdit);
    layoutCMYK -> addWidget(kEdit);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout -> addLayout(layoutRGB);
    hLayout ->addSpacing(15);
    hLayout -> addLayout(layoutHSV);
    hLayout ->addSpacing(15);
    hLayout -> addLayout(layoutLAB);
    hLayout ->addSpacing(15);
    hLayout -> addLayout(layoutXYZ);
    hLayout ->addSpacing(15);
    hLayout -> addLayout(layoutHSL);
    hLayout ->addSpacing(15);
    hLayout -> addLayout(layoutCMYK);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout -> addLayout(layout1);
    //mainLayout -> addSpacing(-75);
    //mainLayout -> addSpacing(-50);
    mainLayout -> addLayout(hLayout);
    //mainLayout ->addSpacing(20);
    mainLayout -> addWidget(chooseButton);

    this->setLayout(mainLayout);

    connect(chooseButton, SIGNAL(clicked()), SLOT(onChooseButtonClicked()));
    connect(redEdit, SIGNAL(valueChanged(int)), SLOT(onRedValueChanged(int)));
    connect(greenEdit, SIGNAL(valueChanged(int)), SLOT(onGreenValueChanged(int)));
    connect(blueEdit, SIGNAL(valueChanged(int)), SLOT(onBlueValueChanged(int)));
    connect(colorNameEdit, SIGNAL(textChanged(const QString&)), SLOT(onColorNameChanged(const QString&)));
}

Widget::~Widget()
{
}

void Widget::onColorNameChanged(const QString& text)
{
    if (text.size() == 0){
        //helpColorLabel->setText("Can not be empty");
        QMessageBox::warning(this, "", "Can not be empty");
    }
    else if (text.size() > 7){
        //helpColorLabel->setText("size must be 7");
        QMessageBox::warning(this, "", "size must be 7");
    }
    else if (text.at(0) != '#'){
        //helpColorLabel->setText("String must start with #");
        QMessageBox::warning(this, "", "String must start with #");

    }
    else if (text.size() > 1){
        QChar qc = text.at(text.size() - 1);
        char c = qc.toLatin1();
        //std::cout << "c = " << c << std::endl;
        if (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f')) || ((c >= 'A') && (c <= 'F')))
        {
            if(text.size() == 7){
                 //helpColorLabel->setText("Ok");
                 helpColorLabel->clear();
                 std::string str = text.toStdString();
                 int r, g, b;
                 std::sscanf(str.c_str(), "#%02x%02x%02x", &r, &g, &b);
                 pwRGB ->setRed(r);
                 pwRGB ->setGreen(g);
                 pwRGB ->setBlue(b);
                 pwRGB->update();

                 changeRGB(r, g, b);
                 changeHSV(r, g, b);
                 changeCMYK(r, g, b);
                 changeLAB(r, g, b);
                 changeXYZ(r, g, b);
                 changeHSL(r, g, b);

            }
            else{
                helpColorLabel->setText("Not enough digits");
                //QMessageBox::warning(this, "", "Not enough digits");
            }
        }
        else
        {
            //helpColorLabel->setText("Must be hex digit");
            //helpColorLabel->clear();
            QMessageBox::warning(this, "", "Must be hex digit");
        }
    }

}

std::string Widget::decToHex(int n)
{
    char hexaDeciNum[2];
        int i = 0;
        while (n != 0)
        {
            int temp = 0;
            temp = n % 16;
            if (temp < 10)
            {
                hexaDeciNum[i] = temp + 48;
                i++;
            }
            else
            {
                hexaDeciNum[i] = temp + 55;
                i++;
            }
            n = n / 16;
        }
        std::string hexCode = "";
        if (i == 2)
        {
            hexCode.push_back(hexaDeciNum[1]);
            hexCode.push_back(hexaDeciNum[0]);
        }
        else if (i == 1)
        {
            hexCode = "0";
            hexCode.push_back(hexaDeciNum[0]);
        }
        else if (i == 0)
        {
            hexCode = "00";
        }
        return hexCode;
}

std::string hexCode;
/*int n = hexCode.length();
    char hexCodeChar[n + 1];

    std::strcpy(hexCodeChar, hexCode.c_str());
char *str = hexCodeChar;
int r, g, b;
std::sscanf(str, "%02x%02x%02x", &r, &g, &b);*/

void Widget::onChooseButtonClicked()
{
    QColor color = QColorDialog::getColor().toRgb();
    int r, g, b;
    r = color .red();
    g = color.green();
    b = color. blue();

    color.setRed(r);
    color.setGreen(g);
    color.setBlue(b);

    pwRGB ->setRed(r);
    pwRGB ->setGreen(g);
    pwRGB ->setBlue(b);
    pwRGB ->update();

    if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)) {

      std::string hexCode = "#";
      hexCode += decToHex(r);
      hexCode += decToHex(g);
      hexCode += decToHex(b);

      QString QHexCode = QString::fromStdString(hexCode);
      colorNameEdit -> setText(QHexCode);
    }

    redEdit -> setValue(r);
    greenEdit -> setValue(g);
    blueEdit -> setValue(b);

}
void Widget::onRedValueChanged(int i)
{
    //colorNameEdit ->setText(QString::number(i));
    pwRGB ->setRed(i);
    pwRGB->update();

    if (i >= 0 && i <= 255) {
        QString hexCode = colorNameEdit ->text();
        QString hexCodeAdd = QString::fromStdString(decToHex(i));
        hexCode.replace(1, 2, hexCodeAdd);

        //QString QHexCode = QString::fromStdString(hexCode);
        colorNameEdit -> setText(hexCode);
    }

    changeRGB(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeHSV(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeCMYK(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeLAB(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeXYZ(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeHSL(redEdit->value(), greenEdit->value(), blueEdit->value());
}

void Widget::onGreenValueChanged(int i)
{
    //colorNameEdit ->setText(QString::number(i));
    pwRGB ->setGreen(i);
    pwRGB-> update();

    if (i >= 0 && i <= 255) {
        //std::string hexCodeAdd = decToHex(i);
        //hexCode.replace(3, 2, hexCodeAdd);
        //QString QHexCode = QString::fromStdString(hexCode);

        QString hexCode = colorNameEdit ->text();
        QString hexCodeAdd = QString::fromStdString(decToHex(i));
        hexCode.replace(3, 2, hexCodeAdd);

        colorNameEdit -> setText(hexCode);
    }

    changeRGB(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeHSV(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeCMYK(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeXYZ(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeHSL(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeLAB(redEdit->value(), greenEdit->value(), blueEdit->value());
}

void Widget::onBlueValueChanged(int i)
{

    pwRGB ->setBlue(i);
    pwRGB-> update();

    if (i >= 0 && i <= 255) {
        //std::string hexCodeAdd = decToHex(i);
        //hexCode.replace(5, 2, hexCodeAdd);
        //QString QHexCode = QString::fromStdString(hexCode);

        QString hexCode = colorNameEdit ->text();
        QString hexCodeAdd = QString::fromStdString(decToHex(i));
        hexCode.replace(5, 2, hexCodeAdd);

        colorNameEdit -> setText(hexCode);
    }

    changeRGB(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeHSV(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeCMYK(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeLAB(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeXYZ(redEdit->value(), greenEdit->value(), blueEdit->value());
    changeHSL(redEdit->value(), greenEdit->value(), blueEdit->value());
}

void Widget::changeRGB(double red, double green, double blue)
{
    redEdit->setValue(red);
    greenEdit->setValue(green);
    blueEdit->setValue(blue);
}

void Widget::changeHSV(double red, double green, double blue)
{
        red = red / 255.0;
        green = green / 255.0;
        blue = blue / 255.0;

        double cmax = std::max(red, std::max(green, blue));
        double cmin = std::min(red, std::min(green, blue));
        double diff = cmax - cmin;
        int h = -1;
        int s = -1;

        if (cmax == cmin)
            h = 0;
        else if (cmax == red)
            h = fmod(60 * ((green - blue) / diff) + 360, 360);
        else if (cmax == green)
            h = fmod(60 * ((blue - red) / diff) + 120, 360);
        else if (cmax == blue)
            h = fmod(60 * ((red - green) / diff) + 240, 360);
        if (cmax == 0)
            s = 0;
        else
            s = (diff / cmax) * 100;

        int v = cmax * 100;

    hueEdit ->setValue(h);
    satEdit ->setValue(s);
    valEdit ->setValue(v);
}

void Widget::changeCMYK(double red, double green, double blue)
{
    int c, m, y, k;
    red = red / 255.0;
    green = green / 255.0;
    blue = blue / 255.0;

    if (red == 0 && green == 0 && blue == 0)
    {
       c = 0;
       m = 0;
       y = 0;
       k = 1;
    }
    else
    {
    double w = std::max(red, std::max(green, blue));
    c = (w - red)/ w * 100;
    m = (w - green) /w * 100;
    y = (w - blue) / w * 100;
    k = (1 - w) * 100;
    }

    cEdit -> setValue(c);
    mEdit -> setValue(m);
    yEdit -> setValue(y);
    kEdit -> setValue(k);
}

void Widget::changeLAB(double red, double green, double blue)
{
    changeXYZ( red, green, blue);
    int x = xEdit -> value();

}

void Widget::changeXYZ(double red, double green, double blue)
{
    red = red / 255.0;
    green = green / 255.0;
    blue = blue / 255.0;

    if (red > 0.04045)
    {
        red = pow(((red + 0.055) / 1.065), 2.4);
    }
    else
    {
        red = red / 12.92;
    }
    if (green > 0.04045)
    {
        green = pow(((green + 0.055) / 1.065), 2.4);
    }
    else
    {
        green = green / 12.92;
    }
    if (blue > 0.04045)
    {
        red = pow(((blue + 0.055) / 1.065), 2.4);
    }
    else
    {
        blue = blue / 12.92;
    }

    red *= 100;
    green *= 100;
    blue *= 100;

    double x = red * 0.4124 + green * 0.3576 + blue * 0.1805;
    double y = red * 0.2126 + green * 0.7152 + blue * 0.0722;
    double z = red * 0.0193 + green * 0.1192 + blue * 0.9505;

    xEdit -> setValue(x);
    yEdit -> setValue(y);
    zEdit -> setValue(z);
}

void Widget::changeHSL(double red, double green, double blue)
{
    red = red / 255.0;
    green = green / 255.0;
    blue = blue / 255.0;

    double cmax = std::max(red, std::max(green, blue));
    double cmin = std::min(red, std::min(green, blue));
    double delta = cmax - cmin;

    double h, s, l;

    l = (cmax + cmin) / 2.0;

    if (delta == 0.0)
    {
        h = 0.0;
        s = 0.0;
    }
    else
    {
        if (l < 0.5)
        {
            s = delta  / (cmax + cmin);
        }
        else
        {
            s = delta / (2.0 - cmax - cmin);
        }

        double deltaR = (((cmax - red) / 6.0) + (delta / 2.0)) / delta;
        double deltaG = (((cmax - green) / 6.0) + (delta / 2.0)) / delta;
        double deltaB = (((cmax - blue) / 6.0) + (delta / 2.0)) / delta;

        if (red == cmax)
        {
            h = deltaB - deltaG;
        }
        else if (green == cmax)
        {
            h = 1.0 / 3.0 + deltaR - deltaB;
        }
        else if (blue == cmax)
        {
            h = 2.0 / 3.0 + deltaG - deltaR;
        }

        if (h < 0.0)
        {
            h += 1.0;
        }
        if (h > 1.0)
        {
            h -= 1.0;
        }
    }

        h *= 360.0;
        s *= 100.0;
        l *= 100.0;

    hEdit -> setValue(h);
    sEdit -> setValue(s);
    l1Edit -> setValue(l);
}
