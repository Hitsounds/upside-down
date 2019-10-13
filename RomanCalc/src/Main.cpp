#include <iostream>
#include <string>

#include "RomanCalc/romanNumerals.h"

void tests();

int main() {
	#ifdef _DEBUG
		tests();
	#endif




	int input;
	std::cin >> input;
	std::string out = int_to_roman(input);
	std::cout << out;
	std::cin.get();


}

void tests() {
	std::cout << "Function tests: " << "\n";
	std::cout << "int_to_roman(1768): " << int_to_roman(1768) << "\n";





}
