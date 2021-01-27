#include <iostream>

using namespace std;

class Chore{
    public:
    Chore(){description = "No description given."; priority = 0;}
    void input(){cout << "Enter a description." << endl; getline(cin, description); cout << "Enter the priority" << endl; cin >> priority; if(cin.peek()== '\n'){cin.ignore();};}
    void output()const{cout << "Chore: " << description << endl << "Priority: " << priority << endl;}
    bool operator <(Chore i)const{return priority < i.priority;}

    private:
    string description;
    int priority;

};