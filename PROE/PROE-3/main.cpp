#include"mainwindow.h"
#include<QApplication>
#include"list.h"
#include"building.h"
#include<ctime>
#include<iostream>

int main(int argc, char *argv[])
{
    time_t start = time(&start);


    List<Building> lista(start);

    QApplication a(argc, argv);

    MainWindow w;

    w.set_list(&lista);

    w.nodelist();

    w.show();


    return a.exec();
}
