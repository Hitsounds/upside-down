#include <iostream>
#include <string>

//#include "RomanCalc/romanNumerals.h"
#include "RomanCalc/NumberClass.h"


int main() {




	int input = 1;
	std::cin >> input;
	number inp(input);
	number b("IV");
	inp = inp + b;
	std::cout << inp.get_int() << "\n" << inp.get_rom() << "\n";
	std::cin.get();


/*	std::string out = int_to_roman(input);
	std::cout << out;
	std::cin.get();
*/
	return 0;
}


/*void tests() {
	std::cout << "Function tests: " << "\n";
	std::cout << "int_to_roman(1768): " << int_to_roman(1768) << "\n";
	std::cout << "roman_to_int(IVV): " << roman_to_int("IVV") << "\n";




}*/
