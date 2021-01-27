#include <iostream>
#include "animals.h"

using namespace std;

void Animal::input(istream& ins){
    
}

void Animal::output(ostream& outs){

}

void Ant::input(istream& ins){
    cout << "This will be an ant farm with standard thickness." << endl;

    cout << "How long is the ant farm? (In feet)" << endl;
    if(ins.peek() == '\n'){ins.ignore();}
    ins >> sidelength;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "How many ants will be inhabiting the farm?" << endl;
    ins >> hive_size;
    if(ins.peek() == '\n'){ins.ignore();}
}

void Ant::output(ostream& outs){
    cout << "Here is the information for customer "<< customer_name << endl;
    cout << "animal: ";
    outs << "ant" << endl;
    cout << description << endl;

    cout << "The length of the side is: ";
    outs << sidelength << endl;
    cout << "The number of contained ants is: ";
    outs << hive_size << endl;


}

void Monkfish::input(istream& ins){
    int thischoice;
    cout << "This will be a cage in a body of water, with gaps small enough to block it from leaving, \nbut large enough to allow its food to enter." << endl;

    cout << "How deep is it? (in feet)" << endl;
     if(ins.peek() == '\n'){ins.ignore();}
    ins >> depth;
     if(ins.peek() == '\n'){ins.ignore();}

    cout << "How long is each side?" << endl;
    ins >> sidelength;
     if(ins.peek() == '\n'){ins.ignore();}

    cout << "Enter your choice:" << endl << "0) The body of water is freshwater." << endl << "1) The body of water is saltwater." << endl;
    ins >> thischoice;
     if(ins.peek() == '\n'){ins.ignore();}

    if(thischoice == 0){
        saltwater = false;
        //if(ins.peek() == "\n"){ins.ignore()}
        cout << "What, are you trying to kill it or something? Oh well, I won't judge." << endl << endl;
    }
    if(thischoice == 1){
        saltwater = true;
        //if(ins.peek() == "\n"){ins.ignore()}
    }

}

void Monkfish::output(ostream& outs){
    int thisbool;

    cout << "Here is the information for customer "<< customer_name << endl;
    cout << "animal: ";
    outs << "monkfish" << endl;
    cout << description << endl;

    cout << "the depth is: ";
    outs << depth << endl;;
    cout << "the side length is: ";
    outs << sidelength << endl;
    cout << "saltwater?: ";
    outs << saltwater << endl;
    if(saltwater ==0){
        cout << "(No)" << endl;
    }
    if(saltwater == 1){
        cout << "(Yes)" << endl; 
    }


}

void GemRabbit::input(istream& ins){
    cout << "This will be a terrarium deep enough for the rabbit's burrow." << endl;

    cout << "How deep is it? (in feet)" << endl;
    if(ins.peek() == '\n'){ins.ignore();}
    ins >> holedepth;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "How rare is it?" << endl << "N) Not" << endl << "R) Relatively rare" << endl << "V) Very rare" << endl;
    ins >> rarity;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "What is the rabbit made of?" << endl;
    getline(ins, gem_type);
     if(ins.peek() == '\n'){ins.ignore();}

}

void GemRabbit::output(ostream& outs){
    cout << "Here is the information for customer "<< customer_name << endl;
    cout << "animal: ";
    outs << "materialrabbit" << endl;
    cout << description << endl;

    cout << "The depth is: ";
    outs << holedepth << endl;
    cout << "The rarity is: ";
    outs << rarity << endl;;
    if(rarity == 'N'){
        cout << "(common)" << endl;}
    if(rarity == 'R'){
        cout << "(somewhat rare)" << endl;}
    if(rarity == 'V'){
        cout << "(very rare)" << endl;}
    cout << "The rabbit is made of: ";
    outs << gem_type << endl;

}

void Scarab::input(istream& ins){
    int thischoice;

    cout << "This will be a terrarium deep enough for the scarab's burrow." << endl;

    cout << "How deep is it? (in feet)" << endl;
    if(ins.peek() == '\n'){ins.ignore();}
    ins >> holedepth;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "Is this scarab specifically the species sacred in Egyptian mythology?" << endl;
    cout << "We need to know how likely it is Khepri decieds to manifest in this scarab's body." << endl;
    cout << "It's an insurance thing, don't think about it too hard." << endl << "0) Yes" << endl << "1) No" << endl;
    cin >> thischoice;
    if(ins.peek() == '\n'){ins.ignore();}

    if(thischoice == 0){
        cout << "Well that's annoying." << endl << endl;
        special = true;
    }
    if(thischoice == 1){
        cout << "Oh, good." << endl << endl;
        special = false;
    }


}

void Scarab::output(ostream& outs){
    //int thisbool;

    cout << "Here is the information for customer "<< customer_name << endl;
    cout << "animal: ";
    outs << "scarab" << endl;
    cout << description << endl;

    cout << "Holedepth: ";
    outs << holedepth << endl;

    cout << "special?: ";
    outs << special << endl;
    if(special == 1){
        //special = true;
        cout << "(Yes)" << endl << endl;
    }
    if(special == 0){
        //special = false;
        cout << "(No)" << endl << endl;
    }

}

void BlinkDog::input(istream& ins){
    cout << "Thise will be a container designed to prevent the Blink Dog from escaping." << endl;

    cout << "How long is the interior room? (The one the dog will normally be inhabiting)" << endl;
    if(ins.peek() == '\n'){ins.ignore();}
    ins >> sidelength;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "How far can the blink dog teleport?" << endl;
    ins >> blink_distance;
    if(ins.peek() == '\n'){ins.ignore();}
    cout << "The outer room will need to have the same radius in order to keep the dog contained." << endl;

    cout << "How often can it teleport? (in seconds)" << endl;
    ins >> cooldown;
    if(ins.peek() == '\n'){ins.ignore();}
    cout << "Be sure to return it to its original room within that time." << endl;

    cout << "At what hour is the blink dog's scheduled walk?" << endl;
    ins >> walktime_hour;
    if(ins.peek() == '\n'){ins.ignore();}
    cout << "At what minute is the blink dog's scheduled walk?" << endl;
    ins >> walktime_minute;
    if(ins.peek() == '\n'){ins.ignore();}

}

void BlinkDog::output(ostream& outs){
    cout << "Here is the information for customer "<< customer_name << endl;
    cout << "animal: ";
    outs << "blink" << endl;
    cout << description << endl;

    cout << "Sidelength: ";
    outs << sidelength << endl;

    cout << "Blink distance: ";
    outs << blink_distance << endl;

    cout << "Cooldown: ";
    outs << cooldown << endl;

    cout << "The dog is walked at hour: ";
    outs << walktime_hour << endl;
    cout << "And minute: ";
    outs << walktime_minute << endl;

}

void Auroch::input(istream& ins){
    int thischoice;

    cout << "This will be a section of wilderness for an entire auroch herd." << endl;

    cout << "How many square miles is it?" << endl;
    if(ins.peek() == '\n'){ins.ignore();}
    ins >> squaremiles;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "How big is the herd?" << endl;
    ins >> herdsize;
    if(ins.peek() == '\n'){ins.ignore();}

    cout << "Are the aurochs alive?" << endl << "0) Yes" << endl << "1) No" << endl;
    ins>> thischoice;
    if(thischoice == 0){
        cout << "Wait, really? They're extinct! I thought this was a joke!" << endl;
        cout << "Well, have fun with that I guess." << endl;
        living = true;
    }
    if(thischoice == 1){
        cout << "Have fun with those bones then." << endl;
        living = false;

    }


}

void Auroch::output(ostream& outs){
    cout << "Here is the information for customer "<< customer_name << endl;
    cout << "animal: ";
    outs << "auroch" << endl;
    cout << description << endl;

    cout << "Square miles: ";
    outs << squaremiles << endl;

    cout << "Herd size: ";
    outs << herdsize << endl;

    cout << "Living? ";
    outs << living;
    if(living == true){
        cout << "(Yes)" << endl;
    }
    if(living == false){
        cout << "(No)" << endl;
    }

}