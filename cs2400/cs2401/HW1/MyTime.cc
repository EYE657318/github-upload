// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructors
/*MyTime::MyTime(){
	hours = 0;
	minutes = 0;
}*/                //Vestigal

MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::simplify(){
       	hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t2){
	MyTime tmp;
    tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t2){
	MyTime tmp;
	tmp.minutes = abs((hours*60+minutes) - 
					(t2.hours*60+t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num){
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num){
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t2){
	return hours == t2.hours && minutes == t2.minutes;
}

bool MyTime::operator < (const MyTime& t2){
	return (hours*60 + minutes) < (t2.hours*60 + t2.minutes);
}

bool MyTime::operator <=(const MyTime& t2){
	return (hours*60 + minutes) <= (t2.hours*60 + t2.minutes);
}

istream& MyTime::input(istream&ins){
       // Here you are to copy the implementation code from the >> operator shown below
	// remember to that variables will be local here - so no referene to t1
       //Then you can have the >> operator call this function.
      // In the .h file remove the word friend for the operator and move its prototype to a spot
      // under the class declaration
	  char junk;
	ins>>hours;
  	ins.get(junk);
	ins>>minutes;
	simplify();
	return ins;
}

ostream& MyTime::output(ostream& outs) const{
	// Do the same thing a you did for the function above except using the code for the << 
	//operator
	outs<<hours<<':'<<setw(2)<<setfill('0')<<minutes<<endl;
	return outs;
}



ostream& operator <<(ostream& outs, const MyTime& t1){
        //outs<<t1.hours<<':'<<setw(2)<<setfill('0')<<t1.minutes;
		t1.output(outs);
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	/*char junk;
	ins>>t1.hours;
  	ins.get(junk);
	ins>>t1.minutes;
	t1.simplify();
	return ins; */
	t1.input(ins);
	return ins;
;}

