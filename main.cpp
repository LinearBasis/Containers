#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <time.h>
#include "hdrs/map.hpp"
#include "hdrs/stack.hpp"

#include "hdrs/rbtree.hpp"
#include "hdrs/vector.hpp"
// #include "hdrs/rbiter.hpp"

using namespace std;


bool	equal(std::map<int, const int> m1, ft::map<int, const int> m2)
{
	auto i = m1.begin();
	auto j = m2.begin();

	while (i != m1.end() && j != m2.end())
	{
		if (i->first != j->first || i->second != j->second)
			return false;
		i++;
		j++;
	}
	if (i != m1.end() || j != m2.end())
		return false;
	return true;
}



void	map_test()
{
	std::map<int, const int>	m1;
	ft::map<int, const int>		m2;
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 7;
		m1.insert(std::make_pair(x, i));
		m2.insert(ft::make_pair(x, i));

		if (!equal(m1, m2))
		{
			std::cout << "ERROR" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 7 + (i + 1) * 7;
		m1.insert(std::make_pair(x, i));

		if (equal(m1, m2))
		{
			std::cout << "ERROR while add rand nums to 1, before to 2" << std::endl;
			return ;
		}
		m2.insert(ft::make_pair(x, i));
	}

	ft::map<int, int>	numbers_to_delete;
	for (int i = 0; i < m1.size(); i++)
	{
		if (rand() % 25 > 12)
			numbers_to_delete[i] = 1;
	}
	auto i = m1.begin();
	auto j = m2.begin();
	for (int n = 0; n < m1.size(); n++)
	{
		if (numbers_to_delete[n] == 1 && m1.end() != i && m2.end() != j)
		{
			auto i1 = i;
			auto j1 = j;
			i1++;
			j1++;
			m1.erase(i);
			m2.erase(j);
			i = i1;
			j = j1;
		}
		if (m1.end() != i)
			i++;
		if (m2.end() != j)
			j++;
	}
	if (j != m2.end() || i != m1.end())
	{
		std::cout << "ERROR" << std::endl;
		return ;
	}
	if (!equal(m1, m2))
	{
		std::cout << "ERROR" << std::endl;
		return ;
	}
	std::cout << "all is okay" << std::endl;
}



void	stack_test()
{
	ft::stack<int>	x;
	std::stack<int>	y;

	for (int i = 0; i < 15; i++)
	{
		int z = rand() % 15;
		x.push(z);
		if (x.top() != z)
		{
			std::cout << "ERROR" << std::endl;
			return;
		}
	}
	if (x.size() != 15)
	{
		std::cout << "ERROR" << std::endl;
		return;
	}
	while (x.size() != 0)
	{
		x.pop();
	}
	if (x.empty())
		std::cout << "all okay\n";
	else
		std::cout << "error\n";
}


int		main()
{
	// map_test();
	// stack_test();
	// srand(1642617733);
	// ft::vector<int>	a;
	// std::vector<int>	b;

	// for (int i = 0; i < 50; i++)
	// {
	// 	int x = rand() % 50;
	// 	a.push_back(x);
	// 	b.push_back(x);
	// }
	// auto i1 = a.begin();
	// auto i2 = b.begin();

	// for (int i = 0; i < a.size(); i++, i1++, i2++)
	// {
	// 	if (rand() % 50 > 35)
	// 	{
	// 		a.erase(i1);
	// 		b.erase(i2);
	// 	}
	// }

	// if (a.size() != b.size())
	// 	std::cout << "ERROR\n";
	// for (int i = 0; i < a.size(); i++)
	// {
	// 	if (a[i] != b[i])
	// 	{
	// 		std::cout << "ERROR\n";
	// 		break ;
	// 	}
	// }



	// ft::_RB_tree<int>	a;

	// // a.push(1);
	// // a.erase(1);
	// // a.erase(1);
	// // a.erase(1);
	// // a.print();
	// time_t	time_seed = time(nullptr);
	// std::cout << time_seed << std::endl;
	// for (int i = 0; i < 50; i++)
	// 	a.push(rand() % 12);
	
	

	// vector<ft::_RB_tree<int>::iterator>	vec;

	// for (auto i = a.begin(); i != a.end(); ++i)
	// {
	// 	if (rand() % 50 > 32)
	// 		vec.push_back(i);
	// }
	// for (auto i : vec)
	// 	a.erase(i);

	// for (ft::_RB_tree<int>::const_reverse_iterator i = a.rbegin(); i != a.rend(); i++)
	// {
	// 	std::cout << *i << std::endl;
	// }
	// a.print();
	// std::cout << "is_rbtree:" << a.is_red_black_tree() << std::endl;
}