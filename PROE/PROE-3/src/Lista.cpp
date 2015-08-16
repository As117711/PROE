#include "../include/Lista.h"
/*
template<class T>
Lista<T>::Lista()
{
    last = nullptr;
    size = 0;
}

template<class T>
Lista<T>::~Lista()
{
    //dtor
}

template<class T>
Wezel<T>* Lista<T>::return_wezel(int position){
    Wezel<T>* temp = last;
    if(position > size-1)return nullptr;
    for(int i = 0;i<=size-position-1; ++i){
        temp = temp->prev;
    }
    return temp;
}
template<class T>
void Lista<T>::add(int position, T &elem){
    Wezel<T> *newW = new Wezel<T>;
        newW->elem = elem;
    Wezel<T> *temp = last;

    if(temp == nullptr){
        last = newW;
        last->prev=nullptr;
    }

    else if(position == size-1){
        newW->prev=last;
        last = newW;
    }

    else{
        temp = return_wezel(position+1);
        newW->prev=return_wezel(position);
        temp->prev=newW;
    }
    ++size;

}

template<class T>
void Lista<T>::add_last(T &elem){
    add(size-1, elem);
}


template<class T>
void Lista<T>::remove(int position){
    if(position == size-1){
        Wezel<T> temp = last;
        last = last->prev;
        delete temp;
    }
    else{
    Wezel<T> temp = return_wezel(position);
    Wezel<T> temp2 = return_wezel(position+1);
    temp2->prev = temp->prev;
    delete temp;
    }
    --size;
}



*/


