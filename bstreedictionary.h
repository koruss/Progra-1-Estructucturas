#ifndef BSTREEDICTIONARY_H
#define BSTREEDICTIONARY_H
#include "dictionary.h"
#include "bstnode.h"
#include "bstree.h"



template <typename K,typename V>

class BSTreeDictionary:public Dictionary<K,V>{

public:
    BSTree<K,V>  *pairs;

    BSTreeDictionary(){
        pairs= new BSTree<K,V>();

    }

    ~BSTreeDictionary(){
        //clear()

    }

    void insert(K key,V value){
        //KVPair<K,V> par= new KVPair<K,V>(key,value);
        pairs->insert(key,value);
    }

private:


public:
    V remove(K key){
        pairs->remove(key);

    }

    V getValue(K key){
        KVPair<K,V> p=pairs->find(key);
        return p.getValue();


    }

    void setValue(K key, V value){


    }

    void clear(){

    }
    bool contains(K key){

        return pairs->contains(key);
    }

    List<K>* getKeys(){
        List<K>*keys= new DlinkedList<K>();
        //Aqui va bien
        List<KVPair<K,V>> *list=new DlinkedList<KVPair<K,V>>();
        list=pairs->getElements();
        for(list->goToStart();!list->atEnd();list->next()){
            //cout<<list->getElement().getKey()<<endl;
            keys->append(list->getElement().getKey());
        }
        return keys;
    }



    List<V>* getValues(){
        List<V> *values= new DlinkedList<V>();
        List<KVPair<K,V>> *list=pairs->getElements();
        for(list->goToStart();!list->atEnd();list->next()){
            values->append(list->getElement().getValue());
        }
        return values;

    }


    int getSize(){
        return pairs->getSize();
    }


    void print(){
        cout<<"Elementos del Diccionario: "<<endl;
        pairs->print();
    }
};

#endif // BSTREEDICTIONARY_H
