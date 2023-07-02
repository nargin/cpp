#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "start: " << *mstack.begin() << std::endl;
	std::cout << "++ : " << *++mstack.begin() << std::endl;
	std::cout << "ending : " << *mstack.end() << std::endl;
	mstack.pop();
	std::cout << "start: " << *mstack.begin() << std::endl;
	std::cout << "ending : " << *mstack.end() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "m size: " << mstack.size() << std::endl;
	std::stack<int> s(mstack);
	std::cout << "s size: " << s.size() << std::endl;
	return 0;
}