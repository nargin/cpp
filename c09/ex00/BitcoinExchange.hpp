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

class BitcoinExchange {
	public :
		std::map<std::string, double> _data;
		BitcoinExchange(std::string filename) {
			std::ifstream file(filename.c_str());
			if (!file.is_open()){
				std::cout << "Error: could not open file" << std::endl;
				exit(1);
			}
			std::string line;
			while (std::getline(file, line)){
				std::cout << line << std::endl;
				std::stringstream ss(line);
				std::cout << ss.str() << std::endl;
				std::string date;
				double price;
				ss >> date >> price;
				_data[date] = price;
			}
			file.close();
		};
		~BitcoinExchange(){};
		void print(){
			std::cout << "Date\t\tPrice" << std::endl;
			for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++){
				std::cout << it->first << "; " << it->second << std::endl;
			}
		};
};