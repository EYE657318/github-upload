/*****************************************************
This is a sample of what the main should like for the first phase of the
Mancala game.
	John Dolan	Ohio University		Spring 2019
*************************************************************/


///FIRST PROJECT GOALS
///Design the board
///Display the board
///Enter one move



#include<iostream>
#include "othello.h"
#include "colors.h"
using namespace std;
using namespace main_savitch_14;


int main(){
    char trash;
    Othello reversi;
    cout<<BLUE<<"I like cookies" <<endl;
   reversi.play();


    cout << "Please enter any character to exit." << endl;
    cin >> trash;
return 0;
}
