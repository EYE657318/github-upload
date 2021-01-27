//*******************************************
//    Implementation file for the Numlist class, which 
//    allows programmers to store a list of numbers that they
//    choose to have sorted if they like.
//	January 2013		John Dolan
//	Ohio University		EECS
//**********************************************/
#include "numlist.h"
#include <string>
using namespace std;

// Constructor
NumList::NumList(){
	used = 0;
}

void NumList::insert(int num){
	if(used <CAPACITY){
		data[used] = num;
		used++;
	}
	else{
		cout<<"Error. List capacity has been reached.\n";
	}
}

void NumList::load_from_file(istream& ins){
// The implementation of this function is left to the student
	while(!ins.eof()){
		string toInt;
		int toInsert;
		getline(ins, toInt);
		toInsert = stoi(toInt);
		//cout << toInsert << endl;
		insert(toInsert);
		getline(ins, toInt);
		
	}
}


void NumList::save_to_file(ostream& outs){
// The implementation of this function is left to the student
	for(int i = 0; i < used; i++){
		outs << data[i] << endl;
	}
}

void NumList::see_all()const{
	char trash2;
	if(used == 0){
	    cout<<"Empty list.\n";
	}
	else{
	    for(size_t i = 0; i<used; ++i){
		cout<<data[i]<<endl;
		}
	}
}

int NumList::get_item(size_t index)const{
	if(index < used)
		return data[index];
	else 
		return -1;
}
	
void NumList::b_sort(){
    bool done = false;
    int j;
    int tmp;
    while(!done){
	done = true;  //!  
	for(j = used - 1; j >= 0; --j){ 
	    if(data[j] < data[j-1] && j != 0){   //!=0
		done = false;
		//cout << "switching " << data[j] << " and " << data[j - 1] << endl; 
		tmp = data[j];
		data[j] = data[j-1];
		data[j-1] = tmp;              //there was an equals instead of a -
	    }
		
	}
	
    }
}
