#include <RomanCalc/romanNumerals.h>
#include <RomanCalc/NumberClass.h>

number::number(int int_v) {
	//Constructor for integer value
	int_val = int_v;
	roman_val = int_to_roman(int_v);
}

number::number(std::string roman_v) {
	//Constructor for roman value
	int_val = roman_to_int(roman_v);
	roman_val = roman_v;

}

number number::operator+ (number b){
	return number(int_val + b.int_val);
}

number number::operator- (number b) {
	return number(int_val - b.int_val);
}

number number::operator* (number b) {
	return number(int_val * b.int_val);
}

number number::operator/ (number b) {
	return number(int_val / b.int_val);
}

int number::get_int() {
	return int_val;
}

std::string number::get_rom() {
	return roman_val;
}
