#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
	int easyfind(T var, int num)
	{
		int i = 0;

		i = distance(var.begin(), find(var.begin(), var.end(), num));
		if (num != var[i])
			throw std::runtime_error("No occurrence is found!!");
		return (i);
	}

#endif