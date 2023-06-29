#pragma once

#include <iostream>

template <typename T>
class Span {
	public:
		Span(size_t n) : _size(n), _count(0), _array(new T[n]) {}
		Span(Span const & src) : _size(src._size), _count(src._count),_array(new T[src._size]) {
			for (size_t i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Span(void) { delete [] _array; }

		Span & operator=(Span const & rhs) {
			if (this != &rhs) {
				delete [] _array;
				_size = rhs._size;
				_array = new T[rhs._size];
				for (size_t i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}

		void	addNumber(T const & n) {
			if (_size == 0 || _count == _size)
				throw OutOfBoundsException();
			for (size_t i = 0; i < _size; i++) {
				if (_array[i] == 0) {
					_array[i] = n;
					return ;
				}
			}
			throw OutOfBoundsException();
		}

		void addNumber(T const * begin, T const * end) {
			if (_size == 0 || _count == _size)
				throw OutOfBoundsException();
			for (size_t i = 0; i < _size; i++) {
				if (_array[i] == 0) {
					_array[i] = *begin;
					begin++;
					if (begin == end)
						return ;
				}
			}
			throw OutOfBoundsException();
		}

		T & operator[](size_t i) const {
			if (i >= _size)
				throw OutOfBoundsException();
			return _array[i];
		}

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char * what(void) const throw() { return "Span: Out of bounds"; }
				virtual const char * segfault(void) const throw() { return "Span: can't add more"; }
		};

		size_t size(void) const { return _size; }

	private:
		size_t _count;
		size_t _size;
		T *_array;
};