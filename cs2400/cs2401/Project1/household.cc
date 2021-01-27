/** 
Implementation of the Household class, which stores the information on one household.
*/ 

#include<iostream>
#include<string>
#include<fstream>

#include "household.h" 

using namespace std;


//////////////////////////////////////////////////////constructor
Household::Household(){

    house_head = "DOES NOT EXIST";
    address = "somewhere on Jupiter";
    occupants = 0;
    income = -99999999;
}

////////////////////////////////////////////////////////getters
string Household::get_head()const{
    return house_head;
}

string Household::get_address()const{
    return address;
}

int Household::get_occupants()const{
    return occupants;
}

int Household::get_income()const{
    return income;
}

///////////////////////////////////////////////////////setters
void Household::set_head(const string& hd){
    house_head = hd;
}

void Household::set_address(const string& add){
    address = add;
}

void Household::set_occupants(int num){
    occupants = num;
}

void Household::set_income(int inc){
    income = inc;
}

/////////////////////////////////////////////////////io
void Household::input(istream& ins){
    //int trash;
    cout << "Enter the head's name." << endl;
    getline(ins, house_head);
    if(ins.peek() == '\n' || ins.peek() == '\r'){
		ins.ignore();
    }
    //ins.get(trash);
    cout << "Enter the address." << endl;
    getline(ins, address);
    if(ins.peek() == '\n' || ins.peek() == '\r'){
		ins.ignore();
    }
    //ins.get(trash);
    cout << "Enter the number of occupants." << endl;
    ins >> occupants;
    if(ins.peek() == '\n' || ins.peek() == '\r'){
		ins.ignore();
    }
    //ins.get(trash);
    cout << "Enter the total household income." << endl;
    ins >> income;
    if(ins.peek() == '\n' || ins.peek() == '\r'){
		ins.ignore();
    }
    //ins.get(trash);
}

void Household::output(ostream& out)const{
    out << house_head << " is the name of the head of " << address << ". It has " << occupants << " occupants, and the total household income is $" << income << "." << endl;
}

istream& operator >> (istream& ins, Household& h){
    h.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, const Household& h){
    h.output(outs);
    return outs;
}