#ifndef	ARRAY_HPP
	#define ARRAY_HPP

	#include <iostream>


	template <typename T>
	class Array
	{
		private:
			T *elements;
			int elem_size;
		public:
			Array()
			{
				elem_size = 0;
				elements = new T[elem_size];
			}
			Array(unsigned int n)
			{
				elem_size = n;
				elements = new T[elem_size];
			}
			Array(Array &obj)
			{
				if (this != &obj)
				{
					this->elem_size = 0;
					this->elements = new T[this->elem_size];
					*this = obj;
				}
			}
			~Array()
			{
				if (elements)
					delete[] elements;
			}

			Array &operator=(Array &obj)
			{
				if (this != &obj)
				{
					if (elements)
						delete[] elements;
					this->elem_size = obj.elem_size;
					this->elements = new T[this->elem_size];
					for (int i = 0; i < this->elem_size ; i++)
						this->elements[i] = obj.elements[i];
				}
				return *this;
			}


			int size() const
			{
				return (this->elem_size);
			}


			class Indexouterr : public std::exception
			{
				public:
					const char *what() const throw()
					{
						return "the index inside the subscript is out of ur access";
					}
			};

			T &operator[](int i)
			{
				
				if (i >= this->elem_size || i < 0)
				{
					throw Indexouterr();
				}
				return  elements[i];
			}
	};
#endif