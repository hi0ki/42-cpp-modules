#include "C.hpp"
#include "B.hpp"
#include "A.hpp"
#include "Base.hpp"

int main()
{
	Base *base = new B();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "----------------" << std::endl;
	base = new C();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "----------------" << std::endl;
	base = new A();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "----------------" << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	delete base;

	return 0;
}