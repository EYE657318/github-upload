#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "friend.h"

using namespace std;

int main(){
    char trash;

    Friend test;
    cout << "Friend 1:" << endl;
    cout << test;

    cin >> test;
    cout << test;

    Friend test2;
    cout << "Friend 2:" << endl;;
    cout << test2;
    
    cin >> test2;
    cout << test2;

    if(test == test2){
        cout << "The friends are the same." << endl;
    }

    if(test != test2){
        cout << "The friends are not the same." << endl;
    }

    cout << "Enter any character to exit." << endl;
    cin >> trash;

}