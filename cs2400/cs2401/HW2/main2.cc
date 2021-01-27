//Isaac Phillips

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int trash;

    int* ptr;
    ptr = new int;
    cout << ptr << endl;
    cout << &ptr << endl;
    *ptr = 2401;
    for(int i = 0; i < 10; i++){
        (ptr)++;
        cout << *ptr << " is stored at " << ptr << endl;
    }
    cout << "Enter any character to exit." << endl;
    cin >> trash;

}