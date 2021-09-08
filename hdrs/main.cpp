#include "Vector.hpp"
// #include <map>
// #include <iterator>
// #include <vector>


class A
{
private:
public:
	int	k;
	A();
	A(const A& copy);
	~A();
	
	A&	operator=(const A& copy);
};

A::A()
{
	std::cout << "ha" << std::endl;
	this->k = 6;
}

A::A(const A& copy)
{
	this->k = 6;
}

A::~A()
{
	std::cout << "destr" << std::endl;
}

A&	A::operator=(const A& copy)
{
	if (this == &copy)
		return (*this);
	std::cout  << "he" << std::endl;

}



int	main()
{
	ft::Vector<A>	asd;

	for (int i = 0; i < 100; i++)
	{
		asd.push_back(A());
	}
	std::cout << "HERE_____________________\n";
}