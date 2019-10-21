#include <RomanCalc/romanNumerals.h>
#include <RomanCalc/NumberClass.h>

number::number(const int& int_v) {
	//Constructor for integer value
	int_val = int_v;
	roman_val = int_to_roman(int_v);
}

number::number(const std::string& roman_v) {
	//Constructor for roman value
	int_val = roman_to_int(roman_v);
	roman_val = roman_v;
}

number::number(){
	//Default construction
	int_val = 0;
	roman_val = "0";
}

number number::operator+ (const number& b){
	return number(int_val + b.int_val);
}

number number::operator- (const number& b) {
	return number(int_val - b.int_val);
}

number number::operator* (const number& b) {
	return number(int_val * b.int_val);
}

number number::operator/ (const number& b) {
	return number(int_val / b.int_val);
}

int number::get_int() {
	return int_val;
}

std::string number::get_rom() {
	return roman_val;
}

void number::set_int(const int& int_v) {
	int_val = int_v;
	roman_val = int_to_roman(int_v);
}

void number::set_rom(const std::string& roman_v) {
	int_val = roman_to_int(roman_v);
	roman_val = roman_v;
}