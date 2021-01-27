/******************************************************************
    This is the main for the Lab 9 Assignment of CS2401. You will need 
to implement the rearview function which should display the list 
backwards. Also, there are problems in the code which you will need to 
diagnose using gdb.
Finally you will also need to write and test the copy constructor for 
this class.
	John Dolan	School of EECS Ohio University, Athens Ohio
			Spring 2018
********************************************************************/

#include<iostream>
#include<cstdlib>
#include "llist.h"
using namespace std;

int main(){

    int n;
    int trash;

    LList somenums;
    for(int i = 0; i <35; ++i)
    {	n = rand()%700 + 1;
	somenums.add_item(n);
    //cout << n << endl;
    }
    //cout << "setup complete" << endl;
// Once you have written the rear-view this should let you
// see the list frontwards and backwards.
//cout << somenums.size() << endl;
      somenums.frontview();
      cout << "COMPLETE 1" << endl << endl << endl;
      somenums.rearview();
      cout << "COMPLETE 2" << endl;
      //somenums.frontview();
// This part will be uncommented once you have written the copy constructor

{
    LList numcopy(somenums);  // call to the copy constructor
    cout << "COPIED" << endl;
    numcopy.frontview();
    cout << "front over" << endl;
    numcopy.rearview();
    cout << "rear over" << endl;
}   // Line 34 - What happens here?

// Checking the original list
    cout<< "originals below:" << endl;
   somenums.frontview();
   somenums.rearview();


cout << endl << "enter any characer to exit." << endl;
cin >> trash;
return 0;
}
	

