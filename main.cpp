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

	// std::map<const int, const int> m;

	// m[1];
	// m[2];
	red_black_tree<const int>	tree;

	for (int i = 0; i < 10; i++)
	{
		int a = rand() % 80;
		std::cout << a << std::endl;
		tree.add(a);
	}
	tree.print();

	// tree.print();
	red_black_tree<const int>::const_iterator iter = tree.begin();
	for (; iter != tree.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	iter--;
	std::cout << "_________" << std::endl;

	red_black_tree<const int>::const_reverse_iterator	iter2 = tree.rbegin();
	std::cout << "reverse_print: \n";
	for (; tree.rend() != iter2; iter2++)
	{
		std::cout << *iter2 << std::endl;
	}
	
	std::cout << "metadata print: \n";
	std::cout << *iter2 << std::endl;
	std::cout <<  *tree.rend() << std::endl;
	std::cout << (tree.rend() == iter2) << std::endl;
}