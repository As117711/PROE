#include "include/Lista.h"
#include<iostream>
#include<fstream>

int main(){

    List<int> list;

    int t1=0,t2=1;


    list.add(0,t1);
    list.add(0,++t1);

    for(int i = 1; i<10; ++i){
        list.add(2,i);
    }

    for(int i = 0; i<10; ++i){
        printf("%d ",list[i]->elem);
    }




    return 0;
}









