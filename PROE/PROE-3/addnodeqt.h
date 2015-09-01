#ifndef ADDNODEQT_H
#define ADDNODEQT_H

#include <QDialog>
#include "building.h"
#include "list.h"
namespace Ui {
class AddNodeQT;
}

class AddNodeQT : public QDialog
{
    Q_OBJECT

public:
    explicit AddNodeQT(QWidget *parent = 0);
    ~AddNodeQT();
    void set_list(List<Building> *_L, QWidget *_parentt);

private:
    Ui::AddNodeQT *ui;
    List<Building> *L;
    QWidget *parentt;
private slots:

    void positive();
    void negative();
};

#endif // ADDNODEQT_H
