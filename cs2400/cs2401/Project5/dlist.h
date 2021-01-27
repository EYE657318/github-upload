//this will be a header like for any normal class; it just has template<class T> above everything else. 
#include <iostream>
#include "dnode.h"
#include "iterator.h"
using namespace std;



template<class T>
class dlist{

    public:
    ////constructor
    dlist();
 
    ////////////////////////////big three      //TODO
    ~dlist();
    dlist(const dlist& other);
    void operator =(const dlist& other);

    

    ////inserts
    void front_insert(T add); //the node is created within the function
    void rear_insert(T add); //the node is created within the function

    ////removes
    void front_remove();
    void rear_remove();

    ////eventually won't be included?
    void show();
    void reverse_show();

    typedef node_iterator<T> iterator;
    iterator begin(){return iterator(head);}
    iterator end(){return iterator(NULL);}
    iterator r_begin(){return iterator(tail);}
    iterator r_end(){return iterator(NULL);}

    void insert_before(iterator spot, T item){
        node<T>* beforespot = spot.current -> previous();
        node<T>* newspot = new node<T>(item);
       // cout << "init" << endl;

        if(beforespot != NULL){
        beforespot -> set_next(newspot);
        }
       // cout << "void set" << endl;
        newspot -> set_previous(beforespot);
        //cout << "set to void" << endl;
        newspot -> set_next(spot.current);
        spot.current -> set_previous(newspot);
        listsize++;

        if(spot.current == head){
            //cout <<"hahahead" << endl;
            head = newspot;
        }

    }

    void insert_after(iterator spot, T item){
        //cout << "test" << endl;
       /* if(spot.current -> next() == NULL){
            cout << "do a barrel roll" << endl;
        }*/
       // cout << "check successful" << endl;
        //cout << spot.current -> next() << endl;
        node<T>* afterspot = spot.current -> next();
        //cout << "init.5" << endl;
        node<T>* newspot = new node<T>(item);
       // cout << "init" << endl;

        
        spot.current -> set_next(newspot);
        //cout << "1" << endl;
        newspot -> set_previous(spot.current);
        //cout << "2" << endl;
        newspot -> set_next(afterspot);
       // cout << "3" << endl;
        if(afterspot != NULL){
        afterspot -> set_previous(newspot);
        }
        //cout << "4" << endl;
        listsize++;

        if(spot.current == tail){
            //cout<<"hahatail"<<endl;
            tail = newspot;
        }
    }

    void remove(iterator spot){
        node<T>* beforespot = spot.current -> previous();
        node<T>* afterspot = spot.current -> next();
        beforespot -> set_next(afterspot);
        afterspot -> set_previous(beforespot);
        listsize--;

    }

    int size(){
        return listsize;
    }

    private:
    node<T>* head;
    node<T>* tail;
    int listsize;


};

#include "dlist.template"