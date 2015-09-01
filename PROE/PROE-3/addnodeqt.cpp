#include "addnodeqt.h"
#include "ui_addnodeqt.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;
AddNodeQT::AddNodeQT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNodeQT)
{
    ui->setupUi(this);
    setWindowTitle("Dodanie elementu");
    connect(ui->buttonBox, SIGNAL (accepted()), this, SLOT (positive()));
    connect(ui->buttonBox, SIGNAL (rejected()), this, SLOT (negative()));
}

AddNodeQT::~AddNodeQT()
{
    delete ui;
}

void AddNodeQT::positive()
{
    string owner = (ui->lineEdit_2->text()).toUtf8().constData();
    string path = (ui->lineEdit_5->text()).toUtf8().constData();
    string type = (ui->lineEdit_3->text()).toUtf8().constData();
    int price = (ui->lineEdit_4->text()).toInt();
    int position = (ui->lineEdit->text()).toInt();



    Building b = Building(type,price,owner,path);

    L->add(position, b);

    ((MainWindow*)parentt)->nodelist();
    ((MainWindow*)parentt)->show();




    this->accept();
}

void AddNodeQT::negative()
{
    this->reject();
}

void AddNodeQT::set_list(List<Building> *_L, QWidget *_parentt){
    L=_L;
    parentt = _parentt;
}
