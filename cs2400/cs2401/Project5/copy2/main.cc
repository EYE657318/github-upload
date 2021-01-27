#include <iostream>
#include <fstream>
#include "animals.h"
#include "dlist.h"

using namespace std;

int menu();

int main(){
    char trash;

    int choice;
    ifstream fins;
    ofstream fouts;

    fins.open("record.txt")
    if(fin.fail()){
        cout << "There was a problem opening the file" << endl;
        return 1;
    }

    Ant A;
    Monkfish M;
    GemRabbit G;
    Scarab S;
    BlinkDog B;
    Auroch U;

    A.input(cin);
    A.output(cout);

    M.input(cin);
    M.output(cout);

    G.input(cin);
    G.output(cout);

    S.input(cin);
    S.output(cout);

    B.input(cin);
    B.output(cout);

    U.input(cin);
    U.output(cout);    

    fouts.open("record.txt");
    A.output(fouts);
    M.output(fouts);
    G.output(fouts);
    S.output(fouts);
    B.output(fouts);
    U.output(fouts);

    fouts.close();

    cout << "Enter any character to exit." << endl;
    cin >> trash;
    return 0;


    

}




int menu(){
    int thischoice;
    cout << "Please enter your choice." << endl;
    cout << "1) Create the habitat for an ant colony." << endl;
    cout << "2) Create the habitat for a monkfish." << endl;
    cout << "3) Create the habitat for an artificial rabbit." << endl;
    cout << "4) Create the habitat for a scarab." << endl;
    cout << "5) Create the habitat for a blink dog." << endl;
    cout << "6) Create the habitat for a herd of aurochs." << endl;
    cout << "7) Exit the program and save to file." << endl;
    cin >> thischoice;
    return thischoice;
}