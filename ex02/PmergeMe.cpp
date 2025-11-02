#include "PmergeMe.hpp"
#include <unistd.h>
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char *av[])
{
	std::string str;
	for (int i = 1; i < ac; i++)
	{
		str = av[i];
		for (size_t j = 0; j < str.length(); j++)
		{
			if (!isdigit(str[j]) && !(j == 0 && str[j] == '-'))
				throw std::invalid_argument("Error: Non-integer value provided.");
		}
		long num = std::stol(str);
		if (num < 0 || num > 2147483647)
			throw std::out_of_range("Error: Integer value out of range.");
		this->vec.push_back(num);
		this->deq.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()   {}

// Utils

std::vector<int> mergeInsertV(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return arr;
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	// print the pairs
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
	std::cout << std::endl;
	std::vector<int> main_chain;
	std::vector<int> pend_chain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].second);
		pend_chain.push_back(pairs[i].first);
	}
	if (arr.size() % 2 != 0)
		pend_chain.push_back(arr[arr.size() - 1]);
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < pend_chain.size(); i++)
		std::cout << pend_chain[i] << " ";
	std::cout << "\n" << "---------------------\n" << std::endl;
	main_chain = mergeInsertV(main_chain);
	if (pend_chain.size())
		main_chain.insert(main_chain.begin(), pend_chain[0]);
	for (size_t i = 1; i < pend_chain.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), 
														main_chain.end(), 
														pend_chain[i]);
		main_chain.insert(it, pend_chain[i]);
	}
	arr = main_chain;
	std::cout << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return arr;
}

void PmergeMe::start()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;

	mergeInsertV(this->vec);
}