#include <iostream>
#include <vector>
#include <stack>
#include <deque>

// template <typename T>
// class myclass : public std::stack<T>
// {

// };

// // class test
// // {
// // 	private:
// // 		int j;
// // 	public:
// // 		test(){ j = 10;}
// // 		class test1{
// // 			public:
// // 				void ft(test *obj)
// // 				{
// // 					obj->j = 20;
// // 				}
// // 		};
// // 		void print()
// // 		{
// // 			std::cout << j << std::endl;
// // 		}
// // };

// int main()
// {
// 	// std::stack<int> var;
// 	std::deque<int> var1;
// 	std::vector<int> var2;

// 	myclass<int> var;

// 	var.push(10);
// 	// std::cout << var.top() << std::endl;
// 	test obj;

	
// }

template <typename T>
void fun(T t)
{
	t.push_back(10);

	typename T::iterator it = t.begin();
}

int main()
{
	std::vector<int> var;

	fun(var);
}