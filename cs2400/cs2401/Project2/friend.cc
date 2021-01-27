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
    string day;
    string month;
    string year;
    if(ins.peek() == '\n'){
        ins.ignore();
    }
    cout << "Please enter the friend's name." << endl;
    getline(ins, toName, '\n');
    if(ins.peek() == '\n'){
        ins.ignore();
    }
    cout << "Please enter the month. And put a / after it because something's wack." << endl;
    getline(ins, month, '/');
    if(ins.peek() == '/'){
        ins.ignore();
    }
    if(ins.peek() == '\n'){
        ins.ignore();
    }
    cout << "Please enter the day. And put a / after it because something's wack." << endl;
    getline(ins, day, '/');
    if(ins.peek() == '/'){
        ins.ignore();
    }
    if(ins.peek() == '\n'){
        ins.ignore();
    }
    cout << "Please enter the year." << endl;
    getline(ins, year, '\n');
    if(ins.peek() == '\n'){
        ins.ignore();
    }
    cout << toName << endl;
    cout << day << endl;
    cout << month << endl;
    cout << year << endl;
    int dayString = stoi(day);
    //cout << "did the day" << endl;
    int monthString = stoi(month);
    //cout << "did the month" << endl;
    int yearString = stoi(year);
    //cout << "did the year" << endl;
    name = toName;
    Date toBday(dayString, monthString, yearString);
    bday = toBday;
    cout << "You entered " << name << " who was born on "<< bday << endl;
}

void Friend::output(ostream& outs)const{
    outs << name << endl;
    outs << bday << endl;

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