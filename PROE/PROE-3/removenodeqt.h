#ifndef REMOVENODEQT_H
#define REMOVENODEQT_H

#include <QDialog>
#include "building.h"
#include "list.h"

namespace Ui {
class RemoveNodeQT;
}

class RemoveNodeQT : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveNodeQT(QWidget *parent = 0);
    ~RemoveNodeQT();
    void set_list(List<Building> *_L, QWidget *_parentt);

private:
    Ui::RemoveNodeQT *ui;
    List<Building> *L;
    QWidget *parentt;
private slots:

    void positive();
    void negative();
};

#endif // REMOVENODEQT_H
