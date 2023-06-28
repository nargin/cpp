#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array {
	public:
		Array(void) : _size(0), _array(NULL) {}
		Array(size_t n) : _size(n), _array(new T[n]) {}
		Array(Array const & src) : _size(src._size), _array(new T[src._size]) {
			for (size_t i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Array(void) { delete [] _array; }

		Array & operator=(Array const & rhs) {
			if (this != &rhs) {
				delete [] _array;
				_size = rhs._size;
				_array = new T[rhs._size];
				for (size_t i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}

		T & operator[](size_t i) const {
			if (i >= _size)
				throw OutOfBoundsException();
			return _array[i];
		}

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char * what(void) const throw() { return "Array: Out of bounds"; }
		};

		size_t size(void) const { return _size; }

	private:
		size_t _size;
		T *_array;
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & rhs) {
	o << "[";
	for (size_t i = 0; i < rhs.size(); i++) {
		o << rhs[i];
		if (i < rhs.size() - 1)
			o << ", ";
	}
	o << "]";
	return o;
}

#endif