#include "othello.h"
#include "colors.h"
#include <iostream>
//#include "game.h"

using namespace std;

void Othello::display_status()const{
    cout << "The current state of the board:" <<endl<< " A  B  C  D  E  F  G  H  " << endl<< "------------------------" << endl;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << " ";
            if(theBoard[i][j].getState() == 'E'){
                cout<<"| ";

            }else if(theBoard[i][j].getState() == 'B'){
                cout << "B ";

            }else if(theBoard[i][j].getState() == 'W'){
                cout << "W ";

            }
        }
        cout<<"    " << i+1<<endl<<endl;
    }
    
}

void Othello::restart(){
    theBoard[3][3].pblack();
    theBoard[4][4].pblack();
    theBoard[3][4].pwhite();
    theBoard[4][3].pwhite();
    }

/*void Othello::make_move(){
    if()
}*/