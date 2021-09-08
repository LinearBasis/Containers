#pragma once

#include <iostream>
#include <string>
#include "Iterators.hpp"
#include "IteratorTraits.hpp"

namespace ft
{
template <class T, class Alloc = std::allocator<T> >
class Vector
{
private:
	typedef typename Alloc::const_pointer	const_pointer;
	typedef typename Alloc::pointer 		pointer;

	typedef typename Alloc::const_reference	const_reference;
	typedef typename Alloc::reference 		reference;

	// typedef typename Alloc::const_pointer	const_pointer;
	// typedef typename Alloc::pointer 		pointer;

	// typedef typename Alloc::const_reference	const_reference;
	// typedef typename Alloc::reference 		reference;
public:
	typedef RandomAccessIterator<T>
		iterator;
	typedef RandomAccessIterator<T, const_pointer, const_reference>
		const_iterator;

private:
	Alloc	_allocator;
	T*		_begin;
	T*		_end;
	T*		_last;
	size_t	_size;
	size_t	_capacity;

	void	_realloc(int size_needed = 0)
	{
		size_t	begin_capacity = this->_capacity;
		if (this->_capacity == 0)
		{
			this->_capacity = 1;
		}
		while (this->_capacity < this->_size + size_needed)
		{
			this->_capacity *= 2;
		}

		pointer	tmp;
		pointer	tmp_last;

		tmp = this->_allocator.allocate(this->_capacity );
		tmp_last = tmp;
		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(tmp_last, this->_begin[i]);
			this->_allocator.destroy(&this->_begin[i]);
			++tmp_last;
		}
		this->_allocator.deallocate(this->_begin, begin_capacity);
		this->_begin = tmp;
		this->_last = tmp_last;
		this->_end = tmp + this->_size;
	}
public:

	iterator	begin()
	{
		return (this->_begin);
	}
	iterator	end()
	{
		return (this->_end);
	}

	const_iterator	begin() const
	{
		return (this->_begin);
	}
	const_iterator	end() const
	{
		return (this->_end);
	}

	reference	operator[](size_t index)
	{
		return (this->_begin[index]);
	}


	/* CONSTRUCTORS */

	Vector()
		:  _allocator(Alloc()), _begin(), _end(), _last(), _size(), _capacity()
	{
	}

	explicit Vector( const Alloc& alloc )
		:_allocator(alloc), _begin(), _end(), _last(), _size(), _capacity()
	{

	}

	Vector( const Vector& copy )
		:  _allocator(copy._allocator), _size(copy._size), _capacity(copy._capacity)
	{
		this->_begin = this->_allocator.allocate(_capacity);
		this->_end = this->_begin + this->_size;
		this->_last = this->_begin;

		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(this->_last, copy[i]);
			++this->_last;
		}
	}
	
	~Vector()
	{
		for (iterator i1 = this->begin(); i1 != this->end(); i1++)
		{
			this->_allocator.destroy(&(*i1));
		}
		this->_allocator.deallocate(this->_begin, this->_capacity);
	}
	
	Vector&	operator=( const Vector& copy )
	{
		if (this == &copy)
			return (*this);
		this->_allocator = copy._allocator;
		this->_size = copy._size;
		this->_capacity = copy._capacity;

		this->begin = this->_allocator.allocate(this->_capacity);
		this->_end = this->_begin + this->_size;
		this->_last = this->_begin;

		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(this->_last, copy[i]);
		}
	}


	/* METHODS */

	void	push_back( const T& value )
	{
		if (this->_size >= this->_capacity)
		{
			_realloc(1);
		}
		this->_allocator.construct(this->_end, value);
		this->_end++;
		this->_size++;
	}

	void	pop_back()
	{
		this->_size--;

		this->_allocator.destruct(this->_last);
		this->_last--;
		this->_end--;
	}
};

// template <class T>
// Vector<T>::Vector()
// {

// }

// template <class T>
// Vector<T>::Vector(const Vector& copy)
// {

// }

// template <class T>
// Vector<T>::~Vector()
// {

// }

// template <class T>
// Vector<T>&	Vector<T>::operator=(const Vector& copy)
// {
// 	if (this == &copy)
// 		return (*this);

// }

// IteratorTraits







}