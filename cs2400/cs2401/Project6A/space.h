#ifndef SPACE_H
#define SPACE_H

using namespace std; 

class Space{

public:
Space(){state = 'E';}

//mutators
void flip(){
    if (state == 'B'){
        pwhite();
    }else if(state == 'W'){
        pblack();
    }
}
void pblack(){
    state = 'B';
}
void pwhite(){
    state = 'W';
}

//accessors
char getState()const{return state;};

private:
char state; //E for Empty, B for Black, W for White

};

#endif