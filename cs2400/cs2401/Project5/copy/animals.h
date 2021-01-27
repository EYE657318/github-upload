#include <iostream>

using namespace std;

class Animal{
    public:
    Animal(){customer_name = "Anonymous"; description = "No description given";}
    virtual void input(istream& ins);
    virtual void output(ostream& outs);

    private:
    string customer_name;
    string description;

};

class Ant: public Animal{
    public:
    Ant(){sidelength = 1; hive_size = 1;}
    void input(istream& ins);
    void output(ostream& outs);

    private:
    int sidelength;
    int hive_size;
};

class Monkfish: public Animal{
    public:
    Monkfish(){sidelength = 1; depth = 1000; saltwater = true;}
    void input(istream& ins);
    void output(ostream& outs);

    private:
    int sidelength;
    int depth;
    bool saltwater;


};

class GemRabbit: public Animal{
    public:
    GemRabbit(){holedepth = 5; gem_type = "dirt"; rarity = R;}
    void input(istream& ins);
    void output(ostream& outs);

    private:
    int holedepth;
    string gem_type;
    char rarity;

};

class Scarab: public Animal{
    public:
    Scarab(){holedepth = 5; special = false;}
    void input(istream& ins);
    void output(ostream& outs);

    private:
    int holedepth;
    bool special;

};

class BlinkDog: public Animal{
    public:
    BlinkDog(){sidelength = 1; blink_distance = 5; cooldown = 40; walktime_minute = 30; walktime_hour = 1;}
    void input(istream& ins);
    void output(ostream& outs);

    private:
    int sidelength;
    double blink_distance;
    int cooldown;
    int walktime_minute;
    int walktime_hour;
};

class Auroch: public Animal{
    public:
    Auroch(){squaremiles = 10; herdsize = 1; living = true;} 
    void input(istream& ins);
    void output(ostream& outs);

    private:
    int squaremiles;
    int herdsize;
    bool living;

};