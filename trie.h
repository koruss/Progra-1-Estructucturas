#ifndef TRIE_H
#define TRIE_H
#include "trienode.h"
#include <string>
#include <stdexcept>
#include "bstnode.h"

using namespace std;

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root=new TrieNode();
    }

    ~Trie(){
        clear();
        delete root;
    }

    bool containsWord(string word){
        TrieNode *current=root;
        for (int i=0;i<word.size();i++) {
            char c=word[i];
            if(!current->contains(c)){
                return false;
            }
            current=current->getChild(c);
        }
        return current->getIsFinal();
    }

    bool containsPrefix(string prefix){
        TrieNode *current=root;
        for (int i=0;i<prefix.size();i++) {
            char c=prefix[i];
            if(!current->contains(c)){
                return false;
            }
            current=current->getChild(c);
        }
        return true;
    }
    void clear(){

    }


    void insert(string palabra){
        TrieNode *current=root;
        current->increaseCount();
        for(int i=0;i<palabra.length();i++){
            char letra=palabra[i];
            if(!current->contains(letra)){
                current->add(letra);
            }
            current=current->getChild(letra);
//            if(i==palabra.length()-2){
//                current->setIsFinal(true);
//            }


        }
        current->setIsFinal(true);

    }

    List<string> *getMatchesAux(TrieNode *current, string prefix, List<string> *result){
        List<char> *keys= current->getChildren();
        List<TrieNode*> *values= current->getChildrenPointers();
        values->goToStart();
        for(keys->goToStart();!keys->atEnd();keys->next()){
            cout<<keys->getElement();
        }
        cout<<endl<<endl;
        for(keys->goToStart();!keys->atEnd();keys->next()){
            cout<<keys->getElement()<<endl;
            if(values->getElement()==NULL){
                cout<<"if"<<endl;
                prefix+=keys->getElement();
                if(current->getIsFinal()){
                    result->append(prefix);
                }
                prefix=eraseCar(prefix);
            }
            else{
                cout<<"else"<<endl;
                prefix+=keys->getElement();//mete la letra en el prefix
                cout<<current->getIsFinal()<<endl;
                if(current->getIsFinal()){

                    result->append(prefix);
                }
                cout<<"prefix: "<<prefix<<endl;
                getMatchesAux(values->getElement(), prefix,result);
                prefix=eraseCar(prefix);

            }


          values->next();
        }
        return result;
    }

    string eraseCar(string word){
        string a;
        for(unsigned int i=0;i<word.length()-1;i++){
            a+=word[i];
        }
        return a;
    }

    List<string> *getMatches(string prefix){
        List<string> *result= new DlinkedList<string>();
        TrieNode *current=root;
        cout<<current->getPrefixCount()<<endl;

        for(unsigned int i=0; i<prefix.size(); i++){
            char word=prefix[i];
            cout<<word<<endl;
            if(current->contains(word)){
                current=current->getChild(word);
                cout<<current->getPrefixCount()<<endl;

            }
            else{
                return result;
            }
        }
        getMatchesAux(current, prefix, result);
        return result;
    }

//    void print(){
//        if(root==NULL){

//        }

//    }


};



#endif // TRIE_H
