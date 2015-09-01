#include "displaynodeqt.h"
#include "ui_displaynodeqt.h"
#include <iostream>
DisplayNodeQT::DisplayNodeQT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayNodeQT)
{
    ui->setupUi(this);
    setWindowTitle("Wyświetlenie elementu");

    connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (gray()));
    connect(ui->pushButton_2, SIGNAL (clicked()), this, SLOT (smoothes()));
    connect(ui->pushButton_3, SIGNAL (clicked()), this, SLOT (conture()));
}

DisplayNodeQT::~DisplayNodeQT()
{
    delete ui;
}

void DisplayNodeQT::set_node(Node<Building> *_node)
{
    node=_node;
}

void DisplayNodeQT::make()
{
    ui->Name->setText(QString::fromStdString(node->elem.return_owner_name()));
    ui->Price->setText(QString::number(node->elem.return_price())+"$");
    ui->Time->setText(QString::number(node->time)+"s");
    ui->Type->setText(QString::fromStdString(node->elem.return_type()));

    QString path("/home/kamil/PROE3/maps/"+ QString::fromStdString(node->elem.return_picture_path()));

    QPixmap temp(path);


    ui->Photo->setPixmap(temp);

    Image = temp.toImage();


    picture = Image.bits();

    width = Image.width();

    height = Image.height();


}

void DisplayNodeQT::gray(){
    Process.convertToGrayscale(picture, width, height, 4);

    cout << width << " " << height << "\n";
    QImage Image(picture,width,height, QImage::Format_RGB32);

    QPixmap temp = QPixmap::fromImage(Image);
    ui->Photo->setPixmap(temp);

    this->show();

}

void DisplayNodeQT::smoothes(){
    Process.smoothing(picture, width, height, 4);

    QImage Image(picture,width,height, QImage::Format_RGB32);

    QPixmap temp = QPixmap::fromImage(Image);
    ui->Photo->setPixmap(temp);

    this->show();

}

void DisplayNodeQT::conture(){
    Process.edgeDetection(picture, width, height, 4);

    QImage Image(picture,width,height, QImage::Format_RGB32);

    QPixmap temp = QPixmap::fromImage(Image);
    ui->Photo->setPixmap(temp);

    this->show();

}


