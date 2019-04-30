#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
#include "list.h"
#include <stdexcept>
#include "dnode.h"

using namespace std;

template<typename E>

class DlinkedList: public List<E>{
private:
    DNode<E> *head;
    DNode<E> *tail;
    DNode<E> *current;
    int size;

public:
    DlinkedList(){
        head=new DNode<E>();
        tail = new DNode<E>();
        head->next=tail;
        tail->previous=head;
        current= head;
        size=0;
    }
    ~DlinkedList(){
        clear();
        delete head;
        delete tail;
    }

    void insert(E element){
        current->next=current->next->previous= new DNode<E>(element, current->next,current);
        size++;

    }



    void append(E element){

         tail->previous->next= new DNode<E>(element,tail,tail->previous);
         tail->previous=tail->previous->next;
         size++;

    }

    E remove()throw(runtime_error){
        if(size==0)throw runtime_error("List is Empty");
        if(current->next==tail)throw runtime_error("No current element while trying to remove");
        E result= current->next->element;
        DNode<E> *temp= current->next;
        current->next=temp->next;
        current->next->previous=current;
        delete temp;
        size--;
        return result;
    }


    void clear(){
        while(head->next!=tail){
            current=head->next;
            head->next=head->next->next;
            delete current;
        }
        current=tail->previous=head;
        size=0;

    }

    E getElement()throw(runtime_error){
        if(size==0)throw runtime_error("List is empty");
        if(current->next==tail)throw runtime_error("No current element");
        return current->next->element;


    }


    void goToStart(){
        current=head;
    }

    void goToEnd(){
        current=tail->previous;
    }

    void goToPos(int pos) throw(runtime_error){
        if(pos<0||pos>size)throw runtime_error("Index out of bounds");
        current=head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }

    }

    int getSize(){
        return size;
    }

    bool atStart(){
        return current==head;
    }

    bool atEnd(){
        return current->next==tail;
    }

    void next(){
        if(current->next!=tail){
            current=current->next;
        }
    }

    void previous(){
        if(current!=head){
            current=current->previous;
        }
    }

    int getPos(){
        int pos=0;
        DNode<E> *temp=head;
        while(temp!=current){
            pos++;
            temp=temp->next;
        }
        return pos;
    }


    void sort(){//sin revisar :(
        if(getSize()==0)return;

        DlinkedList<int> *menores= new DlinkedList<int>();
        DlinkedList<int> *mayores= new DlinkedList<int>();
        goToStart();
        E pivote=remove();
        while(!atEnd()){
            if(getElement()<pivote){
                menores->append(remove());
            }
            else{
                mayores->append(remove());
            }
        }
        menores->sort();
        mayores->sort();

        this->clear();
        menores->goToStart();
        while(!menores->atEnd()){
            this->append(menores->remove());
        }
        append(pivote);
        mayores->goToStart();
        while(!mayores->atEnd()){
            this->append(mayores->remove());
        }



    }

    void print(){

        cout<<endl<<"Lista: ";
        for(goToStart();!atEnd();next()){
            cout<<getElement()<<"- ";
        }

    }


};
#endif // DLINKEDLIST_H
