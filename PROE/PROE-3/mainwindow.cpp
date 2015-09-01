#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   setWindowTitle("PROE-3");
   connect(ui->actionDodaj_element, SIGNAL (triggered()), this, SLOT (add_node()));
   connect(ui->actionUsu_element, SIGNAL (triggered()), this, SLOT (remove_node()));
   connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
           this, SLOT(display_node(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_node(){
    Add.set_list(L,this);
    Add.show();
}

void MainWindow::remove_node(){
    Remove.set_list(L, this);
    Remove.show();
}

void MainWindow::set_list(List<Building> *_L){
    L=_L;
}

void MainWindow::nodelist(){
    ui->listWidget->clear();
    if(L->return_size() == 0)ui->listWidget->addItem("Brak elementów w liście!");
    else{
        for(int i = 0; i<L->return_size(); ++i){
            QString S = QString::number(i)+". Obiekt "+QString::fromStdString((*L)[i]->elem.return_owner_name());
            QListWidgetItem *Item = new QListWidgetItem(S);
            ui->listWidget->addItem(Item);
        }
    }
}
void MainWindow::display_node(QListWidgetItem *item){
    for(int i = 0; i<L->return_size(); ++i){
        if(ui->listWidget->item(i) == item){
            Display.set_node((*L)[i]);
            Display.make();
            Display.show();
        }
    }
}
