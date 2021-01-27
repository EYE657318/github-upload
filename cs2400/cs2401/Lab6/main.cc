#include <string>
#include <iostream>
using namespace std;


void counting(int n);
void reversing(string &s, int start, int end);

int main(){
    char trash;

    //main for part 1
    int x;
    for(int i = 0; i < 3; ++i){
        cout << "Enter a number: ";
        cin >> x;
        cout << "The even numbers counting to there: \n";
        counting(x);
    }
    //main for part 2

    string s;
    int start, end;
    cout << "Enter a string:";
    if(cin.peek() == '\n'){
        cin.ignore();
    }
    getline(cin, s);
    cout << "Now enter two numbers that are within the bounds of the string.";
    cin >> start >> end;
    cout << "This is how your words look now:\n";
    reversing(s, start, end);
    cout << s << endl;

    cout << "Enter any character to exit. ";
    cin >> trash;
    return 0;
}

void counting(int n){
    if(n <= 0){
        return;
    }
    counting(n - 1);
    if(n % 2 == 0){
        cout << n << " ";
    }
}

void reversing(string &s, int start, int end){
    if(end <= start){
        return;
    }
    //cout << "e" << endl;
    reversing(s, start + 1, end - 1);
    char s2 = s[start];
    //out <<"char: " << s2 << " that's it" << endl;
  
   
    s[start] = s[end];
     //cout <<"start: " << s[start] << endl;

    s[end] = s2;
    //cout << "end: " << s[end] << endl;

}