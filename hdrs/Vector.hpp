#pragma once

#include <iostream>
#include <string>
#include "Iterators.hpp"
#include "IteratorTraits.hpp"
#include "algoritmh.hpp"

#include <stdexcept>
#include <limits>

namespace ft
{
template <class T, class Alloc = std::allocator<T> >
class vector
{
public:
	typedef typename Alloc::value_type	
		value_type;

	typedef	Alloc				
		allocator_type;

	typedef typename Alloc::reference 		
		reference;
	typedef typename Alloc::const_reference	
		const_reference;

	typedef typename Alloc::pointer 		
		pointer;
	typedef typename Alloc::const_pointer	
		const_pointer;

	typedef RandomAccessIterator<T, const_pointer, const_reference>
		const_iterator;
	typedef RandomAccessIterator<T, pointer, reference>
		iterator;
	typedef ft::reverse_iterator<iterator>
		reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>
		const_reverse_iterator;

	typedef	typename ft::iterator_traits<iterator>::difference_type
		difference_type;
	typedef typename Alloc::size_type
		size_type;

private:
	allocator_type		_allocator;
	pointer				_begin;
	pointer				_end;
	size_type			_size;
	size_type			_capacity;

	void	_realloc(int size_needed = 0)
	{
		size_type	begin_capacity = this->_capacity;
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
		for (size_type i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(tmp_last, this->_begin[i]);
			this->_allocator.destroy(&this->_begin[i]);
			++tmp_last;
		}
		if (this->_begin)
			this->_allocator.deallocate(this->_begin, begin_capacity);
		this->_begin = tmp;
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
		return (--this->end());
	}
	reverse_iterator	rend()
	{
		return (this->_begin - 1);
	}
	const_reverse_iterator	rbegin()	const
	{
		return (--this->end());
	}
	const_reverse_iterator	rend()		const
	{
		return (this->_begin - 1);
	}

	reference		operator[](size_type index)
	{
		return (this->_begin[index]);
	}
	const_reference	operator[](size_type index) const
	{
		return (this->_begin[index]);
	}

	explicit 
	vector( const allocator_type& alloc = allocator_type() )
		:_allocator(alloc), _begin(), _end(), _size(), _capacity()
	{
	}

	explicit vector( size_type count,
		const_reference value = value_type(),
		const allocator_type& alloc = allocator_type() )
			: _allocator(alloc), _size(0), _capacity(0), _begin(), _end()
	{
		_realloc(count);
		for (size_t i = 0; i < count; i++)
		{
			std::allocator<int>	allocat;
			this->_allocator.construct(this->_begin + this->_size, value);
			++this->_size;
		}
		this->_end = this->_begin + this->_size;
	}

	template <class InputIterator>
		vector (InputIterator first,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
				const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _size(0), _capacity(0), _begin(), _end()
	{
		_realloc(last - first);
		while (first != last)
		{
			this->push_back(*first);
			first++;
		}
	}

	vector( const vector& copy )
		:  _allocator(copy._allocator), _size(copy._size), _capacity(copy._capacity)
	{
		this->_begin = this->_allocator.allocate(_capacity);
		this->_end = this->_begin + this->_size;

		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(this->_begin + i, copy[i]);
		}
	}
	
	~vector()
	{
		this->clear();
		this->_allocator.deallocate(this->_begin, this->_capacity);
	}

	vector&	operator=( const vector& copy )
	{
		if (this == &copy)
			return (*this);
		this->_allocator = copy._allocator;
		this->_size = copy._size;
		this->_capacity = copy._capacity;

		this->_begin = this->_allocator.allocate(this->_capacity);
		this->_end = this->_begin + this->_size;

		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.construct(this->_begin + i, copy[i]);
		}
		return (*this);
	}


	/* METHODS */

	void	assign(size_type n, const_reference val)
	{
		this->clear();
		if (n > this->_capacity)
		{
			this->_realloc(n - this->_capacity);
		}
		this->_size = n;
		for (int i = 0; i < n; i++)
		{
			*(this->_begin + i) = val;
		}
		this->_end = this->_begin + this->_size;
	}

	template <class InputIterator>
		void assign (InputIterator first,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
	{
		if (last < first)
			return ;
		size_type	n = last - first;
	
		this->clear();
		if (n > this->_capacity)
		{
			this->_realloc(n - this->_capacity);
		}
		this->_size = 0;
		for (int i = 0; i < n; i++)
		{
			*(this->_begin + i) = *first;
			first++;
			this->_size++;
		}
		this->_end = this->_begin + n;
	}

	reference at(size_type n)
	{
		if (n >= this->_size)
			throw std::out_of_range("out of range");
		return ((*this)[n]);
	}

	const_reference at(size_type n) const
	{
		if (n >= this->_size)
			throw std::out_of_range("out of range");
		return ((*this)[n]);
	}


	reference back()
		{ return *(--this->end()); }

	const_reference back() const
		{ return *(--this->end()); }

	size_type	capacity() const
		{ return (this->_capacity); }

	void	clear()
	{
		// pointer	ptr = this->_begin;

		for (int i = 0; i < this->_size; i++)
		{
			this->_allocator.destroy(this->_begin + i);
		}
		this->_size = 0;
		this->_end = this->_begin + this->_size;
	}

	bool		empty() const
	{ return (this->_size == 0); }

	iterator erase (iterator position)
	{ return (erase(position, position + 1)); }

	iterator erase (iterator first, iterator last)
	{
		if (last <= first)
			return (last);
		iterator	cpy = first;
		iterator	end = this->end();
		iterator	ans = first;

		while (first != last)
		{

			this->_allocator.destroy(&(*first));
			first++;
		}
		while (first != end)
		{
			this->_allocator.construct(&(*cpy), *first);
			first++;
			cpy++;
		}
		while (cpy != end)
		{
			this->_allocator.destroy(&(*cpy));
			this->_size--;
			this->_end--;
			cpy++;
		}
		return (ans);
	}

	reference front()
	{ return *(this->_begin); }

	const_reference front() const
	{ return *(this->_begin); }
	
	allocator_type	get_allocator() const
	{ return (this->_allocator); }

	iterator	insert(iterator position, const_reference val)
	{ return (_insert(position, 1, val, true)); }

    void		insert (iterator position, size_type n, const_reference val)
	{ _insert(position, n, val, true); }


private:
	iterator	_insert (iterator position, size_type n, const_reference val, bool a)
	{
		(void)a;

		size_type	begin_capacity = this->_capacity;
		if (this->_capacity == 0)
		{
			this->_capacity = 1;
		}
		while (this->_capacity < this->_size + n)
		{
			this->_capacity *= 2;
		}

		pointer	tmp;
		pointer	tmp_last;

		tmp = this->_allocator.allocate(this->_capacity);
		
		tmp_last = tmp;

		pointer		left = this->_begin;
		iterator	left_iter(left);

		while (this->_begin && left_iter < position)
		{
			this->_allocator.construct(tmp_last, *left_iter);
			this->_allocator.destroy(left);

			tmp_last++;
			left++;
			left_iter++;
		}
		iterator	ans = tmp_last;
		while (n > 0)
		{
			this->_allocator.construct(tmp_last, val);
			this->_size++;
			tmp_last++;
			n--;
		}
		while (this->_begin && left_iter < this->end())
		{
			this->_allocator.construct(tmp_last, *left);
			this->_allocator.destroy(left);

			tmp_last++;
			left++;
			left_iter++;
		}
		if (this->_begin)
		{
			this->_allocator.deallocate(this->_begin, begin_capacity);
		}
		this->_begin = tmp;
		this->_end = this->_begin + this->_size;
		return (ans);
	}

public:
	template <class InputIterator>
    	void insert (iterator position, InputIterator first,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
	{
		size_type	n = last - first;

		size_type	begin_capacity = this->_capacity;
		if (this->_capacity == 0)
		{
			this->_capacity = 1;
		}
		while (this->_capacity < this->_size + n)
		{
			this->_capacity *= 2;
		}

		pointer	tmp;
		pointer	tmp_last;

		tmp = this->_allocator.allocate(this->_capacity);
		
		tmp_last = tmp;

		pointer		left = this->_begin;
		iterator	left_iter(left);

		while (this->_begin && left_iter < position)
		{
			this->_allocator.construct(tmp_last, *left_iter);
			this->_allocator.destroy(left);

			tmp_last++;
			left++;
			left_iter++;
		}
		while (n > 0)
		{
			this->_allocator.construct(tmp_last, *first);
			this->_size++;
			tmp_last++;
			first++;
			n--;
		}
		while (this->_begin && left_iter < this->end())
		{
			this->_allocator.construct(tmp_last, *left);
			this->_allocator.destroy(left);

			tmp_last++;
			left++;
			left_iter++;
		}
		if (this->_begin)
		{
			this->_allocator.deallocate(this->_begin, begin_capacity);
		}
		this->_begin = tmp;
		this->_end = this->_begin + this->_size;
	}


	size_type	max_size() const
		{ return (SIZE_T_MAX / sizeof(value_type)); }



	void	push_back( const T& value )
	{
		if (this->_size >= this->_capacity)
			_realloc(1);
		this->_size++;
		this->_allocator.construct(this->_end, value);
		this->_end = this->_begin + this->_size;
	}

	void	pop_back()
	{
		this->_size--;
		this->_end = this->_begin + this->_size;
		this->_allocator.destroy(this->_end);
	}

	void	reserve(size_type n)
	{
		if (n <= this->_capacity)
			return ;
		this->_capacity = n;
		_realloc(0);
	}

	void resize (size_type n, value_type val = value_type())
	{
		if (n <= this->_size)
		{
			for (size_type i = this->_size; i > n; i--)
			{
				this->_allocator.destroy(this->_begin + i - 1);
				this->_size--;
			}
			this->_end = this->_begin + this->_size;
		}
		else
		{
			if (n > this->_capacity)
				this->reserve(n);
			for (int i = this->size(); i < n; i++)
				this->push_back(val);
		}
	}

	void swap (vector& x)
	{
		std::swap(this->_allocator, x._allocator);
		std::swap(this->_begin, x._begin);
		std::swap(this->_end, x._end);
		std::swap(this->_size, x._size);
		std::swap(this->_capacity, x._capacity);
	}




	size_t	size() const
		{ return (this->_size); }



};


template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}


template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs == rhs)); }


template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }


template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (lhs < rhs || lhs == rhs); }


template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs <= rhs)); }



template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs < rhs)); }





}