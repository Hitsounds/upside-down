#include <string>

//Header file with declarations
#include "RomanCalc/romanNumerals.h"


std::string int_to_roman(int integer) {
	//Function to turn a integer value into a roman numeral string.=
	if (integer < 0) {
		//A exception that could be caught higher up if need be
		throw "Can't convert an integer less than 1";
		return "";
	}

	//Array of characters to map to numbers
	const char romans[7] = { 'I','V','X','L','C','D','M' };

	//Array of how many of each char we need -- Probs could combine both lists into a struct or map
	int roman_nums[7] = {0};

	//Find out how many of each character we need by finding DIV
	roman_nums[6] = static_cast<int>(integer / 1000);
	integer = integer - (roman_nums[6] * 1000);
	roman_nums[5] = static_cast<int>(integer / 500);
	integer = integer - (roman_nums[5] * 500);
	roman_nums[4] = static_cast<int>(integer / 100);
	integer = integer - (roman_nums[4] * 100);
	roman_nums[3] = static_cast<int>(integer / 50);
	integer = integer - (roman_nums[3] * 50);
	roman_nums[2] = static_cast<int>(integer / 10);
	integer = integer - (roman_nums[2] * 10);
	roman_nums[1] = static_cast<int>(integer / 5);
	roman_nums[0] = integer - (roman_nums[1] * 5);

	//Create string output in correct order
	std::string output = "";
	for (int i = 6; i >= 0; i--) {
		for (roman_nums[i]; roman_nums[i] > 0; roman_nums[i]--) {
			output = output + romans[i];
		}
	}
	//Return output
	return output;
}

int roman_to_int(const std::string& roman) {
	//Function to turn a roman numeral string to an integer
	int roman_len = roman.length();
	int value = 0;

	for (int i = 0; i < roman_len; i++) {

		switch (roman[i]) {
		case 'I': case 'i':
			value = value + 1;
			break;

		case 'V': case 'v':
			value = value + 5;
			break;

		case 'X': case 'x':
			value = value + 10;
			break;

		case 'L': case 'l':
			value = value + 50;
			break;

		case 'C': case 'c':
			value = value + 100;
			break;

		case 'D': case 'd':
			value = value + 500;
			break;

		case 'M': case 'm':
			value = value + 1000;
			break;

		default:
			break;
		}
	}

	return value;
}
