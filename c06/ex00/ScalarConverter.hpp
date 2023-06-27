#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
	private:
		std::string _input;
		char _char;
		int _int;
		float _float;
		double _double;

	public:
		ScalarConverter();
		ScalarConverter(std::string input);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &copy);

		void convert();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();

		class ImpossibleException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NonDisplayableException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};