#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "hdrs/rbtree.hpp"

using namespace std;

int		main()
{
	red_black_tree<int>	tree;

	tree.add(13);
	tree.add(25);
	tree.add(2);
	tree.add(3);
	// tree.add(1);
	// tree.add(2);

	tree.print();

}