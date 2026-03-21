#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {

}

Base * generate(void)
{
	srand(time(NULL));
	if (rand() % 3 == 0)
		return new A();
	else if (rand() % 3 == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Invalid type" << std::endl;
}
void identify(Base& p)
{
	int i = 3;
	while (i > 0)
	{
		try
		{
			Base var;
			switch (i)
			{
				case 1:
					var = dynamic_cast<A &>(p);
					std::cout << "Class A" << std::endl;
					return ;
				case 2:
					var = dynamic_cast<B &>(p);
					std::cout << "Class B" << std::endl;
					return ;
				case 3:
					var = dynamic_cast<C &>(p);
					std::cout << "Class C" << std::endl;
					return ;
			}

		}
		catch (std::exception &e)
		{
		}
		i--;
	}
	std::cout << "Invalid type" << std::endl;
}