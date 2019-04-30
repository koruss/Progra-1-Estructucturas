#ifndef BSTREEDICTIONARY_H
#define BSTREEDICTIONARY_H
#include "dictionary.h"
#include "bstnode.h"
#include "kvpair.h"



template <typename K, typename V>
class BSTreeDictionary:public Dictionary<K,V>{
    BSTNode<KVPair<K,V>> *root;
    BSTreeDictionary(){
        root=NULL;
    }

    ~BSTreeDictionary(){
        //clear()

    }

    void insert(K key,V value){
        root=insertAux(key,value,root);
    }

    void insertAux(K pKey, V pValue,BSTNode<KVPair<K,V>>* pRoot){
        if(pRoot==NULL){

            return BSTNode<KVPair<K,V>>(new KVPair<K,V>(pKey,pValue));
        }

        if(pKey<pRoot->getElement()->getKey){
            pRoot->setLeft(insertAux(pRoot->getLeft(),));
            return pRoot;
        }
        else{
            pRoot->setRight(insertAux(pRoot->getRight(),element));
            return pRoot;
        }

    }
    void remove(K key){

    }

    void getValue(){

    }

    void setValue(){

    }

    void clear(){

    }
    bool contains(K key){

    }

    List<K>* getKeys(){

    }

    List<K>* getValues(){

    }
    int getSize(){

    }
};

#endif // BSTREEDICTIONARY_H
