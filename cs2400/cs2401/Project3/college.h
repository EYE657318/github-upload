#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"

using namespace std;


class College{

    public:
    //////////////////////////////////////default constructor
    College();

    ////////////////////////////////////the big three
    ~College();
    College(const College& other);
    void operator =(const College& other);

    ////////////////////////////////////////////data manipulation
    void add(course c);          //uses comparison operator to sort
    void remove(string name);
    void set_name(string name);
   
    //////////////////////////////////////////////////////information
    void display(ostream& outs);
    int hours();
    double gpa();//return GPA (points*hours, addition, divide by total hours

    
    //////////////////////////////////////file manipulation
    void load(istream& ins);
    void save(ostream& outs);

    private:

    string studentName;
    node* head;

};

#endif