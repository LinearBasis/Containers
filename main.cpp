#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int		main()
{
	std::vector<int>	vec(5);
	for (int i = 0; i < 5; i++)
	{
		vec[i] = i;
	}
	std::vector<int>::reverse_iterator	a = vec.rbegin();
	while (a != vec.rend())
	{
		std::cout << *a;
		a++;
	}
	std::cout << "____" << std::endl;
	a--;
	std::cout << *a << std::endl;
	std::cout << "____" << std::endl;
	std::vector<int>::iterator b = a.base();
	while (b != vec.end())
	{
		std::cout << *b;
		b++;
	}
}