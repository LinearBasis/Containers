#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "hdrs/rbtree.hpp"
#include "hdrs/rbiter.hpp"

using namespace std;

int		main()
{
	red_black_tree<int>	tree;

	for (int i = 0; i < 10; i++)
	{
		tree.add(rand() % 80);
	}
	tree.print();

	// tree.print();
	red_black_tree<int>::const_iterator iter = tree.begin();
	for (; iter != tree.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	iter--;
	std::cout << "_________" << std::endl;
	while (true)
	{
		std::cout << *iter << std::endl;
		if (iter == tree.begin())
		{
			break ;
		}
		iter--;
	}
}