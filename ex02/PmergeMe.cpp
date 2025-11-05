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

std::vector<size_t> computeJacobSequence(size_t size)
{
    std::vector<size_t> Jacob_seq;
    Jacob_seq.push_back(0);
    Jacob_seq.push_back(1);
    
    while (true)
    {
        size_t next = Jacob_seq[Jacob_seq.size() - 1] + 2 * Jacob_seq[Jacob_seq.size() - 2];
        if (next > size)
            break;
        Jacob_seq.push_back(next);
    }
    
    return Jacob_seq;
}

// void binaryInsert(std::vector<int>& arr, int value, size_t start, size_t end)
// {
	
// }

std::vector<int> mergeInsertV(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return arr;
	std::cout << "size ========================= " << arr.size() << std::endl;
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
		main_chain.push_back(pairs[i].second);
	main_chain = mergeInsertV(main_chain);
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (main_chain[i] == pairs[j].second)
			{
				pend_chain.push_back(pairs[j].first);
				break;
			}
		}
	}
	if (arr.size() % 2 != 0)
		pend_chain.push_back(arr[arr.size() - 1]);
	if (!pend_chain.empty())
		main_chain.insert(main_chain.begin(), pend_chain[0]);
	std::cout << "Pending chain: " << std::endl;
		std::cout << "size " << pend_chain.size() << std::endl;
	std::vector<size_t> seq = computeJacobSequence(pend_chain.size());

	std::vector<size_t> new_seq;
	for (size_t i = 1; i < seq.size(); i++)
	{
		size_t courrent = seq[i];
		size_t prev = seq[i - 1];
		for (size_t j = courrent; j > prev; j--)
			new_seq.push_back(j);
	}

	for (size_t i = pend_chain.size()-1;  i > seq[seq.size() - 1]; i++)
	{
		new_seq.push_back(i);
	}

	for(size_t i = 0; i < new_seq.size(); i++)
	{
		std::cout << new_seq[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < seq.size(); i++)
		std::cout << seq[i] << " ";
	std::cout << std::endl;
	return main_chain;
}

void PmergeMe::start()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;

	mergeInsertV(this->vec);
	std::cout << "After:  ";
	std::cout << std::endl;
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
}
