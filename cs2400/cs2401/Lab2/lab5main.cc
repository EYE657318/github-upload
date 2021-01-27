/*****************************************
	This is the main for Lab Assignment 4.
	You will be creating the Numbers class that it uses.
	Follow the instructions on the lab sheet.
		John Dolan	Ohio University EECS
**************************************************/

#include<ctime>

#include "numbers.h"

using namespace std;


int main()
{
     Numbers N1, N2;

	 int trash;
     
for(size_t i = 2; i < 16; i +=2)

	N1.add(i);
   
  N1.display(cout);
     
     cout<<endl;


     N2 = N1;
	// for(int i = 0; i < 5; i++){
	//	 N2.add(i);
    //}

	

     for(int i = 0; i < 4; ++i)
	
	N2.remove_last();
     
     for(size_t i = 5; i < 20; i += 5)
      
	N2.add(i);

	cout << "The original, address " << N1.reveal_address() << endl;
     N1.display(cout);
	 cout << endl << "The altered copy, address " <<  N2.reveal_address() << endl;
	 N2.display(cout);
	 cout << "fin" << endl;

unsigned long start, stop, running;

     start = time(NULL);


// This part is added after question 6

    unsigned long item = 0;
    
     try{

	while(item<5){ // Five containers will be created

	    Numbers N3;

	    for(int i = 0; i < 100; i++){

		N3.add(item);
	    }
	++item;
	cout<<N3.reveal_address()<<endl;
	}

     }

catch(bad_alloc){  // this probably won't be needed

	cout<<"Memory failure after adding " <<item<<endl;

}


stop = time(NULL);

running = (stop - start)/60;

cout<<endl<<"Running took "<<running<<" minutes.\n";

cout<<"Total bytes allocated = "<<byte_count<<endl;
cout << "Enter any character to exit." << endl;
cin >> trash;




return 0;
}

