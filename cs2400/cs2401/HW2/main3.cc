//Isaac Phillips

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    size_t used = 0;
    size_t capacity = 5;
    int* ptr; 
    int* tmpptr;
    int trash;

    ptr = new int[capacity];
    for(size_t i = 0; i < 25; i++){
        ptr[used] = rand();
        cout << ptr[used] << endl;          //comment?
        used++;
        if(used == capacity){
            tmpptr = new int[capacity+5];
            for(size_t i = 0; i < used; i++){
                tmpptr[i] = ptr[i];
            }
            capacity +=5;
            delete []ptr;
            ptr = tmpptr;
            cout << "Resized\n";
        }
    }

    tmpptr[2] = 0;
    for(size_t i = 0; i < used; i++){
        cout << ptr[i] << endl;
    }



    

    cout << "Enter any character to exit." << endl;
    cin >> trash;
}