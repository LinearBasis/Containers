#pragma once

#include <iostream>
#include <string>
#include "IteratorTraits.hpp"
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


// vector

// typedef RandomAccessIteratorTag<T, const_pointer, const_reference>


// template <class T, class trais = IteratorTraits<T*> >
template <class T, class P = T*, class R = T&, class diff = ptrdiff_t>
class RandomAccessIterator : public iterator<T, RandomAccessIteratorTag>
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
	{
		return RandomAccessIterator<T, const T*, const T&>(_curr);
	}

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
	{
		return (*(this->_curr));
	}

	bool					operator==(const RandomAccessIterator& iter) const
	{
		return (this->_curr == iter._curr);
	}

	bool					operator!=(const RandomAccessIterator& iter) const
	{
		return (this->_curr != iter._curr);
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

	RandomAccessIterator<T>	operator--(int)
	{
		RandomAccessIterator<T>	ret(*this);

		--this->_curr;
		return (ret);
	}

	bool					operator>(const RandomAccessIterator& iter) const
	{
		return (this->_curr > iter._curr);
	}

	bool					operator<(const RandomAccessIterator& iter) const
	{
		return (this->_curr < iter._curr);
	}

	bool					operator>=(const RandomAccessIterator& iter) const
	{
		return (this->_curr >= iter._curr);
	}

	bool					operator<=(const RandomAccessIterator& iter) const
	{
		return (this->_curr <= iter._curr);
	}

	RandomAccessIterator<T>&	operator+=(int n)
	{
		this->_curr += n;
		return (*this);
	}

	RandomAccessIterator		operator+(int n) const
	{
		RandomAccessIterator<T>	ret(*this);

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
		RandomAccessIterator<T>	ret(*this);

		ret -= n;
		return (ret);
	}

	difference_type	operator-(const RandomAccessIterator<T>& iter)
	{
		return (std::distance(iter, *this));
	}

	reference				operator[](int n)
	{
		RandomAccessIterator<T>	ret(*this);
	
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
//___________________________________________________


template <class iter>
class reverse_iterator
	: public iterator<typename ft::iterator_traits<iter>::value_type, typename ft::iterator_traits<iter>::iterator_category>
{
	typedef typename iterator_traits<iter>::pointer pointer;
	typedef typename iterator_traits<iter>::reference reference;
	typedef typename iterator_traits<iter>::difference_type difference_type;
private:
	iter	_iter;
public:
	iter	base()
	{
		iter	ans(_iter);
		ans++;
		return (ans);
	}

	reverse_iterator() : _iter(nullptr)
	{
	}

	reverse_iterator(pointer p) : _iter(p)
	{
	}

	template <class U>
		reverse_iterator(const reverse_iterator<U>& copy) : _iter(copy.base())
	{
	}

	~reverse_iterator()
	{
	}

	reverse_iterator&	operator=(const reverse_iterator& copy)
	{
		if (this == &copy)
			return (*this);
		this->_iter = copy._iter;
		return (*this);
	}

	reverse_iterator&	operator++(void)
	{
		--_iter;
		return (*this);
	}

	reverse_iterator	operator++(int)
	{
		reverse_iterator	ret(*this);

		--_iter;
		return (ret);
	}

	reference	operator*() const
	{
		return (*(this->_iter));
	}

	bool					operator==(const reverse_iterator& right) const
	{
		return (this->_iter == right._iter);
	}

	bool					operator!=(const reverse_iterator& right) const
	{
		return (this->_iter != right._iter);
	}

	pointer					operator->()
	{
		return (this->_iter->_curr);
	}

	reverse_iterator&	operator--(void)
	{
		++_iter;
		return (*this);
	}

	reverse_iterator	operator--(int)
	{
		reverse_iterator	ret(*this);

		++_iter;
		return (ret);
	}

	bool					operator>(const reverse_iterator& right) const
	{
		return (this->_iter > right._iter);
	}

	bool					operator<(const reverse_iterator& right) const
	{
		return (this->_iter < right._iter);
	}

	bool					operator>=(const reverse_iterator& right) const
	{
		return (this->_iter >= right._iter);
	}

	bool					operator<=(const reverse_iterator& right) const
	{
		return (this->_iter <= right._iter);
	}

	reverse_iterator&	operator+=(int n)
	{
		this->_iter -= n;
		return (*this);
	}

	reverse_iterator		operator+(int n) const
	{
		reverse_iterator	ret(*this);

		ret += n;
		return (ret);
	}

	reverse_iterator&	operator-=(int n)
	{
		this->_iter += n;
		return (*this);
	}

	reverse_iterator	operator-(int n)
	{
		reverse_iterator	ret(*this);

		ret -= n;
		return (ret);
	}

	difference_type	operator-(const reverse_iterator& right)
	{
		return (std::distance(right._iter, this->iter));
	}

	reference				operator[](int n)
	{
		reverse_iterator	ret(*this);

		ret -= n;
		return (*ret);
	}

	friend
	reverse_iterator		operator+(int n, const reverse_iterator& right);
	friend
	reverse_iterator		operator-(int n, const reverse_iterator& right);
};


template <class T>
reverse_iterator<T>	operator+(int n, const reverse_iterator<T>& right)
{
	reverse_iterator<T>	ret(right);

	ret += n;
	return (ret);
}

template <class T>
reverse_iterator<T>	operator-(int n, const reverse_iterator<T>& right)
{
	reverse_iterator<T>	ret(right);

	ret -= n;
	return (ret);
}


}