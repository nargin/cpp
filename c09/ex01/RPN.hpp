#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

class RPN {
	public :
		std::stack<int> stack;
		RPN(std::string expression){
			if (expression.length() < 3)
				throw std::string("Error");
			std::stringstream ss(expression);
			std::string token;
			while (std::getline(ss, token, ' ')) {
				if (token.length() == 1 && !isdigit(token[0])) {
					if (stack.size() < 2)
						throw std::string("Error");
					int a = stack.top();
					stack.pop();
					int b = stack.top();
					stack.pop();
					switch (token[0]) {
						case '+':
							stack.push(a + b);
							break;
						case '-':
							stack.push(b - a);
							break;
						case '*':
							stack.push(a * b);
							break;
						case '/':
							stack.push(b / a);
							break;
						case '%':
							stack.push(fmod(b, a));
							break;
						default:
							throw std::string("Error");
					}
				} else {
					stack.push(std::stod(token));
				}
			}
			if (stack.size() != 1)
				throw std::string("Error");
			std::cout << std::fixed << std::setprecision(1) << stack.top() << std::endl;
		};
		~RPN(){};
	
	private:
		RPN(){};

};