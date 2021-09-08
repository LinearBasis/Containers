#pragma once

#include <iostream>
#include <string>
#include "IteratorTraits.hpp"

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

	RandomAccessIterator(const RandomAccessIterator& copy)
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

	RandomAccessIterator&	operator++(void)
	{
		++this->_curr;
		return (*this);
	}

	RandomAccessIterator	operator++(int)
	{
		RandomAccessIterator<T>	ret(*this);

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

template <class T, class P = T*, class R = T&, class diff = ptrdiff_t>
class ReversedRandomAccessIterator : public iterator<T, RandomAccessIteratorTag>
{
	typedef P pointer;
	typedef R reference;
	typedef diff difference_type;
private:
	RandomAccessIterator<T>	_iter;
public:
	ReversedRandomAccessIterator() : _iter(nullptr)
	{
	}

	ReversedRandomAccessIterator(pointer p) : _iter(p)
	{
	}

	ReversedRandomAccessIterator(const ReversedRandomAccessIterator& copy) : _iter(copy._iter)
	{
	}

	~ReversedRandomAccessIterator()
	{
	}

	ReversedRandomAccessIterator&	operator=(const ReversedRandomAccessIterator& copy)
	{
		if (this == &copy)
			return (*this);
		this->_iter = copy._iter;
		return (*this);
	}

	ReversedRandomAccessIterator&	operator++(void)
	{
		--_iter;
		return (*this);
	}

	ReversedRandomAccessIterator	operator++(int)
	{
		ReversedRandomAccessIterator<T>	ret(*this);

		--_iter;
		return (ret);
	}

	reference	operator*() const
	{
		return (*(this->_iter));
	}

	bool					operator==(const ReversedRandomAccessIterator& iter) const
	{
		return (this->_iter == iter._iter);
	}

	bool					operator!=(const ReversedRandomAccessIterator& iter) const
	{
		return (this->_iter != iter._iter);
	}

	pointer					operator->()
	{
		return (this->_iter->_curr);
	}

	ReversedRandomAccessIterator&	operator--(void)
	{
		++_iter;
		return (*this);
	}

	ReversedRandomAccessIterator<T>	operator--(int)
	{
		ReversedRandomAccessIterator<T>	ret(*this);

		++_iter;
		return (ret);
	}

	bool					operator>(const ReversedRandomAccessIterator& iter) const
	{
		return (this->_iter > iter._iter);
	}

	bool					operator<(const ReversedRandomAccessIterator& iter) const
	{
		return (this->_iter < iter._iter);
	}

	bool					operator>=(const ReversedRandomAccessIterator& iter) const
	{
		return (this->_iter >= iter._iter);
	}

	bool					operator<=(const ReversedRandomAccessIterator& iter) const
	{
		return (this->_iter <= iter._iter);
	}

	ReversedRandomAccessIterator<T>&	operator+=(int n)
	{
		this->_iter -= n;
		return (*this);
	}

	ReversedRandomAccessIterator		operator+(int n) const
	{
		ReversedRandomAccessIterator<T>	ret(*this);

		ret += n;
		return (ret);
	}

	ReversedRandomAccessIterator&	operator-=(int n)
	{
		this->_iter += n;
		return (*this);
	}

	ReversedRandomAccessIterator	operator-(int n)
	{
		ReversedRandomAccessIterator<T>	ret(*this);

		ret -= n;
		return (ret);
	}

	difference_type	operator-(const ReversedRandomAccessIterator<T>& iter)
	{
		return (std::distance(iter._iter, this->iter));
	}

	reference				operator[](int n)
	{
		ReversedRandomAccessIterator<T>	ret(*this);

		ret -= n;
		return (*ret);
	}

	friend
	ReversedRandomAccessIterator<T>		operator+(int n, const ReversedRandomAccessIterator<T>& iter);
	friend
	ReversedRandomAccessIterator<T>		operator-(int n, const ReversedRandomAccessIterator<T>& iter);
};


template <class T>
ReversedRandomAccessIterator<T>	operator+(int n, const ReversedRandomAccessIterator<T>& iter)
{
	ReversedRandomAccessIterator<T>	ret(iter);

	ret += n;
	return (ret);
}

template <class T>
ReversedRandomAccessIterator<T>	operator-(int n, const ReversedRandomAccessIterator<T>& iter)
{
	ReversedRandomAccessIterator<T>	ret(iter);

	ret -= n;
	return (ret);
}


}