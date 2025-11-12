#include "PmergeMe.hpp"
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
		long num = std::atol(str.c_str());
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

// get the jacob sequence order
std::vector<size_t> computeJacobSequence(size_t size)
{
    std::vector<size_t> seq;
    seq.push_back(0);
    seq.push_back(1);
    
    while (true)
    {
        size_t next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        if (next >= size)
            break;
        seq.push_back(next);
    }
    
	std::vector<size_t> new_seq;
	for (size_t i = 1; i < seq.size(); i++)
	{
		size_t courrent = seq[i];
		size_t prev = seq[i - 1];
		for (size_t j = courrent; j > prev; j--)
			new_seq.push_back(j);
	}
	for (size_t i = size - 1;  i > seq[seq.size() - 1]; i--)
		new_seq.push_back(i);
    return new_seq;
}

// binary insert
void binaryInsert(std::vector<int> &arr, int value)
{
	std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(it, value);
}

void binaryInsert(std::deque<int> &arr, int value)
{
	std::deque<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(it, value);
}


template<typename T>
T mergeInsert(T arr)
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
	T main_chain;
	for (size_t i = 0; i < pairs.size(); i++)
	main_chain.push_back(pairs[i].second);
	main_chain = mergeInsert(main_chain);

	T pend_chain;
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (main_chain[i] == pairs[j].second)
			{
				pend_chain.push_back(pairs[j].first);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	if (arr.size() % 2 != 0)
		pend_chain.push_back(arr[arr.size() - 1]);
	if (!pend_chain.empty())
		main_chain.insert(main_chain.begin(), pend_chain[0]);
	if (pend_chain.size() <= 1)
		return main_chain;

	std::vector<size_t> sequence_order = computeJacobSequence(pend_chain.size());
	for (size_t i = 0; i < sequence_order.size(); i++)
	{
		size_t index = sequence_order[i];
		binaryInsert(main_chain, pend_chain[index]);
	}

	return (main_chain);
}

double get_the_time(struct timeval& start)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
}

void PmergeMe::start()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;

	double time_vec = 0;
	double time_deq = 0;
	size_t elements = this->vec.size();
	struct timeval start;
	gettimeofday(&start, NULL);

	// Vector Part
	this->vec = mergeInsert(this->vec);
	time_vec = get_the_time(start);

	// Deque Part
	gettimeofday(&start, NULL);
	this->deq = mergeInsert(this->deq);
	time_deq = get_the_time(start);

	std::cout << "After:  ";
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << elements << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << elements << " elements with std::deque  : " << time_deq << " us" << std::endl;
}
