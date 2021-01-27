/* Implementation of the Friend class
By Isaac Phillips */

#include<iostream>
#include<string>
#include "date.h"
#include "friend.h"

using namespace std;


//////////////////////////////////     Constructor
Friend::Friend(){
    name = "Anonymous";
    Date tob; 
    bday = tob;
}


/////////////////////////////////////        Getters
string Friend::get_name()const{
    return name;
} 

Date Friend::get_bday()const{
    return bday;
}

///////////////////////////////////////        I/O
void Friend::input(istream& ins){
    string toName;
    int day;
    int month;
    int year;
    cout << "Please enter the friend's name." << endl;
    ins >> toName;
    cout << "Please enter the day." << endl;
    ins >> day;
    cout << "Please enter the month." << endl;
    ins >> month;
    cout << "Please enter the year." << endl;
    ins >> year;
    Date toBday(day, month, year);
    name = toName;
    bday = toBday;
}

void Friend::output(ostream& outs)const{
    outs << name << " was born on "<< bday << "." << endl;
}

/////////////////////////////////////////////////// Operators
bool Friend::operator == (const Friend& other)const{
    //Date date1 = get_bday();
    //Date date2 = other.get_bday();

    //return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
    return(bday == other.bday && name == other.name);

}

bool Friend::operator != (const Friend& other)const{
    //Date date1 = get_bday();
    //Date date2 = other.get_bday();

    //return (date1.day != date2.day || date1.month != date2.month || date1.year != date2.year);
    return(bday != other.bday || name != other.name);

}

///////////////////////////////////////////////////////////   nonmember operators
istream& operator >> (istream& ins, Friend& f){
    f.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, const Friend& f){
    f.output(outs);
    return outs;
}