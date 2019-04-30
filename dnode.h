#ifndef DNODE_H
#define DNODE_H
#include <iostream>

using namespace std;
template<typename E>
class DNode{
public:
    DNode <E> * next;
    DNode<E> *previous;
    E element;



    DNode(E element,DNode<E> *next=NULL, DNode<E> *previous=NULL){
        this->element=element;
        this->next=next;
        this->previous=previous;
    }


    DNode(DNode<E>*next=NULL,DNode<E> *previous=NULL){
        this->next =next;
        this->previous=previous;
    }
};



#endif // DNODE_H
