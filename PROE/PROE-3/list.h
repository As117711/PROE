#ifndef LIST_H
#define LIST_H
#include <ctime>
using namespace std;

template <class T>
struct Node{
          T elem;
          time_t time;
          Node *prev;
};
template <class T>
class List
{
    private:
        Node<T> *last;
        time_t start_time;

    public:
         int size;
        List();
        List(time_t start);
        List(List<T> &copy);
        virtual ~List();
        void add(int position, T &elem);
        void add_last(T &elem);
        int return_size();
        void remove(int position);
        Node<T> *return_node(int position);
        int return_time(int position);
        Node<T>* operator[](int position);
        List<T> operator=(List<T>& copy);

};





template<class T>
List<T>::List()
{
    last = nullptr;
    start_time = time(& start_time);
    size = 0;
}

template<class T>
List<T>::List(time_t start)
{
    last = nullptr;
    start_time = start;
    size = 0;
}

template<class T>
List<T>::~List()
{
    Node<T>* temp = last;
    Node<T>* temp2;
    while(temp!=nullptr){
        temp2 = temp;
        temp=temp->prev;
        delete temp;
    }
}

template<class T>
List<T>::List(List<T> &copy)
{
    Node<T>* temp = copy.last;
    Node<T>* temp2;

    size = copy.size;
    start_time = copy.start_time;

    if(temp!=nullptr)temp2 = new Node<T>;
    else temp2=nullptr;

    last=temp2;
    while(temp!=nullptr){
        temp2->elem = temp->elem;
        temp2->time = temp->time;
        if(temp->prev!=nullptr)temp2->prev = new Node<T>;
        temp2=temp2->prev;
        temp=temp->prev;
    }
}

template<class T>
List<T> List<T>::operator=(List<T>& copy){
    List<T> O(copy);
    return O;
}

template<class T>
Node<T>* List<T>::return_node(int position){
    Node<T>* temp = last;
    if(position > size-1)return nullptr;
    for(int i = 0;i<size-position-1; ++i){
        temp = temp->prev;
    }
    return temp;
}

template<class T>
int List<T>::return_time(int position){
    return (*this)[position]->time;
}

template<class T>
int List<T>::return_size(){
    return size;
}

template<class T>
Node<T>* List<T>::operator[](int position){
    return return_node(position);
}

template<class T>
void List<T>::add(int position, T &elem){
    Node<T> *newW = new Node<T>;
        newW->elem = elem;
        newW->time = time(&newW->time)-start_time;
    Node<T> *temp = last;

    if(temp == nullptr){
        last = newW;
        last->prev=nullptr;
    }

    else if(position >= size){
        newW->prev=last;
        last = newW;


    }

    else if(position <= 0){
        newW->prev = nullptr;
        return_node(0)->prev=newW;
    }

    else{
        newW->prev=return_node(position-1);
        return_node(position)->prev=newW;
    }
    ++size;

}

template<class T>
void List<T>::add_last(T &elem){
    add(size, elem);
}


template<class T>
void List<T>::remove(int position){
    if(position > size-1)position=size-1;
    if(position < 0)position = 0;
    if(position == size-1){
        Node<T>* temp = last;
        last = last->prev;
        delete temp;
    }
    else{
    Node<T>* temp = return_node(position);
    Node<T>* temp2 = return_node(position+1);
    temp2->prev = temp->prev;
    delete temp;
    }
    --size;
}

#endif // LIST_H
