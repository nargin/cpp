#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input(""), _char(0), _int(0), _float(0), _double(0), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false), _isImpossible(false), _isNan(false), _isInf(false), _isNegInf(false), _isPosInf(false) {}
ScalarConverter::ScalarConverter(std::string input) : _input(input), _char(0), _int(0), _float(0), _double(0), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false), _isImpossible(false), _isNan(false), _isInf(false), _isNegInf(false), _isPosInf(false) {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) : _input(copy._input), _char(copy._char), _int(copy._int), _float(copy._float), _double(copy._double), _isChar(copy._isChar), _isInt(copy._isInt), _isFloat(copy._isFloat), _isDouble(copy._isDouble), _isImpossible(copy._isImpossible), _isNan(copy._isNan), _isInf(copy._isInf), _isNegInf(copy._isNegInf), _isPosInf(copy._isPosInf) {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	if (this != &copy) {
		this->_input = copy._input;
		this->_char = copy._char;
		this->_int = copy._int;
		this->_float = copy._float;
		this->_double = copy._double;
		this->_isChar = copy._isChar;
		this->_isInt = copy._isInt;
		this->_isFloat = copy._isFloat;
		this->_isDouble = copy._isDouble;
		this->_isImpossible = copy._isImpossible;
		this->_isNan = copy._isNan;
		this->_isInf = copy._isInf;
		this->_isNegInf = copy._isNegInf;
		this->_isPosInf = copy._isPosInf;
	}
	return *this;
}

void ScalarConverter::convert() {
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
		char c = this->_input[0];
	else {
		try {
			int charValue = atoi(this->_input.c_str());
			if (charValue < 0 || charValue > 127)
				throw ScalarConverter::NonDisplayableException;
			else if (charValue < 32 || charValue == 127)
				throw ScalarConverter::ImpossibleException;
			else
				this->_char = static_cast<char>(charValue);
			

		} catch (std::invalid_argument &e) {
			ScalarConverter::NonDisplayableException.what();
		} catch (std::out_of_range &e) {
			ScalarConverter::ImpossibleException.what();
		}
	}
}

void ScalarConverter::printInt() {

}

void ScalarConverter::printFloat() {

}

void ScalarConverter::printDouble() {

}

const char *ScalarConverter::ImpossibleException::what() const throw() { return "impossible"; }
const char *ScalarConverter::NonDisplayableException::what() const throw() { return "non displayable"; }