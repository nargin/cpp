#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <iomanip>

#define INT_MAX 2147483647

class PmergeMe {
	public:
		std::vector<int> vector;
		std::deque<int> deque;

		PmergeMe(char *av[]) {
			int i = 0;
			long long int tmp;
			while (av[++i]) {
				tmp = std::stoll(av[i]);
				if (tmp > INT_MAX || tmp < 0) {
					std::cout << "Error: " << tmp << " is out of range" << std::endl;
					exit(1);
				}
				vector.push_back(tmp);
				deque.push_back(tmp);
			}
			printStack(0);
			clock_t start = clock();
			std::sort(vector.begin(), vector.end());
			clock_t end = clock();
			printStack(1);
			std::cout << "Vector sort time: " << std::setprecision(6) << std::fixed << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
			start = clock();
			std::sort(deque.begin(), deque.end());
			end = clock();
			std::cout << "Deque sort time: " << std::setprecision(6) << std::fixed << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

		}

		void printStack(int status) {
			status ? std::cout << "Before: " : std::cout << "After: ";
			for (auto it = vector.begin(); it != vector.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
	private:
		PmergeMe(){};
};