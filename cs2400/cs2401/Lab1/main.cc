/******************************************************
   A primitive main solution for lab2 - cs2401
*****************************************************/
#include<iostream>
#include<fstream>
#include <string>
#include "numlist.h"
using namespace std;

int main(){

     char trash;

     NumList num1;
     int tmp;
     ifstream ifs;
     string filename;
     cout<<"Please enter the name of your number file.\n";
     cin>>filename;
     ifs.open(filename.c_str());
     if(ifs.fail()){
	cout<<"Input file failed to open.\n";
     cout << "enter any character to exit." << endl;
     cin >> trash;
	return -1;
     }
     num1.load_from_file(ifs);
     ifs.close();
     num1.see_all();
     cout << "the current size is " << num1.size() << endl;
     cout<<"Please enter three numbers to add to the list.\n";
     cin>>tmp;
     num1.insert(tmp); //1
     cin>>tmp;
     num1.insert(tmp); //2
     cin>>tmp;
     num1.insert(tmp); //3
     num1.see_all();
     cout << "the current size is " << num1.size() << endl;
     num1.b_sort();
     cout << "reached end of sort" << endl;
     num1.see_all();
     cout << "reached end of see all" << endl;
// here you will use the find function to find the . in the filename
// immediately before the . you will insert the word "sorted"
// the filename will now be changed so the following will save to the new 
// name -- this only takes two or three lines of code

     int dotIndex = filename.find('.');
     filename.insert(dotIndex, "sorted");
     cout << filename << endl;
     cin >> trash;

     ofstream ofs(filename.c_str());
     num1.save_to_file(ofs);
     ofs.close();
     cout << "complete" << endl;
     cin >> trash;

return 0;
}


