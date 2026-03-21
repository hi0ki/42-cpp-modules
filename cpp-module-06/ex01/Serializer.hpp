#ifndef SERIALIZER_HPP
	#define SERIALIZER_HPP

	#include <iostream>

	typedef struct s_data
	{
		std::string myname;
		int myage;
	} Data;

	class Serializer {
		private:
			Serializer();
			Serializer(Serializer &obj);
			~Serializer();
			Serializer &operator=(const Serializer &obj);
		public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
	};
#endif