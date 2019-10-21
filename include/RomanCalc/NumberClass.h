#pragma once
#include <string>

class number {
//A class to use to perform math on the numbers
//Abstracts away the conversion functions = less work later on


public:
	//Constructors
	number(int);
	number(std::string);

	//Get values
	int get_int();
	std::string get_rom();

	//Mathematical operations
	number operator+(number);
	number operator-(number);
	number operator/(number);
	number operator*(number);



private:
	//Don't want people editing these
	int int_val;
	std::string roman_val;

};
