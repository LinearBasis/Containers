#include "vector.hpp"
// #include <map>
// #include <iterator>
#include <vector>
#include <string>
using namespace std;
#include "tests.hpp"

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

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	erase_test()
{
	vec<int>	asd;
	
	// for (int i = 0; i < 6; i++)
	// {
	// 	asd.push_back(i);
	// }
	auto iter = asd.erase(asd.begin(), asd.end());

	// cout << *iter << endl;

	for (auto &i : asd)
	{
		cout << i << " ";
	}
	cout << endl;
}

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	insert_test()
{
	vec<int>	asd;

	asd.insert(asd.begin(), 2, 13);
	cout << *asd.insert(asd.end() - 1, 12) << endl;
	for (auto &i : asd)
	{
		cout << i << " ";
	}
	cout << endl << endl;

	vec<int>	bef;

	bef.insert(bef.end(), 3);
	bef.insert(bef.end(), 2);
	bef.insert(bef.end(), 2);
	bef.insert(bef.end(), 4);


	asd.insert(asd.end() - 5, bef.begin(), bef.end());

	for (int i = 0; i < asd.size(); i++)
	{
		cout << asd[i] << " ";
	}
	cout << endl << endl;
}

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	reserve_test()
{
	vec<int>	asd;

	asd.push_back(1);
	asd.push_back(2);
	asd.push_back(3);
	asd.push_back(4);
	asd.push_back(5);


	for (auto i : asd)
	{
		cout << i << " ";
	}
	cout << endl;
	asd.reserve(5);
	cout << asd.capacity() << endl;
	asd.reserve(8);
	cout << asd.capacity() << endl;
	asd.reserve(12);
	cout << asd.capacity() << endl;
}

template <template <typename T, class _allocator = std::allocator<T> >  class vec>
void	resize_test()
{
	vec<int>	asd;

	asd.resize(2, 4);
	for (auto i : asd)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << asd.capacity() << endl << endl;
	asd.resize(1, 4);


	for (auto i : asd)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << asd.capacity() << endl << endl;

	asd.resize(5, 3);

	for (auto i : asd)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << asd.capacity() << endl << endl;	



}


int	main()
{
	// iter_test<ft::vector>("asd");
	// third_test<ft::vector>();
	// a<ft::vector>();
	// erase_test<ft::vector>();
	// cout << "___________" << endl;
	// erase_test<std::vector>();


	// ft_vector_tests();
	// resize_test<ft::vector>();


	ft_vector_tests();



	// ft::vector<int>	a(12, 5);
	// ft::vector<int>	b(12, 5);

	// std::cout << (a == b) << std::endl;
}