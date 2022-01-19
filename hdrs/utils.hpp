#pragma once
#include <cstddef>

namespace ft
{


template <class T>
void	swap(T &a, T &b)
{
	T	x = a;
	a = b;
	b = x;
}

template <class InputIterator>
ptrdiff_t	distance(InputIterator begin, InputIterator end)
{
	ptrdiff_t	counter = 0;
	while (begin != end)
	{
		begin++;
		counter++;
	}
	return (counter);
}

template <bool B, class T=void> struct enable_if
{
	typedef T type;
};

template <class T> struct enable_if<true, T>
{
	typedef T type;
};

template <class T> struct enable_if<false, T>
{
	typedef void type;
};

template <class T> struct is_integral
{
	static const bool   value = false;
};

template <> struct is_integral<bool>
{
	static const bool   value = true;
};

template <> struct is_integral<char>
{
	static const bool   value = true;
};

template <> struct is_integral<char16_t>
{
	static const bool   value = true;
};

template <> struct is_integral<char32_t>
{
	static const bool   value = true;
};

template <> struct is_integral<wchar_t>
{
	static const bool   value = true;
};

template <> struct is_integral<signed char>
{
	static const bool   value = true;
};

template <> struct is_integral<short int>
{
	static const bool   value = true;
};

template <> struct is_integral<int>
{
	static const bool   value = true;
};

template <> struct is_integral<long int>
{
	static const bool   value = true;
};

template <> struct is_integral<long long int>
{
	static const bool   value = true;
};

template <> struct is_integral<unsigned char>
{
	static const bool   value = true;
};

template <> struct is_integral<unsigned short int>
{
	static const bool   value = true;
};

template <> struct is_integral<unsigned int>
{
	static const bool   value = true;
};

template <> struct is_integral<unsigned long int>
{
	static const bool   value = true;
};

template <> struct is_integral<unsigned long long int>
{
	static const bool   value = true;
};

template <class T>
struct less
{
	bool operator()( const T& lhs, const T& rhs ) const
	{ return (lhs < rhs); }
};














};