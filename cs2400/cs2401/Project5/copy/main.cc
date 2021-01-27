#include <iostream>
#include "animals.h"

using namespace std;

int menu();

int main(){
    char trash;

    int choice;

    Ant A;
    Monkfish M;
    GemRabbit G;
    Scarab S;
    Blinkdog B;
    Auroch U;

    cout << "Enter any character to exit." << endl;
    cin >> trash;
    return 0;


    

}




int menu(){
    cout << "Please enter your choice." << endl;
    cout << "1) Create the habitat for an ant colony." << endl;
    cout << "2) Create the habitat for a monkfish." << endl;
    cout << "3) Create the habitat for an artificial rabbit." << endl;
    cout << "4) Create the habitat for a scarab." << endl;
    cout << "5) Create the habitat for a blink dog." << endl;
    cout << "6) Create the habitat for a herd of aurochs." << endl;
    cout << "7) Exit the program and save to file." << endl;
    cin >> choice;
    return choice;
}