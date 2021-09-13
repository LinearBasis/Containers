#include "Vector.hpp"
// #include <map>
// #include <iterator>
#include <vector>
#include <string>

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	iter_test(std::string filename)
{
	std::vector<int>	nums;
	vec<int>			tested;

	for (int i = 0; i < 5; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < nums.size(); i++)
	{
		tested.push_back(nums[i]);
	}
	for (typename vec<int>::iterator iter = tested.begin(); iter != tested.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	for (typename vec<int>::reverse_iterator iter = tested.rbegin(); iter != tested.rend(); iter++)
	{
		std::cout << *iter << " ";
	}

	std::cout << std::endl;
	for (typename vec<int>::const_iterator iter = tested.begin(); iter != tested.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	for (typename vec<int>::const_reverse_iterator iter = tested.rbegin(); iter != tested.rend(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	third_test()
{
	vec<int>	tested(3, 5);

	for (typename vec<int>::const_iterator iter = tested.begin(); iter != tested.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	a()
{
	vec<int>	vector(5);
	for (int i = 0; i < 5; i++)
	{
		vector[i] = i;
	}
	typename vec<int>::reverse_iterator	a = vector.rbegin();
	while (a != vector.rend())
	{
		std::cout << *a;
		a++;
	}
	std::cout << "____" << std::endl;
	a--;
	std::cout << *a << std::endl;
	std::cout << "____" << std::endl;
	typename vec<int>::iterator b = a.base();
	b = a.base();
	while (b != vector.end())
	{
		std::cout << *b << " ";
		b++;
	}
	std::cout << std::endl;
}

int	main()
{
	ft::vector<int>		a;


	for (int i = 0; i < 5; i++)
		a.push_back(i);
	ft::vector<int>		b(3, 50);
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	// for (int i = 0; i < b.; i++)

}