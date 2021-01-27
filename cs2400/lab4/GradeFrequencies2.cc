/*
 *        File: GradeFrequencies2.cc
 *      Author: Isaac Phillips
 *        Date: 06/09/2020
 * Description: List grade inputs, but this time from and to a file.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

char getGrade(double score); //prototype, finds letter grade
void printGrade(ofstream &outFile, double score, char grade); //prototype, prints grade number and letter
void printFrequencies(ofstream &outFile, int aCount, int bCount, int cCount, int dCount, int fCount); //prototype, prints quantity of each letter grade
void raiseFrequency(char grade, int &aCount, int &bCount, int &cCount, int &dCount, int &fCount); //prototype, add to the count per letter grade


int main() {



    cout << setprecision(1) << fixed; //output format

    int trash; //exit program
    double score;  //the test score
    string inputName;  //name of input stream
    char grade; //the letter grade
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0; //frequencies of letter grades
    ifstream inFile; //the input stream
    ofstream outFile; //the output stream

    

    outFile.open("scores.txt");  //opens output stream
        if(outFile.fail()){         //if fails
            cout << "There was a problem opening the output file." << endl;
            cout << "Enter any character to exit." << endl;
            cin >> trash;
            return 0;
        }
    cout << "Please enter the name of the file you wish to pull grades from." << endl;  //user enters input
    cin >> inputName;
    inFile.open(inputName);
        if(inFile.fail()){ //if fails
            cout << "There was a problem opening " << inputName << ". Enter any character to exit." << endl;
            cin >> trash;
            return 0;
        }

    cout << "You have designated " << inputName << " as your input file." << endl;  //confirmation
    
    

    do{
        inFile >> score;      //enters next score on file
        grade = getGrade(score); //turns into letter grade
        printGrade(outFile, score, grade);    //prints information to file
        raiseFrequency(grade, aCount, bCount, cCount, dCount, fCount);  //updates frequencies
        
    } while (!inFile.eof()); //until file is complete

    printFrequencies(outFile, aCount, bCount, cCount, dCount, fCount);  //posts all frequencies

    outFile.close();  //saves output file
    cout <<"Complete. Enter any character to exit." << endl;    //exit
    cin >> trash;
    return 0;



}

char getGrade(double score){
    if (score >= 90) {  //Grade is A
        return 'A';
    }
    
    if (score >= 80) {  //Grade is B
        return 'B';
    }

    if (score >= 70) {  //Grade is C
        return 'C';
    }

    if (score >= 60) {   //Grade is D
        return 'D';
    }

    if (score >= 0) {   //Grade is F
        return 'F';
    }

    return 'E';     //Shouldn't happen, but just in case it's none of the above

    } 
     


void printGrade(ofstream &outFile, double score, char grade){

    outFile << "Score: " << score << ", Grade: " << grade << "." << endl;  //prints score and letter
    

}

void printFrequencies(ofstream &outFile, int aCount, int bCount, int cCount, int dCount, int fCount){

    outFile << " " << endl;
    outFile << "Grade    Frequency" << endl;
    outFile << "------------------" << endl;
    outFile << "A             " << aCount << endl;  //prints frequencies
    outFile << "B             " << bCount << endl;
    outFile << "C             " << cCount << endl;
    outFile << "D             " << dCount << endl;
    outFile << "F             " << fCount << endl;


}

void raiseFrequency(char grade, int &aCount, int &bCount, int &cCount, int &dCount, int &fCount){ //determine grade, then add to frequency
    switch(grade){
        case 'A':
            aCount++;     //increase frequency of A
            break;

        case 'B':
            bCount++;       //of B
            break;

        case 'C':
            cCount++;        //of C
            break;
        
        case 'D':
            dCount++;     //of D
            break;

        case 'F':
            fCount++;     //of F
            break;

    
    }
}