#ifndef ITER_HPP
	#define ITER_HPP

	#include <iostream>
	#include <string>

	template <typename T, typename U>
	void iter(T *array, int len, U func( T &))
	{
		int i = 0;
		while (len > i)
		{
			func(array[i]);
			i++;
		}
	}

#endif