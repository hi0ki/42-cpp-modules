#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "-------------" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "------ second test ------" << std::endl;
	MutantStack<int>::reverse_iterator it1 = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite1 = mstack.rend();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";;
		++it1;
	}
	std::cout << std::endl;
	return 0;
}