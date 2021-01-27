/** 
Implementation of the Ward class, which stores a bunch of Households.
*/ 

#include<iostream>
#include<string>
#include<fstream>

#include "household.h"
#include "ward.h" 

using namespace std;


/////////////////////////////////////Constructor
Ward::Ward(){
    occupied = 0;
}


/////////////////////////////////////ArrayManip
void Ward::add(Household& h){
    if(occupied < size){
        occupied++;
        Neigh[occupied - 1] = h;
    }else{
        cout << "This neighborhood is full!" << endl;
    }   
}
    

void Ward::remove(string toEnd){
    string searched;
    int index = -1;
    for(int i = 0; i < occupied; i++){
        searched = Neigh[i].get_head();
        if(searched.find(toEnd) != string::npos){
            index = i;
            for(int j = index; j < occupied; j++){
            Neigh[j] = Neigh[j + 1];
            }
             occupied--;
            break;
        }
    }
   
    }


///////////////////////////////////////////Save/Load

void Ward::save(ostream& outs){
    for(int i = 0; i < occupied; i++){
        outs << Neigh[i].get_head() << endl;
        outs << Neigh[i].get_address() << endl;
        outs << Neigh[i].get_occupants() << endl;
        outs << Neigh[i].get_income() << endl;
    }
}


void Ward::load(istream& ins){
    while(!ins.eof()){
        Household h;
        h.input(ins);
        if(ins.peek() == '\n' || ins.peek() == '\r'){
		    ins.ignore();
        } 
        cout << h;
        add(h);
    }
}


//////////////////////////////////////////Search/Find

Household Ward::find(string target){
    string searched;
    for(int i = 0; i < occupied; i++){
        searched = Neigh[i].get_head();
        if(searched.find(target) != string::npos){
            return Neigh[i];
        }  
    }
    cout << "There was no household with a head of that name." << endl;
    Household bad;                                                            ///find a better way to do this.
    return bad;
}

int Ward::display_richest(){
    int big_income = Neigh[0].get_income();
    int index = 0;
    for(int i = 1; i < occupied; i++){
        if(big_income < Neigh[i].get_income()){
            index = i;
        }
    }
    Neigh[index].output(cout);
    return index;
}


//////////////////////////////////////////Print/Find

void Ward::display(ostream& outs){
    for(int i = 0; i < occupied; i++){
        //cout << "This should output one." << endl;
        Neigh[i].output(cout);
    }

}

int Ward::display_avg_income(){
    int total = 0;
    int add = 0;
    int count = 0;
    int average = 0;
    for(int i = 0; i < occupied; i++){
        add = Neigh[i].get_income();
        total += add;
        count++;
    }
    average = total / count;
    cout << "The average income is $" << average << "." << endl;
    return average;


}

int Ward::display_avg_people(){
    int total = 0;
    int add = 0; 
    int count = 0;
    int average = 0;
    for(int i = 0; i < occupied; i++){
        add = Neigh[i].get_occupants();
        total += add; 
        count++;
    }
    average = total / count;
    cout << "The average occupancy is " << average << " people." << endl;
    return average;

}


////////////////////////////////////////////Sorting

void Ward::sort_by_income(){
    bool complete = false;
    Household hold;
    while(!complete){
        complete = true;
        for(int i = occupied - 1; i >= 0; i--){
            if(Neigh[i].get_income() < Neigh[i-1].get_income()){
                complete = false;
                hold = Neigh[i];
                Neigh[i] = Neigh[i - 1];
                Neigh[i - 1] = hold;
            }
        }
    }
}

void Ward::sort_by_name(){
    bool complete = false;
    string first_string;
    string second_string;

    Household hold;

   // string first_char;
   // string second_char;

    while(!complete){
        complete = true;
        for(int i = occupied - 1; i > 0; i--){
           // cout << "check " << i << " and " << i - 1 << endl;
            first_string = Neigh[i].get_head();
           // cout << "test" << endl;
            second_string = Neigh[i-1].get_head();
            //cout << "test" << endl;
            //cout << first_string << " and " << second_string << endl;
           // int newtest = toupper(first_string.at(1));
            //cout << newtest << endl;
           // first_char = first_string.at(1);
            //second_char = second_string.at(1);
            //cout << toupper(first_char) << " and " << toupper(second_char) << endl;
           // cout << first_string.at(0) << " and " << second_string.at(0) << endl;
            if(first_string.at(0) < second_string.at(0)){
                //cout << "a switch" << endl;
                complete = false;
                hold = Neigh[i];
                Neigh[i] = Neigh[i - 1];
                Neigh[i - 1] = hold;
            }
        }
    }
}
