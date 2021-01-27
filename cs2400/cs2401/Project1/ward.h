/** 
This class contains an array of various Household objects
*/

#include<iostream>
#include<string>
#include<fstream>
#include "household.h"
#ifndef WARD_H
#define WARD_H

using namespace std;

    class Ward{
        public:
            Ward();                                      

            void add(Household& h);
            //Function: add
            //Adds a household to the array
            //@param h - the object added to the array
            void remove(string toEnd);          
            //Function: remove
            //Removes a household from the array
            //@Param toEnd - the name that is searched for to find the object to be removed

            void save(ostream& outs);
            //Function: save
            //Saves stored information when ending the program
            //@Param outs - the file that will be saved to
            void load(istream& ins);
            //Function: load
            //Loads information from a file when starting the program
            //@Param ins - the file that will be taken from

            Household find(string target);
            //Function: find
            //displayes information on a household
            //@Param target - the name that will be searched for in house heads to find the file
            int display_richest();
            //Function: display_richest
            //Displays household information on richest household
            

            void display(ostream& outs);
            //Function: display
            //prints all house information
            //@Param outs - where it will be printed
            int display_avg_income();
            //Function: display_avg_income
            //Displays the average income of all houses
            int display_avg_people();
            //Function: display_avg_people
            //displays average house population

            void sort_by_income();
            //Function: sort_by_income
            //sorts objects from smallest to highest income
            void sort_by_name();
            //Function: sort_by_name
            //sorts objects by alphabetical order

        private:
            Household Neigh[200];
            static const int size = 200;
            int occupied;

    };



#endif