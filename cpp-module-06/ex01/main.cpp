#include "Serializer.hpp"

int main()
{
	Data *data = new Data();
	data->myname = "John";
	data->myage = 42;
	uintptr_t var = Serializer::serialize(data);

	Data *data2 = Serializer::deserialize(var);
	std::cout << "Name2: " << data2->myname << std::endl;

	std::cout << "data address: " << data << std::endl;
	std::cout << "data2 address: " << data2 << std::endl;

	delete data;
	return 0;
}