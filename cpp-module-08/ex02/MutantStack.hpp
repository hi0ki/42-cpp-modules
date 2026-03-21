#ifndef MUTANTSTACK_HPP
	#define MUTANTSTACK_HPP

	#include <iostream>
	#include <stack>

	template <typename T>
	class MutantStack : public std::stack<T>
	{
		public:
			// defult constructor
			MutantStack() { std::cout << "MutantStack default constructor called" << std::endl; }
			// copy constructor
			MutantStack(MutantStack &obj)
			{
				std::cout << "MutantStack copy constructor called" << std::endl; 
				*this = obj;
			}
			// assignment operator
			MutantStack &operator=(MutantStack &obj)
			{
				std::cout << "MutantStack assignment operator called" << std::endl;
				if (this != &obj)
				{
					this->c = obj.c;
				}
				return *this;
			};
			// destructor
			~MutantStack() { std::cout << "MutantStack destructor called" << std::endl; };


			// typedefs for iterators
			typedef typename std::stack<T>::container_type::iterator iterator;
			typedef typename std::stack<T>::container_type::const_iterator const_iterator;
			typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
			typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
			// functions
			iterator begin() { return this->c.begin(); }
			const_iterator begin() const { return this->c.begin(); }

			iterator end() { return this->c.end(); }
			const_iterator end() const { return this->c.end(); }

			reverse_iterator rbegin() { return this->c.rbegin(); }
			const_reverse_iterator rbegin() const { return this->c.rbegin(); }

			reverse_iterator rend() { return this->c.rend(); }
			const_reverse_iterator rend() const { return this->c.rend(); }
	};


#endif