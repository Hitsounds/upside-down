#include <string>

//Header file with declarations
#include "RomanCalc/romanNumerals.h"


std::string int_to_roman(int integer) {
	//Array of characters to map to numbers
	const char romans[7] = { 'I','V','X','L','C','D','M' };

	//Array of how many of each char we need -- Probs could combine both lists into a struct or map
	int roman_nums[7] = {0};

	//Find out how many of each character we need by finding DIV
	roman_nums[6] = integer / 1000;
	integer = integer - (roman_nums[6] * 1000);
	roman_nums[5] = integer / 500;
	integer = integer - (roman_nums[5] * 500);
	roman_nums[4] = integer / 100;
	integer = integer - (roman_nums[4] * 100);
	roman_nums[3] = integer / 50;
	integer = integer - (roman_nums[3] * 50);
	roman_nums[2] = integer / 10;
	integer = integer - (roman_nums[2] * 10);
	roman_nums[1] = integer / 5;
	roman_nums[0] = integer - (roman_nums[1] * 5);

	//Create string output in correct order
	std::string output = "";
	for (int i = 0; i < 7; i++) {
		for (roman_nums[i]; roman_nums[i] > 0; roman_nums[i]--) {
			output = output + romans[i];
		}

	}
	//Return output
	return output;

}


int roman_to_int(const std::string& roman) {
	int roman_len = roman.length();
	int value = 0;
	for (int i = 0; i < roman_len; i++) {
		switch (roman[i]) {

		case 'I':
		case 'i':
			value = value + 1;
			break;

		case 'V':
		case 'v':
			value = value + 5;
			break;

		case 'X':
		case 'x':
			value = value + 10;
			break;

		case 'L':
		case 'l':
			value = value + 50;
			break;

		case 'C':
		case 'c':
			value = value + 100;
			break;

		case 'D':
		case 'd':
			value = value + 500;
			break;

		case 'M':
		case 'm':
			value = value + 1000;
			break;

		default:
			//Possible error trapping
			break;


		}
	}
	return value;


}

bool validate_roman(const std::string& roman) {
	return false;




}