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
	srand(time(nullptr));

	const int	size = rand() % 283 + rand() % 111;
	std::vector<int>	a;
	for (int i = 0; i < size; i++)
	{
		int k = rand() % size;
		a.push_back(k);
		tree.add(k);
		std::cout << std::boolalpha;
		if (!tree.is_red_black_tree())
		{
			break ;
		}
	}
	if (a.size() != size)
	{
		std::cout << "BAN" << std::endl;
		for (int i = 0; i < a.size(); i++)
		{
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "OKAY GOOD BOOMER" << std::endl;
	}


	// tree.add(7);
	// tree.add(49);
	// tree.add(23);
	// tree.add(8);
	// tree.add(130);
	// tree.add(122);
	// tree.add(144);
	// tree.add(128);
	// // tree.add(23);
	// tree.add(109);
	// tree.add(90);
	// std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	// tree.add(65);
	// std::cout << std::boolalpha;
	// std::cout << tree.is_red_black_tree() << std::endl;
	// tree.print();
}