#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>

int parser(std::string date, double price);

class BitcoinExchange {
	private :
		BitcoinExchange(){};

	public :
		std::map<std::string, double> _data;
		int defaultValue = -1;
		std::string _filename;

		std::string lower_date(std::string date);

		BitcoinExchange(std::string filename) {
			_filename = filename;
			std::ifstream file("data.csv");
			if (!file.is_open()){
				std::cout << "Error: could not open file" << std::endl;
				exit(1);
			}
			std::string line;
			std::cout << "file is open" << std::endl;
			std::getline(file, line);
			std::cout << "Extracting data of type : " << line.substr(0, line.find_first_of(',')) + " and " << line.substr(line.find_first_of(',') + 1, line.length()) << std::endl;
			std::cout << "Data in a hashmap alias magic container" << std::endl;
			while (std::getline(file, line)){
				std::string date = line.substr(0, line.find_first_of(','));
				double price = std::stod(line.substr(line.find_first_of(',') + 1, line.length()));
				_data[date] = price;
			}
			file.close();
		};
		~BitcoinExchange(){};
		void print(){
			std::ifstream file(_filename);
			if (!file.is_open()){
				std::cout << "Error: could not open file" << std::endl;
				exit(1);
			}
			std::string line;
			std::string date;
			double price;
			std::getline(file, line);
			std::cout << "format extracted : " << line << std::endl;
			while (std::getline(file, line)) {
				date = line.substr(0, line.find_first_of('|'));
				date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
				price = std::stod(line.substr(line.find_first_of('|') + 1, line.length()));
				if (!parser(date, price)) {
					if (!_data.count(date))
						date = lower_date(date);
					std::cout << date << " => " << price << " = " << price * _data[date] << std::endl;
				}
			}
		};
};

int parser(std::string date, double price) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
		std::cout << "Error: invalid date format => " << date << std::endl;
		return 1;
	} else if (date.substr(0, 4) < "2009" || date.substr(0, 4) > "2022"){
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	} else if (date.substr(5, 2) < "01" || date.substr(5, 2) > "12"){
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	} else if (date.substr(8, 2) < "01" || date.substr(8, 2) > "31"){
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	} else if (price < 0){
		std::cout << "Error: not a positive number" << std::endl;
		return 1;
	} else if (price > 1000){
		std::cout << "Error: too big number" << std::endl;
		return 1;
	}
	return 0;
}

std::string BitcoinExchange::lower_date(std::string date){
	if (_data.count(date))
		return date;
	int loop = 0;
	loop:
		std::string day = date.substr(8, 2);
		int day_int = std::stoi(day);
		if (day_int-- > 1){
			day = std::to_string(day_int);
			if (day.length() == 1)
				day = "0" + day;
			date = date.substr(0, 8) + day;
		}
	while (loop++ < 10 && !_data.count(date))
		goto loop;
	return date;
}