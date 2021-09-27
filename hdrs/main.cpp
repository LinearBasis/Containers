#include "Vector.hpp"
// #include <map>
// #include <iterator>
#include <vector>
#include <string>
using namespace std;

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
void	assign_test()
{
	vec<int>	asd;

	for (int i = 0; i < 6; i++)
	{
		asd.push_back(i);
	}
	vec<int>	bef(2, 4);
	for (int i = 0; i < bef.size(); i++)
	{
		cout << bef[i] << " ";
	}
	cout << " | ";
	bef.assign(asd.begin() + 1, asd.end() - 1);
	for (int i = 0; i < bef.size(); i++)
	{
		cout << bef[i] << " ";
	}

	cout << " | ";
	bef.assign(7, 4);
	for (int i = 0; i < bef.size(); i++)
	{
		cout << bef[i] << " ";
	}
	cout << endl;
}



int	main()
{
	// iter_test<ft::vector>("asd");
	// third_test<ft::vector>();
	// a<ft::vector>();
	assign_test<ft::vector>();
}