#pragma once

#include <iostream>
#include <string>
#include "Iterators.hpp"
#include "IteratorTraits.hpp"

namespace ft
{
template <class T, class Alloc = std::allocator<T> >
class vector
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
	typedef RandomAccessIterator<T, pointer, reference>
		iterator;
	typedef RandomAccessIterator<T, const_pointer, const_reference>
		const_iterator;

	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

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

		tmp = this->_allocator.allocate(this->_capacity);
		tmp_last = tmp;
		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(tmp_last, this->_begin[i]);
			this->_allocator.destroy(&this->_begin[i]);
			++tmp_last;
		}
		if (this->_begin)
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
		return (const_iterator(this->_begin));
	}
	const_iterator	end() const
	{
		return (const_iterator(this->_end));
	}


	reverse_iterator	rbegin()
	{
		return (this->_last);
	}
	reverse_iterator	rend()
	{
		return (this->_begin - 1);
	}

	const_reverse_iterator	rbegin()	const
	{
		return (this->_last);
	}
	const_reverse_iterator	rend()		const
	{
		return (this->_begin - 1);
	}

	reference		operator[](size_t index)
	{
		return (this->_begin[index]);
	}
	const_reference	operator[](size_t index) const
	{
		return (this->_begin[index]);
	}
	/* CONSTRUCTORS */

	
	vector()
		:  _allocator(Alloc()), _begin(), _end(), _last(), _size(), _capacity()
	{
	}

	explicit 
	vector( const Alloc& alloc )
		:_allocator(alloc), _begin(), _end(), _last(), _size(), _capacity()
	{

	}

	explicit vector( size_t count,
		 const T& value = T(),
		 const Alloc& alloc = Alloc() )
		 	: _allocator(alloc), _size(0), _capacity(0), _begin(), _end(), _last()
	{
		_realloc(count);
		for (size_t i = 0; i < count; i++)
		{
			std::allocator<int>	allocat;
			// allocat.construct(this->_last, value);
			this->_allocator.construct(this->_last, value);
			++this->_last;
		}
		this->_end = this->_last;
		--this->_last;
	}


	vector( const vector& copy )
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
	
	~vector()
	{
		for (iterator i1 = this->begin(); i1 != this->end(); i1++)
		{
			this->_allocator.destroy(&(*i1));
		}
		this->_allocator.deallocate(this->_begin, this->_capacity);
	}


	vector&	operator=( const vector& copy )
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
			this->_last++;
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
// vector<T>::vector()
// {

// }

// template <class T>
// vector<T>::vector(const vector& copy)
// {

// }

// template <class T>
// vector<T>::~vector()
// {

// }

// template <class T>
// vector<T>&	vector<T>::operator=(const vector& copy)
// {
// 	if (this == &copy)
// 		return (*this);

// }

// IteratorTraits







}