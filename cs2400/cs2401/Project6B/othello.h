#ifndef OTHELLO_H
#define OTHELLO_H

#include "game.h"
#include "space.h"
using namespace main_savitch_14;

class Othello:public game{

public:
Othello(){}
~Othello(){}
//void play(){display_status();}

protected:
//must override makemove, which does the flipping, then call the parent function
//moves are strings
//there's a function that gets the move?

//must override restart, which does ???

void display_status()const;
//implement the parent functions later
bool is_legal(const std::string& move)const{
        if(move == "D6" || move == "C5" || move == "E3" || move == "F4"){
                return true;}
        return false;}
void make_move(const std::string& move){
        if(move == "D6"){theBoard[4][3].flip(); theBoard[5][3].pblack();}
        if(move == "C5"){theBoard[4][3].flip();theBoard[4][2].pblack();}
        if(move == "E3"){theBoard[3][4].flip();theBoard[2][4].pblack();}
        if(move == "F4"){theBoard[3][4].flip();theBoard[3][5].pblack();}
        
}
void restart();



//display status somewhere, but where?
//stored and displayed differently
//can use colors.h

//is_legal
//for right now, just check for specific spaces, checking all the rules comes later

//makemove also gets to be simplified     -----
//                                                ]-------call parent functions
//restart sets up initial board           -----

private:
Space theBoard[8][8];
        //the 2D array [row]][column]    both 0-7
        //for (j = 0, j < 8)
        //for (i = 0, i < 8)
        //board[j][i]         this can check the entire board

};



/*strings: 
A becomes 0, 3 becomes 2

row = int(move[0] - 'A')            move[0] is the first character (the letter)
B - A
will probably want to toupper the letter

col = int(move[1] - '1')             move[1] is the second character (the number)*/

#endif