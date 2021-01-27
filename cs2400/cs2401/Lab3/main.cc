/*********************************************************************
     Lab Assignment 3: This is a lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Summer 2019
*********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
     int data;
     node * link;
};


// These are the three I have written for you
void build_list(node* & head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

//These are the two that you are to write, as described in the 
//instructions page.
void remove_repeats(node*& head);
void split_list(const node* original, node*& lesser, 
		node*& greater,int split_value);



int main(){
    int start, stop;
    int split;
    char trash;
    node* head = NULL;
    node *lesser;
    node * greater;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout<<"Time to build list = "<<stop - start <<" seconds.\n";
    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout<<"Time to print list = "<<stop - start<<" seconds.\n";
    cout<<"Size of the list = "<<size(head)<<endl;
    start = time(NULL);
    remove_repeats(head);
    stop = time(NULL);
    cout << "Time to remove repeats = " << stop - start << " seconds." << endl;
    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout << "Time to print list = "  << stop - start<< " seconds." << endl;
    cout << "Please enter the number you want to split the list by." << endl;
    cin >> split;
    start = time(NULL);
    split_list(head, lesser, greater, split);
    stop = time(NULL);
    cout << "Time to split list = " << stop - start << " seconds." << endl;
    start = time(NULL);
    show_list(lesser);
    stop = time(NULL);
    cout << "Size of the list: " << size(lesser) << endl;
    cout << "Time to print the list of smaller numbers = "<< stop - start << " seconds." << endl;
    start = time(NULL);
    show_list(greater);
    stop = time(NULL);
    cout << "Size of the list: " << size(greater) << endl;
    cout << "Time to print the list of larger numbers = " << stop - start << " seconds." << endl;
    

    cout << "Enter any character to exit." << endl;
    cin >> trash;



return 0;
}

//splits 
void split_list(const node* original, node*& lesser, node*& greater,int split_value){
     const node* cursorO = original;
    lesser = new node;
     greater = new node;
     node* cursorL = lesser;
     node* cursorG = greater;


    // int count = 0; 

     cout << "start" << endl;
     for(cursorO; cursorO != NULL; cursorO = cursorO -> link){
               if(cursorO -> data < split_value){
                    //cout << "L" << endl;
                    //cursorL = new node;
                    cursorL -> link = new node;
                    cursorL = cursorL -> link;
                    cursorL -> data = cursorO -> data;
                    //cursorL -> link = new node;
                    //cursorL = cursorL -> link;
               }
               if(cursorO -> data > split_value){
                    //cout << "G" << endl;
                    cursorG -> link = new node;
                    cursorG = cursorG -> link;
                    cursorG -> data  = cursorO -> data;
                    //cout << "1";
                    //cursorG -> link = new node;
                    //cout << "2";
               //cursorG = cursorG -> link;
                    //cout << "3" << endl;
               }
               //count++;
               //cout << "count: " << count << endl;
          
     }
     //cursorL = NULL;
     //cursorG = NULL;
     lesser = lesser -> link;
     greater = greater -> link;
}


//changes the list to remove duplicates
void remove_repeats(node*& head){
     int theNumber;
     int number = 0;
     int withinNumber = 0;

     //cout << "the starting size is " << size(head) << endl;

     node * testing = head;
     //cout << "start successful" << endl;
     for(node * cursor = head; cursor != NULL; cursor = cursor -> link){
          //cout << "loop started" << endl;
          theNumber = cursor -> data;
          number++;
          //cout << "Starting number " << number << endl;
          //cout << "the size is now " << size(head) << endl;
          for(node * cursor2 = cursor; cursor2 -> link != NULL; cursor2 = cursor2 -> link){
               //cout << "second loop started" << endl;
               testing = cursor2 -> link;
               //cout << "testing set" << endl;
               if(testing -> data == theNumber && testing != cursor){
                    //cout << "if successful" << endl;
                    if(testing -> link != NULL){
                    cursor2 -> link = testing -> link;
                    }
               //}else{
                    //cout << "if unsuccessful" << endl;
               }
               withinNumber++;
               //cout << "checked data " << withinNumber << " for number " << number << endl; 
               //cout << "the size is "<< size(head) << endl;
          }
          withinNumber = 0;
          //cout << "the size is " << size(head) << endl;
     }
     cout << "The size of the new list is " << size(head) << endl;

}

// builds a linked list of 2000 random integers, all in the 1 to 500 range
void build_list(node*& head){
     node* cursor;
     head = new node;
     head->data = rand()%500 + 1;
     cursor = head;
     for(int i = 0; i < 2000; ++i){
	cursor->link = new node;
        cursor = cursor->link;
        cursor->data = rand()%500 + 1;
     }
     cursor->link = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
      const node * cursor = head;
      while(cursor !=  NULL){
   	cout<<cursor->data<<"  ";
	cursor = cursor->link;
      }
     cout<<endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor->link;
	}
	return count;
}
