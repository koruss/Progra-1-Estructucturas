#ifndef KVPAIR_H
#define KVPAIR_H
#include <iostream>
template <typename K, typename V>

class KVPair{
private:
    K key;
    V value;

public:
    //Constructores de la clase
    KVPair(){
        this->key=NULL;
        this->value=NULL;
    }

    KVPair(K key, V value){
        this->key=key;
        this->value=value;
    }

    //Metodos de acceso
    K getKey()
    {
        return this->key;
    }

    void setKey(const K &value)
    {
        key = value;
    }

    V getValue() const
    {
        return value;
    }

    void setValue(const V &value)
    {
        value = value;
    }

    //operadores

    void operator=(const KVPair &other){
        this->key= other.key;
        this->value=other.value;
    }

    bool operator==(const KVPair &other){
        return key==other.key;
    }

    bool operator !=(const KVPair &other){
        return key!=other.key;
    }

    bool operator <(const KVPair &other){
        return key < other.key;
    }
    bool operator <=(const KVPair &other){
        return key<=other.key;
    }

    bool operator >(const KVPair &other){
        return key>other.key;
    }

    bool operator >=(const KVPair &other){
        return key>=other.key;
    }






};
#endif // KVPAIR_H
