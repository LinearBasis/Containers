#pragma once

#include <iostream>
#include <string>
#include "IteratorTraits.hpp"
#include "utils.hpp"
#include <stack>
namespace ft
{

template <class T, class Category, class Ptr = T*, class Ref = T&, class diff = ptrdiff_t>
struct iterator
{
	typedef diff		difference_type;
	typedef T			value_type;
	typedef Ptr			pointer;
	typedef Ref			reference;
	typedef Category	iterator_category;
};



template <class T, class P = T*, class R = T&, class diff = ptrdiff_t>
class RandomAccessIterator : public iterator<T, RandomAccessIteratorTag, P, R, diff>
{
public:
	typedef P pointer;
	typedef R reference;
	typedef diff difference_type;
private:
	pointer	_curr;
public:
	
	RandomAccessIterator()
	{
		this->_curr = nullptr;
	}

	RandomAccessIterator(pointer p)
	{
		this->_curr = p;
	}

	RandomAccessIterator(const RandomAccessIterator<T, P, R, diff>& copy)
	{
		this->_curr = copy._curr;
	}

	~RandomAccessIterator()
	{

	}

	RandomAccessIterator&	operator=(const RandomAccessIterator& copy)
	{
		if (this == &copy)
			return (*this);
		this->_curr = copy._curr;
		return (*this);
	}

	operator RandomAccessIterator<T, const T*, const T&>()
	{ return RandomAccessIterator<T, const T*, const T&>(_curr); }

	RandomAccessIterator&	operator++(void)
	{
		++this->_curr;
		return (*this);
	}

	RandomAccessIterator	operator++(int)
	{
		RandomAccessIterator	ret(*this);

		++this->_curr;
		return (ret);
	}

	reference	operator*() const
	{ return (*(this->_curr)); }

	friend bool	operator==(const RandomAccessIterator& left, const RandomAccessIterator& right)
	{
		return (left._curr == right._curr);
	}

	friend bool	operator!=(const RandomAccessIterator& left, const RandomAccessIterator& right)
	{
		return (left._curr != right._curr);
	}

	pointer					operator->()
	{
		return (this->_curr);
	}

	RandomAccessIterator&	operator--(void)
	{
		--this->_curr;
		return (*this);
	}

	RandomAccessIterator	operator--(int)
	{
		RandomAccessIterator	ret(*this);

		--this->_curr;
		return (ret);
	}

	bool					operator>(const RandomAccessIterator& iter) const
	{ return (this->_curr > iter._curr); }

	bool					operator<(const RandomAccessIterator& iter) const
	{ return (this->_curr < iter._curr); }

	bool					operator>=(const RandomAccessIterator& iter) const
	{ return (this->_curr >= iter._curr); }

	bool					operator<=(const RandomAccessIterator& iter) const
	{ return (this->_curr <= iter._curr); }

	RandomAccessIterator&	operator+=(int n)
	{
		this->_curr += n;
		return (*this);
	}

	RandomAccessIterator		operator+(int n) const
	{
		RandomAccessIterator	ret(*this);

		ret += n;
		return (ret);
	}

	RandomAccessIterator&	operator-=(int n)
	{
		this->_curr -= n;
		return (*this);
	}

	RandomAccessIterator	operator-(int n)
	{
		RandomAccessIterator	ret(*this);

		ret -= n;
		return (ret);
	}

	difference_type	operator-(const RandomAccessIterator<T>& iter)
	{
		return (std::distance(iter._curr, this->_curr));
	}

	reference				operator[](int n)
	{
		RandomAccessIterator	ret(*this);
	
		ret += n;
		return (*ret);
	}

	friend
		RandomAccessIterator<T>		operator+(int n, const RandomAccessIterator<T>& iter);
	friend
		RandomAccessIterator<T>		operator-(int n, const RandomAccessIterator<T>& iter);
};


template <class T>
RandomAccessIterator<T>	operator+(int n, const RandomAccessIterator<T>& iter)
{
	RandomAccessIterator<T>	ret(iter);

	ret += n;
	return (ret);
}

template <class T>
RandomAccessIterator<T>	operator-(int n, const RandomAccessIterator<T>& iter)
{
	RandomAccessIterator<T>	ret(iter);

	ret -= n;
	return (ret);
}


template<class Iterator>
class reverse_iterator
{
public:
	typedef
		Iterator
		iterator_type;
	typedef
		typename ft::iterator_traits<Iterator>::iterator_category
		iterator_category;
	typedef
		typename ft::iterator_traits<Iterator>::value_type
		value_type;
	typedef
		typename ft::iterator_traits<Iterator>::difference_type
		difference_type;
	typedef
		typename ft::iterator_traits<Iterator>::pointer
		pointer;
	typedef
		typename ft::iterator_traits<Iterator>::reference
		reference;

	/* Constructors and destructor */
	reverse_iterator( void )
		: _iter()
	{}

	reverse_iterator( iterator_type x)
		: _iter(x)
	{}

	template<class U>
	reverse_iterator( const reverse_iterator<U>& other)
		: _iter(other.base())
	{}

	~reverse_iterator( void )
	{}

	/* Assignment overload */
	template<class U>
	reverse_iterator&   operator=( const reverse_iterator<U>& other)
	{
		this->_iter = other.iter;
	}

	/* Base */
	iterator_type   base() const    { return this->_iter; }

	/* Data access */
	reference       operator*(void)         { return *(this->_iter); }
	const reference operator*(void) const   { return *(this->_iter); }
	
	pointer         operator->(void)        { return &(*this->_iter); }
	const pointer   operator->(void) const  { return &(*this->_iter); }
	
	reference       operator[](const difference_type& m)
	{ return this->_iter[-m - 1]; }
	const reference operator[](const difference_type& m) const
	{ return this->_iter[-m - 1]; }

	/* Arifmetics operators */
	reverse_iterator& operator++(void)
	{
		--this->_iter;
		return (*this);
	}

	reverse_iterator& operator--(void)
	{
		++this->_iter;
		return (*this);
	}
	
	reverse_iterator operator++(int)
	{
		reverse_iterator  tmp(*this);
		--this->_iter;
		return (tmp);
	}
	
	reverse_iterator operator--(int)
	{
		reverse_iterator  tmp(*this);
		++this->_iter;
		return (tmp);
	}

	reverse_iterator& operator+=(const difference_type& m)
	{
		this->_iter -= m;
		return (*this);
	}

	reverse_iterator& operator-=(const difference_type& m)
	{
		this->_iter += m;
		return (*this);
	}

	reverse_iterator operator+(const difference_type& m) const
	{
		return (this->_iter - m);
	}

	reverse_iterator operator-(const difference_type& m) const
	{
		return (this->_iter + m);
	}

private:
	iterator_type    _iter;

};

/* compares overloads
	
	each compare has two overloads for <T> and <T, U>
	for compare <T, const T>.
*/
// ==
template<typename T>
bool    operator==(const reverse_iterator<T>& first,
					const reverse_iterator<T>& second)
{
	return (first.base() == second.base());
}

template<typename T, typename U>
bool    operator==(const reverse_iterator<T>& first,
					const reverse_iterator<U>& second)
{
	return (first.base() == second.base());
}

// !=
template<typename T>
bool    operator!=(const reverse_iterator<T>& first,
					const reverse_iterator<T>& second)
{
	return (first.base() != second.base());
}

template<typename T, typename U>
bool    operator!=(const reverse_iterator<T>& first,
					const reverse_iterator<U>& second)
{
	return (first.base() != second.base());
}

// >=
template<typename T>
bool    operator>=(const reverse_iterator<T>& first,
					const reverse_iterator<T>& second)
{
	return (first.base() <= second.base());
}

template<typename T, typename U>
bool    operator>=(const reverse_iterator<T>& first,
					const reverse_iterator<U>& second)
{
	return (first.base() <= second.base());
}

// <=
template<typename T>
bool    operator<=(const reverse_iterator<T>& first,
					const reverse_iterator<T>& second)
{
	return (first.base() >= second.base());
}

template<typename T, typename U>
bool    operator<=(const reverse_iterator<T>& first,
					const reverse_iterator<U>& second)
{
	return (first.base() >= second.base());
}

// >
template<typename T>
bool    operator>(const reverse_iterator<T>& first,
					const reverse_iterator<T>& second)
{
	return (first.base() < second.base());
}

template<typename T, typename U>
bool    operator>(const reverse_iterator<T>& first,
					const reverse_iterator<U>& second)
{
	return (first.base() < second.base());
}

// <
template<typename T>
bool    operator<(const reverse_iterator<T>& first,
					const reverse_iterator<T>& second)
{
	return (first.base() > second.base());
}

template<typename T, typename U>
bool    operator<(const reverse_iterator<T>& first,
					const reverse_iterator<U>& second)
{
	return (first.base() > second.base());
}

/* non-member afirmetic functions */
template<typename T>
reverse_iterator<T> operator+(
	const typename reverse_iterator<T>::difference_type& m,
	const reverse_iterator<T>& iter)
{
	return (iter.base() - m);
}

template<typename T>
typename reverse_iterator<T>::difference_type
operator-(const reverse_iterator<T>& first,
			const reverse_iterator<T>& second)
{
	return (second.base() - first.base());
}

template<typename T, typename U>
typename reverse_iterator<T>::difference_type
operator-(const reverse_iterator<T>& first,
			const reverse_iterator<U>& second)
{
	return (second.base() - first.base());
}

}