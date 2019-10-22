#pragma once
#include <string>

class number {
//A class to use to perform math on the numbers
//Abstracts away the conversion functions = less work later on


public:
	//Constructors
	number(const int&);
	number(const std::string&);
	number();

	//Get values
	int get_int();
	std::string get_rom();

	//Set values
	void set_int(const int&);
	void set_rom(const std::string&);

	//Mathematical operations
	number operator+(const number&);
	number operator-(const number&);
	number operator/(const number&);
	number operator*(const number&);



private:
	//Don't want people editing these
	int int_val;
	int decimal_com;
	std::string roman_val;
};
