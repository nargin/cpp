#include "Serializer.hpp"

# define GREEN(x) "\033[1;32m" << x << "\033[0m"
# define RED(x) "\033[1;31m" << x << "\033[0m"
# define YELLOW(x) "\033[1;33m" << x << "\033[0m"
# define BLUE(x) "\033[1;34m" << x << "\033[0m"
# define MAGENTA(x) "\033[1;35m" << x << "\033[0m"
# define CYAN(x) "\033[1;36m" << x << "\033[0m"

int main(void)
{
	Data *data = new Data;
	data->something = "something";
	data->doesnt = "doesn't";
	data->exist = "exist";
	data->supreme = "supreme";
	data->power = "power";

	uintptr_t raw = Serializer::serialize(data);
	Data *rotten = Serializer::deserialize(raw);

	std::cout << MAGENTA("Address of Data before serialize:  ") << &raw << std::endl;
	std::cout << RED("Address of Data after deserialize: ") << rotten  << std::endl;
	std::cout << std::endl;

	std::cout << CYAN("Data before serialize: ") << std::endl;
	std::cout << "something: " << data->something << std::endl;
	std::cout << "doesn't:   " << data->doesnt << std::endl;
	std::cout << "exist:     " << data->exist << std::endl;
	std::cout << "supreme:   " << data->supreme << std::endl;
	std::cout << "power:     " << data->power << std::endl;
	std::cout << std::endl;

	std::cout << CYAN("Data after deserialize: ") << std::endl;
	std::cout << "something: " << rotten->something << std::endl;
	std::cout << "doesn't:   " << rotten->doesnt << std::endl;
	std::cout << "exist:     " << rotten->exist << std::endl;
	std::cout << "supreme:   " << rotten->supreme << std::endl;
	std::cout << "power:     " << rotten->power << std::endl;
	std::cout << std::endl;
	return 0;
}