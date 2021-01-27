#include<iostream>
#include<string>
#include<fstream>
#include "friend.h"
#include "fbfriends.h"

using namespace std;

/////////////////////////////////////Default Constructor
FBFriends::FBFriends(){              //array of five friends
data = new unsigned long[5];
used = 0;
capacity = 5;
current_index = 0;
}


///////////////////////////////////////Big Three
FBFriends::~FBFriends(){
    delete [] data;
    cout << "Get out >:(" << endl;
}

FBFriends::FBFriends(const FBFriends& other){
    data = new unsigned long[5];
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    copy(other.data, other.data + used, data);
}

void FBFriends::operator = (const FBFriends& other){
    if(&other == this){
        return;    
    }
    unsigned long *temp;
        temp = new unsigned long[capacity];
        used = other.used;
        copy(other.data, other.data + used, temp);
        delete [] data;
        data = temp;
}


//////////////////////////////////////// sequence class allows application programmer to choose order
void FBFriends::start(){  //puts iterator at beginning, 0
current_index = 0;
cout << "Index set to start." << endl;

}

void FBFriends::advance(){ //increases iterator by 1
current_index++;
cout << "The index is now set to friend #" << current_index + 1 << endl;

}

bool FBFriends::is_item(){  //returns true if iterator is a valid item (if it's within the used)
    return (current_index < used);
}

Friend FBFriends::current(){  //returns friend at current location
    return data[current_index];

}


//////////////////////////////////////////////////actually editing the array
void FBFriends::remove_current(){       //removes selected, pulls others back
    for(size_t i = 0; i < used; i++){
        data[i] = data[i+1];
    }
    used--;
}

void FBFriends::insert(const Friend& f){   //add to current location
    for(size_t i = used; i > current_index; i++){
            if(used == capacity){
                resize();
            }
            data[i] = data[i - 1];
    }
    data[current_index] = f;

}

void FBFriends::attach(const Friend& f){      //adds after current location? 14:00-ish in the video
    for(size_t i = used; i > current_index + 1; i++){
        if(used == capacity){
            resize();
        }
        data[i] = data[i - 1];
    }
    data[current_index + 1] = f;
}


void FBFriends::bday_sort(){                                        //data[i].get_bday() < data[i+1].getbday()
    bool finished = false;
    Friend temp;
    while(!finished){
        finished = true;
        for(size_t i = used - 1; i > 0; i--){
            Friend datai = data[i];
            Friend dataiminus = data[i - 1];
            if(data[i].get_bday() < data[i - 1].get_bday()){
                finished = false;
                temp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////searching/printing
void FBFriends::show_all(std::ostream& outs)const{    //display
    for(size_t i = 0; i < used; i++){
        outs << data[i] << endl;
    }

}

Friend FBFriends::find_friend(const std::string& name)const{         //search for string, return the friend
    for(size_t i = 0; i < used; i++){
        string searching = data[i].get_name();
        if(searching.find(name) > 0 && searching.find(name) < string::npos){
            return data[i];
        }
    }
    Friend junk;
    return junk;
}
 
bool FBFriends::is_friend(const Friend& f) const{        //tests if they are in list
    for(size_t i = 0; i < used; i++){
        if(data[i] == f){
            return true;
        }
    }
    cout << "No such friend found." << endl;
    return false;    
}

//////////////////////////////////////////////////////////////////////////////files
void FBFriends::load(std::istream& ins){             //load le file
    string toName;
    string toMonth;
    string toDay;
    string toYear;
    while(!ins.eof()){
        getline(ins, toName, '\n');
        if(ins.peek() == '\n'){
            ins.ignore();
        }
        getline(ins, toMonth, '/');
        getline(ins, toDay, '/');
        getline(ins, toYear, '\n');
        if(ins.peek() == '\n'){
            ins.ignore();
        }
        
    }

}

void FBFriends::save(std::ostream& outs){           //save to le file
    for(size_t i = 0; i < used; i++){
        outs << data[i];
    }
}


//////////////////////////////////////////////resizer
void FBFriends::resize(){          //the resizer
    unsigned long *temp;
    temp = new unsigned long[capacity+5];
    copy(data, data + used, temp);
    delete [] data;
    capacity += 5;
    data = temp;
}