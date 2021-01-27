#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

using namespace std;
    ////////////////////////////////////////default constructor
    College::College(){
        head = NULL;
        studentName = "Anonymous";
        
    }

    ////////////////////////////////////the big three          
    College::~College(){
        for(head; head != NULL; head = head -> link()){
            delete head;
        }
    }

    College::College(const College& other){
        string toName = other.studentName;
        set_name(toName);
        node* otherList = other.head;
        head = new node;
        head -> set_data(otherList -> data());
        head -> set_link(NULL);
        otherList = otherList -> link();

    
        for(node* cursor = head; otherList != NULL; otherList = otherList -> link()){
            cursor -> set_link(new node);
            cursor = cursor -> link();
            cursor -> set_data(otherList -> data());
            cursor -> set_link(NULL);
        }
    }

    void College::operator =(const College& other){
        if(&other == this){
            return;
        }
        string toName = other.studentName;
        set_name(toName);
        node* otherList = other.head;
        head = new node;
        head -> set_data(otherList -> data());
        head -> set_link(NULL);
        otherList = otherList -> link();

    
        for(node* cursor = head; otherList != NULL; otherList = otherList -> link()){
            cursor -> set_link(new node);
            cursor = cursor -> link();
            cursor -> set_data(otherList -> data());
            cursor -> set_link(NULL);

        }
    }

    ////////////////////////////////////////////data manipulation
    void College::add(course c){
        node* cursor;
        node* futureCursor;
        node* testCursor;
        if(head == NULL){
            //cout << "empty" << endl;
            head = new node;
            head -> set_data(c);
            head -> set_link(NULL);
        }else{
            //cout << "not empty" << endl;

            if(head -> data() > c){
                //cout << "smaller than original" << endl;
                cursor = new node;
                cursor -> set_data(c);
                cursor -> set_link(head);
                head = cursor;
            }else{
                //cout << "need to check" << endl;
                //cout << cursor -> link() << endl;
                //testCursor = cursor -> link();
                //cout << testCursor -> data();                 //this crashes it, but gives an actual error message
                //cout << "test cursor passed" << endl;

                //if(testCursor -> data() == NULL){              //this causes a massive list of compiler issues
                if(head -> link() == NULL){
                    //cout << "NULL" << endl;
                    cursor = head;
                    cursor -> set_link(new node);
                    cursor = cursor -> link();
                    cursor -> set_data(c);
                    return;
                }
                cout << cursor -> link() << endl;
                for(cursor = head; cursor -> link() != NULL; cursor = cursor -> link()){
                    //cout << "a loop" << endl;
                    futureCursor = cursor -> link();
                    //cout << "futureCursor" << endl;
                    if(futureCursor -> data() > c){
                        //cout << "should input" << endl;
                        cursor -> set_link(new node);
                        cursor -> set_data(c);
                        cursor -> set_link(futureCursor);
                        return;
                    }
                //cout << "end of if" << endl;
                }
                cursor -> set_link(new node);
                cursor = cursor -> link();
                cursor -> set_data(c);
                return;
            }
        }
    }

    void College::remove(string name){            
        node* cursor = head;
        node* searching;
        string courseName;
        course courseTest;
        cout << "setup" << endl;
        for(cursor = head; cursor -> link() != NULL; cursor = cursor -> link()){
            cout << "loop" << endl;
            searching = cursor -> link();
            courseTest = searching -> data();
            courseName = courseTest.get_course_number();
            cout << "setup2" << endl;
            if(courseName.find(name) < string::npos){
                cout << "found!" << endl;
                if(searching -> link() != NULL){
                    cursor -> set_link(searching -> link());
                    cout << "set to the next one" << endl;
                }else{
                    cursor -> set_link(NULL);
                    cout << "set to null" << endl;
                    return;
                }
            }
        } 
    }                                      

    void College::set_name(string name){
        studentName = name;
    }
   
    //////////////////////////////////////////////////////information
    void College::display(ostream& outs){
        node* cursor = head;
        course examining;
        //cout << "it started" << endl;
        //cout << cursor << endl;
        for(cursor = head; cursor != NULL; cursor = cursor -> link()){
            //cout << "loop started" << endl;
            examining = cursor -> data();
            //cout << "assignment" << endl;
            outs << examining;
            //cout << "cout" << endl;
        }
    }

    int College::hours(){
        int totalHours = 0;
        node* cursor = head;
        course examining;
        int currentHours;
        for(cursor; cursor != NULL; cursor = cursor -> link()){
            examining = cursor -> data();
            currentHours = examining.get_hours();
            totalHours += currentHours;
            //cout<< "current hours " << currentHours << " was added to total hours " << totalHours << endl;
        }
        return totalHours;
    }

    double College::gpa(){           
        int currentHours = 0, currentGrade = 0, currentPoints = 0; 
        double totalPoints = 0, totalHours = 0, gpa = 0;
        node* cursor = head;
        course examining;
        for(cursor; cursor != NULL; cursor = cursor -> link()){
            examining = cursor -> data();
            currentHours = examining.get_hours();
            currentGrade = examining.get_number_grade();
            currentPoints = currentHours * currentGrade;
            //cout << "THe points for this course were " << currentPoints << endl;

            totalPoints += currentPoints;
        }
        totalHours = hours();

        gpa  = totalPoints / totalHours;
        return gpa;
    }
    
    //////////////////////////////////////file manipulation
    void College::load(istream& ins){
        course fromFile;
        string toName;
        getline(ins, toName);
        set_name(toName);
        while(ins.peek() == '\n'){
            ins.ignore();
        }
        while(!ins.eof()){
        //for(int i = 0; i< 4; i++){
        //do{
        ins >> fromFile;
        add(fromFile);
        if(ins.peek() == '\n'){
            ins.ignore();
        }
        }//while(!ins.eof());
    }

    void College::save(ostream& outs){
                outs << studentName << endl;
        for(node* cursor = head; cursor != NULL; cursor = cursor -> link()){
                outs << cursor -> data();
        }
    }