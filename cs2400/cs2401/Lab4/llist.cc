/************************************************************************
     This is the implementation file for the LList class which is a 
container based on a doubly linked list. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.
	John Dolan		Ohio University		Spring 2018
************************************************************************/
#include<iostream>
#include "llist.h"
using namespace std;

void LList::frontview()const{
    node* cursor = head;
    while (cursor != NULL){
	cout<<cursor->data() <<"  ";
	cursor = cursor->next();
    }
}

// The student is required to write the implementation of this function
void LList::rearview()const{
	node* cursor = tail;
	while (cursor != NULL){
	cout << cursor -> data() << "  ";
	cursor = cursor -> previous();
}

}


void LList::add_item(int item){
    if(head == NULL){
	head=new node(item); //removed =tail
	tail=NULL;
	head -> set_next(tail);
	nodecount++;
	//cout << "set first" << endl;
    }
   else if(item%5 == 0 && nodecount > 3){
		//cout<<"OK"<<endl;
		int i = 0;
		node* cursor=head;
	while(i < nodecount/2){
	    cursor = cursor->next();
	    i++;//0
		//cout<<"e"<<endl;
	}
	node* set = new node(item, cursor -> previous(), cursor-> next());
	cursor->previous()->set_next(set);//new node(item,cursor->next(),cursor->previous()));
	cursor -> next() -> set_previous(set);

	//cout<<"done"<<endl;
	nodecount++;
	
    }
    else{
		if(tail == NULL){
			node* next = new node (item, head);  //maybe make tail head?
			tail = next;
			head -> set_next(tail);
			//cout<<"Ok"<<endl;
		}else{
			tail->set_next(new node(item, tail));
			tail = tail->next();
			//cout <<"ok"<<endl;
		}
	nodecount++;
    }
}

LList::~LList(){
   node* rmptr;
   while(head != NULL){
	rmptr=head;
	head = head->next();
	delete rmptr;
   }
}

LList::LList(const LList& other){
	node* cursor = new node;
	head = cursor;
	cursor -> set_previous(NULL);
	nodecount = other.nodecount;

	for(node* otherlist = other.head; otherlist != NULL; otherlist = otherlist -> next()){
			cursor -> set_data(otherlist -> data());
			//cout << cursor -> data() << endl;
			cursor -> set_next(new node);
			cursor -> next() -> set_previous(cursor);
			cursor = cursor -> next();
			
	}
	//cursor = NULL;
	tail = cursor -> previous();
	tail -> set_next(NULL);
	//cursor = NULL;
	//head = head -> next();
}
