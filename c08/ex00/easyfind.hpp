#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

class NoFind : public std::exception {
	public :
		virtual const char *what(void) const throw() { return "No finding..."; };
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NoFind();
	}
	return it;
}