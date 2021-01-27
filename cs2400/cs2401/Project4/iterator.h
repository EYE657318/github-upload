//right now I'm just listing the functions I'm going to need according to the main

//begin()
//end()
//r_begin()
//r_end()



//insert_before()
//insert_after()
//remove()

#include <iostream>

using namespace std;

template<class T>
    class dlist;

template<class T>
class node_iterator{
    public:
    ///Default constructor
    node_iterator(node<T>* init = NULL){
        current = init;
    }

    friend class dlist<T>;

    ///Operators
    bool operator !=(const node_iterator other){
        return current != other.current;
    }
    bool operator ==(const node_iterator other){
        return current == other.current;
    }
    T operator *(){
        return current -> data();
    }
    node_iterator operator ++(){
        current = current -> next();
        return *this;
    }
    node_iterator operator ++(int){
        node_iterator original(current);
        current = current -> next();
        return original;
    }
    node_iterator operator --(){
        current = current -> previous();
        return *this;
    }
    node_iterator operator --(int){
        node_iterator original(current);
        current = current -> previous();
        return original;
    }

    private:
    node<T>* current;

};