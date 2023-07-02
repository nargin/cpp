#pragma once

#include <iostream>


template <typename T>
class Span {
	public:
		Span(size_t n) : _count(0), _size(n), _array(new T[n]) {}
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

		unsigned int cuve(int n) { return (n < 0) ? -n : n; }

		void	addNumber(T const & n) {
			if (_size == 0 || _count >= _size)
				throw OutOfBoundsException();
			_array[_count++] = n;
		}

		void addNumber(T const * src, T const length) {
			if (_size == 0 || _count + length > _size || length == 0)
				throw OutOfBoundsException();
			for (size_t i = 0; i < length; i++) {
				_array[i] = src[i];
				if (++_count > _size)
					throw OutOfBoundsException();
			}
		}

		unsigned int shortestSpan(void) {
			if (_size == 0 || _count < 2)
				throw OutOfBoundsException();
			unsigned int shortest = cuve(_array[0] - _array[1]);
			for (size_t i = 1; i < _count; i++) {
				if (cuve(_array[i] - _array[i - 1]) < shortest)
				shortest = cuve(_array[i] - _array[i - 1]);
			}
			return shortest;
		}

		unsigned int longestSpan(void) {
			if (_size == 0 || _count < 2)
				throw OutOfBoundsException();
			unsigned int longest = cuve(_array[0] - _array[1]);
			for (size_t i = 1; i < _count; i++) {
				if (cuve(_array[i] - _array[i - 1]) > longest)
					longest = cuve(_array[i] - _array[i - 1]);
			}
			return longest;
		}

		T & operator[](size_t i) const {
			if (i >= _size)
				throw OutOfBoundsException();
			return _array[i];
		}

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char * what(void) const throw() { return "Span: Out of bounds"; }
		};

		size_t size(void) const { return _size; }
		size_t counting(void) const { return _count; }

	private:
		Span(void) : _count(0), _size(0), _array(NULL) {}
		size_t _count;
		size_t _size;
		T *_array;
};