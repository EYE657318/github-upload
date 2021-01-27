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
    string animaltype;
    Animal* temp;
    dlist<Animal*> animals;
    Animal* test;
    bool breaker = false;
    bool breaker2 = false;


    fins.open("record.txt");
    if(fins.fail()){cout << "There was a problem opening the file" << endl;
        return 1;}

    while(!fins.eof()){
        fins >> animaltype;
            if(animaltype == "ant"){
                temp = new Ant;}
            if(animaltype == "monkfish"){
                temp = new Monkfish;}
            if(animaltype == "materialrabbit"){
                temp = new GemRabbit;}
            if(animaltype == "scarab"){
                temp = new Scarab;}
            if(animaltype == "blink"){
                temp = new BlinkDog;}
            if(animaltype == "auroch"){
                temp = new Auroch;}
        
        temp -> input(fins);
        animals.rear_insert(temp);
        if(fins.peek() == '\n'){fins.ignore();}
        
    }

    cout << endl << endl << "LOADING HAPPENED" << endl << endl;    

    choice = menu();
    cout << "CHOICE: " << choice << endl;
    while(choice != 8){
        switch(choice){
            case 1:
                temp = new Ant;
                cout << "e" << endl;
                break;
            case 2:
                temp = new Monkfish;
                break;
            case 3:
                temp = new GemRabbit;
                break;
            case 4:
                temp = new Scarab;
                break;
            case 5:
                temp = new BlinkDog;
                break;
            case 6:
                temp = new Auroch;
                break;
            case 7:
                for(dlist<Animal*>::iterator i = animals.begin(); i!= animals.end(); ++i){
                    test = *i;
                    test -> output(cout);
                    cout << endl << endl;
                }
                //temp = NULL;
                breaker2 = true;
                //cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
                break;

            default:
                breaker = true;
                break;

        }
        if(breaker == true){
            break;
        }
        if(breaker2 == false ){
        temp -> input(cin);
        animals.rear_insert(temp);
        }else{
            breaker2 = false;
        }
        choice = menu();
    }

    //dlist<Animal*>::iterator i = animals.begin();
    
    //test -> output(cout);

    

    /*Ant A;
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

    fouts.close();*/
    fouts.open("record.txt");

    for(dlist<Animal*>::iterator i = animals.begin(); i!= animals.end(); ++i){
                    test = *i;
                    test -> output(fouts);
    }
    fouts.close();

    cout << endl << endl << endl;
    cout << "Ignore all of that, it means it's working." << endl;
    cout << endl << endl;

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
    cout << "7) Print all entries." << endl;
    cout << "8) Exit the program and save to file." << endl;
    cin >> thischoice;
    return thischoice;
}