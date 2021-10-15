#pragma once

namespace ft
{
template <class T1, class T2>
class pair
{
public:
	typedef T1 first_type;
	typedef T2 second_type;

	first_type  first;
	second_type second;


	pair() {}
	
	template<class U, class V>
	pair (const pair<U, V>& pr) : first(pr.first), second(pr.second)
	{
	}

	pair (const first_type& a, const second_type& b) : first(a), second(b)
	{
	}

	pair&	operator=(const pair& pr)
	{
		if (this == &pr)
			return (*this);
		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	}


};

template <class T1, class T2>
ft::pair<T1, T2>	make_pair(T1 first, T2 second)
{
	return (ft::pair<T1, T2>(first, second));
}


template <class T1, class T2>
bool	operator==(ft::pair<T1, T2> left, ft::pair<T1, T2> right)
{
	return (left.first == right.first && left.second == right.second);
}

template <class T1, class T2>
bool	operator!=(ft::pair<T1, T2> left, ft::pair<T1, T2> right)
{
	return (!(left == right));
}

template <class T1, class T2>
bool	operator<(ft::pair<T1, T2> left, ft::pair<T1, T2> right)
{
	return (left.first < right.first || (left.first == right.first && left.second < right.second));
}

template <class T1, class T2>
bool	operator<=(ft::pair<T1, T2> left, ft::pair<T1, T2> right)
{
	return (left < right || left == right);
}

template <class T1, class T2>
bool	operator>(ft::pair<T1, T2> left, ft::pair<T1, T2> right)
{
	return (!(left <= right));
}

template <class T1, class T2>
bool	operator>=(ft::pair<T1, T2> left, ft::pair<T1, T2> right)
{
	return (!(left < right));
}


}