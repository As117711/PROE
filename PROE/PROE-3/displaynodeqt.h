#ifndef DISPLAYNODEQT_H
#define DISPLAYNODEQT_H

#include <QDialog>
#include "list.h"
#include "building.h"
#include "Static/static.h"

namespace Ui {
class DisplayNodeQT;
}

class DisplayNodeQT : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayNodeQT(QWidget *parent = 0);
    ~DisplayNodeQT();
    Node<Building> *node;
    void set_node(Node<Building> *_node);
    void make();

private:
    Ui::DisplayNodeQT *ui;
    SimpleProcessing Process;
    QImage Image;
    int width;
    int height;

    unsigned char *picture;

private slots:
    void gray();
    void smoothes();
    void conture();
};

#endif // DISPLAYNODEQT_H
