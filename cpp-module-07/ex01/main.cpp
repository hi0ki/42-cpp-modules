#include "iter.hpp"

void printelement(std::string &element) {
    std::cout << element << std::endl;
}

int main()
{
	std::string arr[3] = {"mehdi", "el ansary", "20"};
	::iter(arr, 3, printelement);
}