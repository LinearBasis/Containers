#include "Vector.hpp"
// #include <map>
// #include <iterator>
#include <vector>
#include <string>

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	test(std::string filename)
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

	for (typename vec<int>::const_iterator iter = tested.rbegin(); iter != tested.rend(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

int	main()
{
	test<ft::Vector>(std::string("my_test"));
}