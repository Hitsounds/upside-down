#include <iostream>
#include <string>

//#include "RomanCalc/romanNumerals.h"
#include "RomanCalc/NumberClass.h"


int main() {
	std::string Ichi;
	std::string Ni;
	std::cout << "Enter the first number as a roman numeral: ";
	std::cin >> Ichi;
	std::cout << "Enter the second number as a roman numeral: ";
	std::cin >> Ni;
	//TODO: Validate here
	number numIchi(Ichi);
	number numNi(Ni);

	std::cout << "\nFirst number" << ":\nArabic: " << numIchi.get_int() << "\nRoman Numerals: " << numIchi.get_rom() << "\n\n";
	std::cout << "Second number" << ":\nArabic: " << numNi.get_int() << "\nRoman Numerals: " << numNi.get_rom() << "\n\n";

	std::cout << "Enter corresponding symbol for the operation you want to perform:\n(+)Addition or (-)Subtraction ";

	number result;
	std::string temp;
	std::cin >> temp;

	switch (temp[0]) {
		case '+':
			result = numIchi + numNi;
			break;

		case '-':
			result = numIchi - numNi;
			break;

		default:
			std::cout << "Bad input! Not + or -. Presuming + input...\n";
			result = numIchi + numNi;
			break;

	}

	std::cout << "\nResult" << ":\nArabic: " << result.get_int() << "\nRoman Numerals: " << result.get_rom() << "\n\n";

/*	int input = 1;
	std::cin >> input;
	number inp(input);
	number b("IV");
	inp = inp + b;
	std::cout << inp.get_int() << "\n" << inp.get_rom() << "\n";
	std::cin.get();


	std::string out = int_to_roman(input);
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
