// #include <map>
// #include <iterator>
// #include <vector>
// #include <string>
// #include <iostream>
#include "vector.hpp"
#include <vector>


using std::cout;
using std::endl;


int	main()
{
	ft::vector<int>	a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for (ft::vector<int>::const_reverse_iterator iter = a.rbegin(); a.rend() != iter; iter++)
	{
		std::cout << *iter << std::endl;
	}
}