//uses a queue to sort through items

#include "item.h"
#include <queue>
using namespace std;

int main(){
    //Chore i;
    //Chore j;
    char trash;
    Chore temp;
    int used = 0;
    //bool test;

    priority_queue<Chore> theQueue;

   for(int i = 0; i < 5; i++){
       temp.input();
       theQueue.push(temp);
       used++;
   }

   for(int i = 0; i < used; i++){
       theQueue.top().output();
       theQueue.pop();
   }

    //test = i < j;
    //cout << test << endl;

    cout << "Enter any character to exit." << endl;
    cin >> trash;
}