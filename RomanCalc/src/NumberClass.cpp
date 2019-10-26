#include <RomanCalc/romanNumerals.h>
#include <RomanCalc/NumberClass.h>
#include <regex>
#include <algorithm>

void number::construct_roman() {
	//Constructs a roman numeral from member vars : int_val and decimal_com e.g XXI.VI
	roman_val = int_to_roman(int_val);
	if (decimal_com > 0) {
		roman_val += "." + int_to_roman(decimal_com);
	}
}

number::number(const int& int_v) {
	//Constructor for integer value
	int_val = int_v;
	decimal_com = 0;
	construct_roman();
}

number::number(const std::string& roman_v) {
	//Constructor for roman value
	std::size_t pos = roman_v.find(".");
	if (pos != std::string::npos) {
		//Use substr to isolate integer part
		int_val = roman_to_int(roman_v.substr(0,pos));
		//Use substr to isolate decimal part
		decimal_com = roman_to_int(roman_v.substr(pos + 1, (roman_v.size() - pos) + 1));
		int_val = int_val + decimal_com / 100;
		decimal_com = decimal_com % 100;
		construct_roman();
		return;
	}
	int_val = roman_to_int(roman_v);
	decimal_com = 0;
	construct_roman();
}

number::number(const double& val) {
	//Constructor for floats. Going to be some data loss but im not going to be using this constructor.
	int_val = static_cast<int>(val);
	decimal_com = static_cast<int>((val - int_val) * 100);
	construct_roman();
}

number::number(const float& val) {
	//Constructor for floats. Going to be some data loss but im not going to be using this constructor.
	int_val = static_cast<int>(val);
	decimal_com = static_cast<int>((val - int_val) * 100);
	construct_roman();
}

number::number(){
	//Default construction
	int_val = 0;
	decimal_com = 0;
	roman_val = "";
}

number number::operator+ (const number& b){
	int new_decimal = (decimal_com + b.decimal_com) % 100;
	int new_int_val = int_val + b.int_val + ((decimal_com + b.decimal_com) / 100);
	number output(new_int_val);
	output.set_decimal_com(new_decimal);
	return output;
}

number number::operator- (const number& b) {
	//Finds the new decimal component 
	int new_decimal = (100+(decimal_com - b.decimal_com) % 100)%100;
	//Finds the new integer value 
	int new_int_val = int_val - b.int_val + ((decimal_com - b.decimal_com + 100) / 100) - 1;
	number output(new_int_val);
	output.set_decimal_com(new_decimal);
	return output;
}

int number::get_int() {
	return int_val;
}

std::string number::get_rom() {
	return roman_val;
}

int number::get_deciCom() {
	return decimal_com;
}

double number::get_valAsDouble() {
	return int_val + decimal_com / 100.0;
}

void number::set_int(const int& int_v) {
	int_val = int_v;
	construct_roman();
}

void number::set_rom(const std::string& roman_v) {
	int_val = roman_to_int(roman_v);
	construct_roman();
}

void number::set_decimal_com(const int& dec) {
	decimal_com = dec;
	construct_roman();
}

bool number::validate_roman(std::string roman) {
	std::transform(roman.begin(), roman.end(), roman.begin(), ::toupper);
	number rom(roman);
	const std::regex re("[^IVXLCDM.]", std::regex_constants::icase);
	if (std::regex_search(roman, re)) {
		throw std::string(": Invalid Chars in Roman Numeral.");
		return false;
	}
	int int_value = roman_to_int(roman);
	if (int_value > 4000) {
		throw std::string(": Too large");
		return false;
	}
	if (roman.length() > rom.get_rom().length()) {
		std::string msg = "should be condensed did you mean: " + rom.get_rom();
		throw msg;
		return false;
	}
	if (rom.get_rom() != roman) {
		std::string msg = "is in the wrong order did you mean: " + rom.get_rom();
		throw msg;
		return false;
	}
	return true;

}