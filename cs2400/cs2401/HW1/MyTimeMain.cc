// The main for MyTime
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;


int main(){

    MyTime test;
    MyTime test2;
    int trash;

    cout << "Please enter the number of hours, then the number of minutes." << endl;
    cin >> test;
    cout << test;

    cout << "Now do it again." << endl;
    cin >> test2;
    cout << test2;

    cout << "Now, we math." << endl;

    cout << "Addition of the times;   ";
    cout << test + test2;
    cout << "Subtraction of the times;   ";
    cout << test - test2;
    cout << "Multiplying the first by 2;  ";
    cout << test * 2; 
    cout << "Divising the first by 2;   ";
    cout << test / 2;
    
    if(test == test2){
        cout << "The entries are equal to eachother." << endl;
    }else{
        cout << "The entries are not equal." << endl;
    }

    if(test < test2){
        cout << "The first entry is less than the second entry." << endl;
    }else{
        cout << "The first entry is not less than the second entry." << endl;
    }

    if(test <= test2){
        cout << "The first entry is less than or equal to the second entry." << endl;
    }else{
        cout << "The first entry is not less than or equal to the second entry" << endl;
    }

    cout << "Please enter any character to exit." << endl;
    cin >> trash;
}

