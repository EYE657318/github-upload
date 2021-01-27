//The node which will be placed into the linked list

#include <iostream>

using namespace std;

template<class T>
class node{
    public:

    ///Constructor
    node(T stored, node* b = NULL, node* f = NULL){
        datahere = stored; prev_point = b; next_point = f;
    } 

    ///Accessors
    node* next(){return next_point;}
    node* previous(){return prev_point;}
    T data(){return datahere;}

    ///Mutators
    void set_next(node* nnode){next_point = nnode;}
    void set_previous(node* nnode){prev_point = nnode;}
    void set_data(T ndata){datahere = ndata;}



    private:
    T datahere;
    node* prev_point;
    node* next_point;
 
};