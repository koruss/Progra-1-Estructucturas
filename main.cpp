#include <iostream>
#include "dlinkedlist.h"
#include "trie.h"
#include "bstree.h"
#include "bstreedictionary.h"
#include "kvpair.h"


using namespace std;

int main()
{


//    BSTreeDictionary<int,int> *dic =new BSTreeDictionary<int,int>();
//    dic->insert(5,50);
//    dic->insert(1,10);
//    dic->insert(6,60);
//    dic->insert(4,40);
//    dic->insert(9,90);
//    dic->insert(10,100);
//    dic->remove(5) ;
//    cout<<dic->getValue(9);
    //dic->print();
    //cout<<dic->getSize();



    Trie *trie= new Trie();
   List<string> *hope =new DlinkedList<string>();

    trie->insert("casa");
    trie->insert("casona");
    trie->insert("castor");
    trie->insert("cas");
//    trie->insert("pan");
//    trie->insert("palopma");
//    trie->insert("paz");
//     trie->insert("pala");
//    trie->insert("palabra");


//   hope=dic->getValues();

//    cout<<hope->getSize()<<endl;
   hope=trie->getMatches("ca");

////    cout<<hope->getSize()<<endl;
    for(hope->goToStart();!hope->atEnd();hope->next()){
        cout<<hope->getElement()<<"--";
    }






//    BSTree<int,int> *tree= new BSTree<int,int>();
//    tree->insert(1,10);
//    tree->insert(6,60);
//    tree->insert(3,30);
//    tree->insert(4,40);
//    tree->insert(5,50);
//    tree->print();




}
