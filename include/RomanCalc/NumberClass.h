#pragma once
#include <string>

class number {
//A class to use to perform math on the numbers and keep track of the roman numeral representation at the same time
//Abstracts away the conversion functions = less work later on


public:
	//Misc?
	void construct_roman();
	//You shouldn't need to call this function as it should be called automatically when it needs to be.
	//Maybe I should make it private. But it doesn't hurt to allow it to be called from outside.

	static bool validate_roman(std::string roman);

	//Constructors
	number(const int&);
	number(const std::string&);
	number(const double&);
	number(const float&);
	number();

	//Get values
	int get_int();
	std::string get_rom();
	int get_deciCom();
	double get_valAsDouble();

	//Set values
	void set_int(const int&);
	void set_rom(const std::string&);
	void set_decimal_com(const int&);

	//Mathematical operations
	number operator+(const number&);
	number operator-(const number&);



private:
	//Don't want people editing these
	int int_val;
	int decimal_com;
	std::string roman_val;
};
