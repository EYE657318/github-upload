/******************************************************************
    This is the main for the final submission of project four. Begin by
    hiding the test main: mv main1.cc main1.hold
    and unhiding this:    mv main2.hold main2.cc

    Now you should be able to compile and run this without trouble since
    you know all your functions work.

    When you run it you will see lots of numbers streaming across the screen.
    To see the colors:
      redirect the output to a file: a.out > result
      apply either p1p2_mkhtml or labs_mkhtml to the file
	p1p2_mkhtml result
      if you're using ssh use something like winscp to download the resulting
        html file to your machine
      double-click the html to see the colors
		John Dolan			Spring 2014
********************************************************************/
#include <iostream>
#include <fstream>
#include "dlist.h"
#include "swatches.h"

using namespace std; 

int main() 
{	

	int trash;

	dlist<Swatch> swatches;
	dlist<Swatch>::iterator it; 
	ifstream fin; 
	fin.open("swatches.txt"); 
	if (fin.fail())
	{
		cout << "Could not open input file." << endl; 
		return 1; 
	}
	Swatch tmp; 
	while (fin >> tmp)
	{
		int red = tmp.get_red(); 
		int green = tmp.get_green(); 
		int blue = tmp.get_blue(); 
		
		if ( (green >= red) && (green >= blue) ) // green is dominant
		{
			swatches.rear_insert(tmp); 
			//cout << "Green" << endl;
		}
		else if ( (red >= green) && (red>=blue) ) 
				// red is dominant
		{
			swatches.front_insert(tmp); 
			//cout << "Red" << endl;
		}
		else // blue is dominant
		{
			//cout << "Blue start" << endl;
		   it = swatches.begin();
		   for(int i = 0;i < swatches.size()/2;i++)
			++it; // loop moves iterator to the middle
			//cout << swatches.size() << endl;
		   if(swatches.size()%2 == 1){
			//cout << "Odd" << endl;
			swatches.insert_before(it,tmp);
		   }
		   else{
			//cout << "Even" << endl;
			swatches.insert_after(it,tmp);
		   }
		   //cout << "Blue end" << endl;
		}
		//cout << "Dominance check" << endl;
	}
	fin.close(); 
	cout << "File closed" << endl;

	dlist<Swatch> copy(swatches); // make a copy
	
	// remove the front, back, and centermost swatch from the copy
	copy.front_remove(); 
	copy.rear_remove(); 
	it = copy.begin();
	//cout << "Removes" << endl;
	for(int i =0; i < copy.size()/2; ++i)
		++it;
	//if(copy.size()%2 ==1) ++it; // if list has a true middle
					// step up into it
	copy.remove(it);
	//cout<<"Removes2"<<endl;
	
	
	// output the original list frontwards
	for (dlist<Swatch>::iterator i=swatches.begin(); i != swatches.end(); ++i)
	{
		cout << *i << endl; 
	}
	//cout<<"output1"<<endl<<endl<<endl;
	
	cout << endl << endl; // some space
	
	// output the copy frontwards
	for (dlist<Swatch>::iterator i=copy.begin(); i != copy.end(); ++i)
	{
		cout << *i << endl; 
	}
	//cout<<"output2"<<endl<<endl<<endl;

	cout << endl << endl; // some space

	// output the original backwards
	for (dlist<Swatch>::iterator i=swatches.r_begin(); i != swatches.r_end(); --i)
	{
		cout << *i << endl; 
	}
	
	//cout<<"output3"<<endl<<endl<<endl;
	cout << endl << endl; // some space

	// destroy the original list by alternating between removal of first and 
	// last items.  Print each item as it is removed
	int counter=0; 
	while (swatches.size() > 0)
	{
		//cout<<swatches.size()<<endl;
		cout<<*swatches.begin()<<endl;
		//cout<<"begin success"<<endl;
		swatches.front_remove();
		//cout<<swatches.size()<<" + 2"<<endl;
		if(swatches.size() > 0){
		    cout<<*swatches.r_begin()<<endl;
		    swatches.rear_remove();
			
		}

	}
	//cout<<"destruction"<<endl<<endl<<endl;

	cout << endl << endl; // some space

	// output the copy backwards
	for (dlist<Swatch>::iterator i=copy.r_begin(); i != copy.r_end(); --i)
	{
		cout << *i << endl; 
	}
	
	//cout << "enter any character to exit" << endl;
	cin >> trash;

	return 0; 
}

