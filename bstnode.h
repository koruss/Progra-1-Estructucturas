#ifndef BINNODE_H
#define BINNODE_H
#include <iostream>
#include "kvpair.h"
using namespace std;

template <typename K,typename V>



class BSTNode
{
private:
    KVPair<K,V> element;
    BSTNode<K,V> *left;
    BSTNode<K,V> *right;


public:
    BSTNode(BSTNode<K,V>*left=NULL,BSTNode<K,V>*right=NULL){
        this->left=left;
        this->right=right;
    }


    BSTNode(K key,V value=NULL, BSTNode<K,V> *left=NULL, BSTNode<K,V> *right=NULL) {
        this->element=KVPair<K,V>(key,value);
        this->left=left;
        this->right=right;

    }






//    ~BSTNode(){

//    }

    KVPair<K,V> getElement(){
        return element;
    }

    void setElement(KVPair<K,V> element){
        this->element;
    }

    BSTNode<K,V> *getLeft(){
        return left;
        }

    void setLeft(BSTNode<K,V> *left){
        this->left = left;
        }

    BSTNode<K,V> *getRight(){
        return right;
        }

    void setRight(BSTNode<K,V> *right){
        this->right = right;
        }

    bool isLeaf(){
        return left==NULL && right==NULL;
        }

    int childrenCount(){
        return(left==NULL?0:1)+(right==NULL?0:1);
        }

    BSTNode<K,V> *getUniqueChild(){
        return left==NULL ? right : left;
        }

    BSTNode<K,V> * getSuccesor(){
        return getSuccessorAux(right);
        }

private:
    BSTNode<K,V> *getSuccessorAux(BSTNode<K,V> *pRoot){
        if(pRoot==NULL)return NULL;
        if(pRoot->left==NULL)return pRoot;
        else{
            return getSuccessorAux(pRoot->left);
        }
    }

private:
    void swap(BSTNode<K,V>*node1,BSTNode<K,V>*node2){
        KVPair<K,V> temp= node1->getElement();
        node1->setElement(node2->getElement());
        node2->setElement(temp);
    }
public:
    bool contains(KVPair<K,V> element){
        try {
            find(element);
            return true;
        } catch (runtime_error &e) {
            return false;

        }
    }



};
#endif // BINNODE_H
