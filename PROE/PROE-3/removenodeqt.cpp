#include "removenodeqt.h"
#include "ui_removenodeqt.h"
#include "mainwindow.h"

RemoveNodeQT::RemoveNodeQT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveNodeQT)
{
    ui->setupUi(this);
    setWindowTitle("Usunięcie elementu");
    connect(ui->buttonBox, SIGNAL (accepted()), this, SLOT (positive()));
    connect(ui->buttonBox, SIGNAL (rejected()), this, SLOT (negative()));
}

RemoveNodeQT::~RemoveNodeQT()
{
    delete ui;
}

void RemoveNodeQT::positive()
{
    int position = (ui->lineEdit->text()).toInt();
    L->remove(position);

    ((MainWindow*)parent)-t>nodelist();
    ((MainWindow*)parentt)->show();

    this->accept();
}

void RemoveNodeQT::negative()
{
    this->reject();
}

void RemoveNodeQT::set_list(List<Building> *_L, QWidget *_parentt){
    L=_L;
    parentt=_parentt;
}
