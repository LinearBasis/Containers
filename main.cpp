#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <time.h>

#include "hdrs/rbtree.hpp"
// #include "hdrs/rbiter.hpp"

using namespace std;


int		main()
{
	ft::_RB_tree<int>	a;
	// time_t	time_seed = time(nullptr);
	srand(1642617733);
	// std::cout << time_seed << std::endl;
	for (int i = 0; i < 50; i++)
		a.push(rand() % 12);
	

	vector<ft::_RB_tree<int>::iterator>	vec;

	for (auto i = a.begin(); i != a.end(); ++i)
	{
		if (rand() % 50 > 12)
			vec.push_back(i);
	}
	for (auto i : vec)
		a.erase(i);

	for (ft::_RB_tree<int>::const_reverse_iterator i = a.rbegin(); i != a.rend(); i++)
	{
		std::cout << *i << std::endl;
	}
	a.print();
	std::cout << "is_rbtree:" << a.is_red_black_tree() << std::endl;
}