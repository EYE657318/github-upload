/**************************************
   CS2401 Spring 2013	Lab Assignment 4
	John Dolan
   A little class that holds a dynamic array of numbers
***************************************/

#include<iostream>
using namespace std;

size_t byte_count = 0;
class Numbers{
    public:
	Numbers();
	~Numbers();
	void add(unsigned long item);
	void resize();
	void remove_last();
	void display(std::ostream& outs);
	unsigned long* reveal_address()const;
					//This is added after first three questions answered:
	void operator = (const Numbers& other);
	// This is used in Part 2 and would normally not be in a container	unsigned long * reveal_address()const;
	//This is a function that you add in Part 2
	//~Numbers();
    private: 
	unsigned long * data;
	std::size_t used;
	std::size_t capacity;
};

Numbers::Numbers(){
	data = new unsigned long[5];
	used = 0;
	capacity = 5;
	byte_count +=5*sizeof(unsigned long);
}

void Numbers::add(unsigned long item){
	if(used == capacity)
	   resize();
	data[used] = item;
	used++;
}

void Numbers::resize(){
	unsigned long *tmp;
	tmp = new unsigned long[capacity+5];
	std::copy(data, data+used, tmp);    
	delete [] data;
	capacity += 5;
	byte_count +=5*sizeof(unsigned long);
	data = tmp;
}

void Numbers::remove_last(){
	used--;
}

void Numbers::display(std::ostream& outs){
	for(std::size_t i = 0; i < used; ++i)
	    outs<<data[i]<<' ';
}

unsigned long *Numbers::reveal_address()const{
	return data;
}
// You will need to write the implementation of this overloaded operator

void Numbers::operator = (const Numbers& other){
	if(&other == this){
		return;
	}
	unsigned long *temp;
	temp = new unsigned long[capacity];
	used = other.used;
	copy(other.data, other.data + used, temp);
	delete [] data;
	data = temp;

	
	
}

Numbers::~Numbers(){
	byte_count = byte_count - capacity*sizeof(unsigned long);
	delete [] data;
	cout << "Get out >:(" << endl;
}

