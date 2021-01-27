//Isaac Phillips

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//prototypes
void pretty();

int main(){
    int trash;

    for(int j = 0; j < 6; j++){
        pretty();
    }

    cout << "Enter any character to exit." << endl;
    cin >> trash;
}



//definitions
void pretty(){
    //static 
    int x = 0;
    x++;
    //cout << x;
    for(int i = 0; i < x; i++){
        cout << '*';
    }
    cout << endl;
}