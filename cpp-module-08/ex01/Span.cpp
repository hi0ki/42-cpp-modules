#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->N = N;
	std::cout << "Constructor called!!" << std::endl;
}

Span::Span(const Span &obj)
{
	std::cout << "coppy constructor called!!" << std::endl;
	*this = obj;
}

void Span::addNumber(unsigned int num)
{
	if (this->numbers.size() < this->N)
		numbers.push_back(num);
	else
		throw std::runtime_error("Span is full, cannot add more numbers.");
}

int Span::shortestSpan()
{
	int result;

	if (numbers.empty() || numbers.size() == 1)
		throw std::runtime_error("there is no number in the span");
	result = abs(numbers[0] - numbers[1]);
	for (int i = 1; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size(); j++)
		{
			if (j != i && abs(numbers[j] - numbers[i]) < result)
				result = abs(numbers[j] - numbers[i]);
		}
	}
	return result;
}

int Span::longestSpan()
{
	int size = numbers.size();
	if (numbers.empty() || size == 1)
		throw std::runtime_error("there is no number in the span");
	std::sort(numbers.begin(), numbers.end());
	int result = numbers[size - 1] - numbers[0];
	return result;
}


Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->N = obj.N;
	}
	std::cout << "assignation operator called!!" << std::endl;
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor called!!" << std::endl;
}
