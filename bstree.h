#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "bstnode.h"
#include "dlinkedlist.h"
#include "list.h"

template<typename K,typename V>

class BSTree{
private:
   BSTNode<K,V> *root;



public:
   BSTree(){
       root=NULL;
   }

   ~BSTree(){
      clear();
   }

   void insert(K key,V value){
       root= insertAux(root,key,value);

   }
private:
   BSTNode<K,V> *insertAux(BSTNode<K,V> *pRoot, K key,V value){
       if(pRoot==NULL){
           return new BSTNode<K,V>(key,value);
       }
       int k=(int)key;
       if(k<(int)pRoot->getElement().getKey()){
           pRoot->setLeft(insertAux(pRoot->getLeft(),key,value));
           return pRoot;
       }
       else{
           pRoot->setRight(insertAux(pRoot->getRight(),key,value));
           return pRoot;
       }
   }




public:
   KVPair<K,V>find(K element)throw(runtime_error){
       return findAux(root,element);
   }


private:
    KVPair<K,V> findAux(BSTNode<K,V>*pRoot,K element)throw(runtime_error){
       if(pRoot==NULL)throw runtime_error("Tree is Empty");

       if(element==pRoot->getElement().getKey()){
           return pRoot->getElement();
       }
       if(element<pRoot->getElement().getKey()){
           return findAux(pRoot->getLeft(),element);
       }
       else{
           return findAux(pRoot->getRight(),element);
       }
   }

public:
   KVPair<K,V> remove(K key)throw(runtime_error){
       KVPair<K,V> result = find(key);
       root =removeAux(root,key);
       return result;
   }

private:
   BSTNode<K,V> *removeAux(BSTNode<K,V> *pRoot, K key)throw(runtime_error){
       if(pRoot==NULL)throw runtime_error("Element not found");
       if(key<pRoot->getElement().getKey()){
           pRoot->setLeft(removeAux(pRoot->getLeft(),key));
           return pRoot;
       }
       if(key>pRoot->getElement().getKey()){
           pRoot->setRight(removeAux(pRoot->getRight(),key));
           return pRoot;
       }
       else{
           if(pRoot->isLeaf()){
               delete pRoot;
               return NULL;
           }
           if(pRoot->childrenCount()==1){
               BSTNode<K,V> *temp = pRoot->getUniqueChild();
               delete pRoot;
               return temp;
           }
           else {
               BSTNode<K,V> *succesor=pRoot->getSuccesor();
               swap(pRoot,succesor);
               pRoot->setRight(removeAux(pRoot->getRight(),key));
               return pRoot;
           }
       }
   }


public:
   bool contains(K key){
       return containsAux(root,key);

   }

private:
   bool containsAux(BSTNode<K,V>* pRoot,K key){
       if(pRoot==NULL){
           return false;
       }
       if(key==pRoot->getElement().getKey()){
           return true;
       }
       if(key<pRoot->getElement().getKey()){
           return containsAux(pRoot->getLeft(),key);
       }
       else{
           return containsAux(pRoot->getRight(),key);
       }
   }

public:
   void clear(){
       clearAux(root);
       root=NULL;
   }
private:
   void clearAux(BSTNode<K,V> *pRoot){
       if(pRoot==NULL)return;
       clearAux(pRoot->getLeft());
       clearAux(pRoot->getRight());
       delete pRoot;
   }

public:
   List<KVPair<K,V>> *getElements(){
       List< KVPair<K,V> > *elements= new DlinkedList<KVPair<K,V> >();
       getElementsAux(root,elements);
       return elements;
   }

private:

   void getElementsAux(BSTNode<K,V> *pRoot,List<KVPair<K,V> > *elements){
          if(pRoot==NULL){
              return ;
          }
          else{
              getElementsAux(pRoot->getLeft(),elements);
              //cout<<pRoot->getElement().getKey()<<endl;
              elements->append(pRoot->getElement());
              getElementsAux(pRoot->getRight(),elements);

          }
}






public:

//   int getSize(){
//    int *size=new int;
//    getSizeAux(root,size);

//    return ;

//   }

//   void getSizeAux(BSTNode<K,V> *pRoot,int pSize){
//       if(pRoot== NULL){
//           return;
//       }
//       else{
//           getSizeAux(pRoot->getLeft(),pSize);
//           cout<<"k";
//           pSize++;
//           getSizeAux(pRoot->getRight(),pSize);

//       }
//   }


   int getSize(){//Lo cambie a recursividad de pila por que por cola no me funka
       return getSizeAux(root);
   }

   int getSizeAux(BSTNode<K,V>*root){
       if(root!=NULL){
           return 1+getSizeAux(root->getLeft()) + getSizeAux(root->getRight());
       }
       else{
           return 0;
       }
   }

   void print(){
       return printAux(root);
   }

private:
   void printAux(BSTNode<K,V>* pRoot){
       if(pRoot==NULL){
           return ;
       }
       else{          
           printAux(pRoot->getLeft());
           cout<<pRoot->getElement().getKey()<<"-"<<pRoot->getElement().getValue()<<endl;
           printAux(pRoot->getRight());

       }
   }

};
#endif // ARBOLBINARIO_H
