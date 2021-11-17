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

	red_black_tree<int>::const_reverse_iterator	iter2 = tree.rbegin();
	for (; tree.rend() != iter2; iter2++)
	{
		std::cout << *iter2 << std::endl;
	}
	
	// std::cout << *iter2 << std::endl;
	// std::cout <<  *tree.rend() << std::endl;
	// std::cout << (tree.rend() == iter2) << std::endl;
}