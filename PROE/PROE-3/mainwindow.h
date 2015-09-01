#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addnodeqt.h"
#include "removenodeqt.h"
#include "displaynodeqt.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_list(List<Building> *L);
    void nodelist();

private:
    Ui::MainWindow *ui;
    AddNodeQT Add;
    RemoveNodeQT Remove;
    DisplayNodeQT Display;
    List<Building> *L;

private slots:
    void add_node();
    void remove_node();
    void display_node(QListWidgetItem *item);

};

#endif // MAINWINDOW_H
