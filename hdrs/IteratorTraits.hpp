#pragma once
#include <cstddef>

namespace ft
{

struct ErrorIteratorTag {};
struct InputIteratorTag {};
struct ForwardIteratorTag : public InputIteratorTag {};
struct BidirectionalIteratorTag : public ForwardIteratorTag {};
struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

template <class Iter,
	class IterCategory = ErrorIteratorTag> struct IteratorTraits
{
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::iterator_category	iterator_category;
};

template <class T> struct IteratorTraits<T*>
{
	typedef ptrdiff_t				difference_type ;
	typedef T						value_type;
	typedef T*						pointer;
	typedef T&						reference;
	typedef ErrorIteratorTag		iterator_category;
};

template <class T> struct IteratorTraits<const T*>
{
	typedef ptrdiff_t				difference_type ;
	typedef T						value_type;
	typedef const T*				pointer;
	typedef const T&				reference;
	typedef ErrorIteratorTag		iterator_category;
};

}