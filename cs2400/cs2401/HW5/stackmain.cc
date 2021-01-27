/*****************************************************************
	Lab Assignment 8 - working with a stack
	It's sometimes tricky to set up the loop that reads the 
expression from the keyboard, so I am giving that to you. You have to 
fill in the rest of the main.
	John Dolan Spring 2019
			Ohio University
			Home of the Bobcats 
******************************************************************/
#include <stack> 
#include <iostream>
#include "calc_useful.h"
using namespace std; 


int main(){
    // declare your stack here
	stack<int> nums;
	char trash;
	bool broke = false;


    char c;
    int onenum, twonum;
	while(trash != '9'){
	broke = false;
	
	
    cout<<"Please enter your expression:\n";
	
	//cout << "past" << endl;

    c = cin.get(); // priming read for the sentinel loop.
    while(c != '\n'){
 	if(isdigit(c)){
	    cin.putback(c);
	    cin>>onenum;
		nums.push(onenum);
	// stack operation here.
	}
	else if(isop(c)){
	// if the stack is empty here you have an error.
	///
	// here is where you have to pop a couple of numbers,
		if(nums.empty()){
			cout << "Error: Not enough numbers for inputted operator." << endl;
			//cout << "Enter any character to exit." << endl;
			//cin >> trash;
			//return -1;
			//cout << "break" << endl;
			//cout << onenum << " break" << endl;
			broke = true;
			break;
		}
		twonum = nums.top();
		nums.pop();

		if(nums.empty()){
			cout << "Error: Not enough numbers for inputted operator." << endl;
			//cout << "Enter any character to exit." << endl;
			//cin >> trash;
			//return -1;
			//cout << "break" << endl;
			//cout << onenum << " break" << endl;
			broke = true;
			break;
		}
		onenum = nums.top();
		nums.pop();
		nums.push(evaluate(onenum, twonum, c));
        // apply the operator to the numbers
        // and then push the result back into the stack		    
	}
	c = cin.get(); // reading at the bottom of the sentinel loop
    }
	// this is where you get your final answer off the stack
	if(broke == false){
	onenum = nums.top();
	nums.pop();
	// it should be the only number left on the stack at this point
    if(! nums.empty()){
	cout<<"Error. Insufficient operators for operands.\n";
	//cout << "Enter any character to exit." << endl;
	//cin >> trash;
	//return -1;
    }
	//if()
    cout<<"The answer is: "<< onenum<<endl; //return 0;
	}
	cout <<"Enter 9 if you want to exit, and any other character if you want to continue." << endl;
	cin >> trash;
	//while(cin.peek() == '\n'){
	//cin.ignore();//}
	cin.ignore();//cin.ignore();cin.ignore();
	}
	//cout << "Enter any character to exit." << endl;
	//cin >> trash;
	return 0;

}
