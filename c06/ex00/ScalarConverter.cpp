#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input(""), _char(0), _int(0), _float(0.0f), _double(0.0) {}
ScalarConverter::ScalarConverter(std::string input) : _input(input), _char(0), _int(0), _float(0), _double(0) {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) : _input(copy._input), _char(copy._char), _int(copy._int), _float(copy._float), _double(copy._double) {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	if (this != &copy) {
		this->_input = copy._input;
		this->_char = copy._char;
		this->_int = copy._int;
		this->_float = copy._float;
	}
	return *this;
}

void ScalarConverter::convert() {
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void ScalarConverter::printChar() {
	std::cout << "char: ";
	if (_input.length() == 1 && !isdigit(_input[0])) {
		_char = static_cast<char>(_input[0]);
	} else {
		try { 
			_char = static_cast<char>(std::stoi(_input.c_str()));
		} catch (std::out_of_range &e) {
			std::cout << "non displayable" << std::endl;
			return ;
		} catch (std::invalid_argument &e) {
			std::cout << "impossible" << std::endl;
			return ;
		}
		if (std::isprint(_char)) { 
			std::cout << "'" << _char << "'" << std::endl;
			return ;
		} else {
			std::cout << "non displayable" << std::endl;
			return ;
		}
	}
	std::cout << "'" << _char << "'" << std::endl;
}

void ScalarConverter::printInt() {
	std::cout << "int: ";
	try {
		_int = static_cast<int>(std::stoi(_input.c_str()));
	} catch (std::out_of_range &e) {
		std::cout << "non displayable" << std::endl;
		return ;
	} catch (std::invalid_argument &e) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << _int << std::endl;
}

void ScalarConverter::printFloat() {
	std::cout << "float: ";
	_float = static_cast<float>(std::atof(_input.c_str())) + 0.0f;
	if (std::isnan(_float)) {
		std::cout << "nanf" << std::endl;
		return ;
	} else if  (std::isinf(_float) && _input[0] == '-') {
		std::cout << "-inff" << std::endl;
		return ;
	} else if (std::isinf(_float)){
		std::cout << "+inff" << std::endl;
		return ;
	}
	try {
		_float = static_cast<float>(std::stof(_input.c_str()));
	} catch (std::out_of_range &e) {
		std::cout << "impossible" << std::endl;
		return ;
	} catch (std::invalid_argument &e) {
		std::cout << "non displayable" << std::endl;
		return ;
	}
	std::cout << std::setprecision(1) << std::fixed << _float << "f" << std::endl;
}

void ScalarConverter::printDouble() {
	std::cout << "double: ";
	try {
		_double = static_cast<double>(std::stod(_input.c_str()));
	} catch (std::out_of_range &e) {
		std::cout << "impossible" << std::endl;
		return ;
	} catch (std::invalid_argument &e) {
		std::cout << "non displayable" << std::endl;
		return ;
	}
	if (std::isnan(_double)) {
		std::cout << "nan" << std::endl;
		return ;
	} else if  (std::isinf(_double) && _double < 0) {
		std::cout << "-inf" << std::endl;
	} else if (std::isinf(_double) && _double > 0){
		std::cout << "+inf" << std::endl;
	} else {
		std::cout << std::setprecision(1) << std::fixed << _double << std::endl;
	}
}

const char *ScalarConverter::ImpossibleException::what() const throw() { return "impossible"; }
const char *ScalarConverter::NonDisplayableException::what() const throw() { return "non displayable"; }