/*
 *        File: grade-frequencies.cc
 *      Author: Isaac Phillips
 *        Date: 06/02/2020
 * Description: List them grades.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>



char getGrade (double score); //prototype. takes score and determines letter grade.
void printGrade(double score, char grade);  //prototype. lists score and grade.
void printFrequencies(int aCount, int bCount, int cCount, int dCount, int fCount); //lists number of each grade
void raiseFrequency(char currentGrade, int &aCount, int &bCount, int &cCount, int &dCount, int &fCount); //raises the frequency

using namespace std;

int main() {

    cout << setprecision(1) << fixed; //output format


    double score; //the score
    char currentGrade; //for printing current grade
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;  //frequencies
    int trash; //for exiting the program

    cout << "Please enter a score." << endl;         //enter the first score
    cin >> score;

    

    while (score >= 0) {
        currentGrade = getGrade(score);
        printGrade(score, currentGrade);    //print score, find and print letter grade
        raiseFrequency(currentGrade, aCount, bCount, cCount, dCount, fCount);
        cout << "Please enter another score. Enter a negative to stop." << endl;      //enter another
        cin >> score;
    }

    printFrequencies(aCount, bCount, cCount, dCount, fCount); //prints frequencies

    cout << "Enter any character to exit." << endl; //exits program
    cin >> trash;


}

char getGrade (double score) {
    
    if (score >= 90) {  //counts as 'A'
        return 'A';
    }
    
    if (score >= 80) {  //'B'
        return 'B';
    }

    if (score >= 70) {  //'C'
        return 'C';
    }

    if (score >= 60) {   //'D'
        return 'D';
    }

    if (score >= 0) {   //'F'
        return 'F';
    }

    return 'E';

    } 
     
void printGrade(double score, char currentGrade){

    cout << "Score: " << score << ", Grade: " << currentGrade << "." << endl;  //prints score and letter

}

void printFrequencies(int aCount, int bCount, int cCount, int dCount, int fCount){       //prints all letter frequencies

    cout << "Grade    Frequency" << endl;
    cout << "------------------" << endl;
    cout << "A             " << aCount << endl;
    cout << "B             " << bCount << endl;
    cout << "C             " << cCount << endl;
    cout << "D             " << dCount << endl;
    cout << "F             " << fCount << endl;
}

void raiseFrequency(char currentGrade, int &aCount, int &bCount, int &cCount, int &dCount, int &fCount){ //determine grade, then add to frequency
    switch(currentGrade){
        case 'A':
            aCount++;
            break;

        case 'B':
            bCount++;
            break;

        case 'C':
            cCount++;
            break;
        
        case 'D':
            dCount++;
            break;

        case 'F':
            fCount++;
            break;

    
    }
} 
