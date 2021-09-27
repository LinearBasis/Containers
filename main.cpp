#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// std::is_integral<int>

class	A
{
public:
	int	k;
	A(const A& cpy)
	{
		k = cpy.k;
		cout << "4";
	}
	A(int i = 3)
	{
		k = i;
		cout << "3";
	}
};
std::ostream&	operator<<(std::ostream&out, const A& a)
{
	cout << a.k;
	return (out);
}

int		main()
{
	vector<A>	asd(0);
	for (int i = 0; i < 8; i++)
	{
		asd.push_back(A(i));
	}

	cout << endl << endl;
	asd.erase(asd.begin() + 2);
	cout << endl << endl;
	for (int i = 0; i < asd.size(); i++)
		cout << asd[i] << " ";
	cout << endl;
}