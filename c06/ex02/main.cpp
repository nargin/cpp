#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	srand(time(NULL));
	std::cout << "Generating random class" << std::endl;
	int random = rand() % 3;
	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b;
		} catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c;
			} catch (std::exception &e) {
				std::cout << "Unknown class" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}