#include "Array.hpp"

int main(void) {
	Array<int> a(5);
	Array<int> b(5);

	for (size_t i = 0; i < a.size(); i++)
		a[i] = i;
	for (size_t i = 0; i < b.size(); i++)
		b[i] = i + 5;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	Array<int> c(a);
	std::cout << "c: " << c << std::endl;

	Array<int> d;
	d = b;
	std::cout << "d: " << d << std::endl;

	try {
		std::cout << "a[0]: " << a[0] << std::endl;
		std::cout << "a[1]: " << a[1] << std::endl;
		std::cout << "a[2]: " << a[2] << std::endl;
		std::cout << "a[3]: " << a[3] << std::endl;
		std::cout << "a[4]: " << a[4] << std::endl;
		std::cout << "a[5]: " << a[5] << std::endl;
	} catch (std::exception & e) {
		std::cout << "a[5]: " << e.what() << std::endl;
	}

	return 0;
}
