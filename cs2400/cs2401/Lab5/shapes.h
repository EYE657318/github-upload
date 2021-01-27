#include <cmath>
#include <iostream>

using namespace std;

class Shape{
    public: 
    Shape(){thickness = 1; cpcu = 1;};
    virtual void input(){
        cout << "Please enter the thickness" << endl;
        cin >> thickness;
        cout << "Please enter the cost per cubic unit" << endl;
        cin >> cpcu;
        }

    double cost(){return thickness*cpcu*area();};
    virtual double area() = 0;

    private:
    double thickness;
    double cpcu;
};

class Circle: public Shape{
    public:
    Circle(){radius = 0;}
    void input(){cout << "Please enter the radius" << endl; cin >> radius;}
    double area(){return radius*radius*M_PI;};

    private:
    double radius;

};

class Rectangle: public Shape{
    public:
    Rectangle(){length = 0; width = 0;};
    void input(){ cout << "Please enter the length" << endl; cin >> length;
        cout << "Please enter the width" << endl; cin >> width;
    };
    double area(){return length*width;};

    private:
    double length;
    double width;

};

class Trapezoid: public Shape{
    public: 
    Trapezoid(){base1 = 0; base2 = 0; height = 0;};
    void input(){ cout << "Please enter the first base" << endl; cin >> base1;
        cout << "Please enter the second base" << endl; cin >> base2;
        cout << "Please enter the height" << endl; cin >> height;
    };
    double area(){return height*(base1*base2)/2.0;};

    private:
    double base1;
    double base2;
    double height;

};