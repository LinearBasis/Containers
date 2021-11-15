#pragma once
#include "Iterators.hpp"
#include "IteratorTraits.hpp"
#include "rbtree.hpp"

namespace ft
{

template <class T, class P, class R, class diff>
class red_black_tree_iterator : public ft::iterator<T, ft::BidirectionalIteratorTag>
	{
	public:
		typedef typename red_black_tree<T>::red_black_node	red_black_node;
		typedef red_black_node* pointer;
		typedef red_black_node& reference;
		typedef diff difference_type;
	private:
		pointer _curr;
	public:
		red_black_tree_iterator()
		{ this->_curr = nullptr; }
		red_black_tree_iterator(pointer p)
		{ this->_curr = p; }
		
		red_black_tree_iterator(const red_black_tree_iterator<T, P, R, diff>& copy)
		{ this->_curr = copy._curr; }

		~red_black_tree_iterator()
		{ }

		red_black_tree_iterator&	operator=(const red_black_tree_iterator<T, P, R, diff>& copy)
		{ if (this != &copy) this->_curr = copy.curr; return (*this); }

		operator red_black_tree_iterator<T, const T*, const T&>()
		{ return red_black_tree_iterator<T, const T*, const T&>(this->_curr); }

		red_black_tree_iterator&	operator++(void)
		{
			// if (!this->_curr->prev)
			// {
			// 	this->_curr = this->_curr->left;
			// }
			if (this->_curr->right)
			{
				this->_curr = this->_curr->right;
				this->_curr = this->_curr->get_far_left();
			}
			else if (this->_curr->prev)
			{
				while (this->_curr->prev && red_black_node::is_on_right(this->_curr))
				{
					this->_curr = this->_curr->prev;
				}
				if (this->_curr->prev)
					this->_curr = this->_curr->prev;
			}
			return (*this);
		}

		red_black_tree_iterator		operator++(int)
		{
			red_black_tree_iterator	iter(this->_curr);

			++(*this);
			return (iter);
		}

		T&		operator*() const
		{ return (this->_curr->_data); }

		bool	operator==(const red_black_tree_iterator& iter) const
		{ return (this->_curr == iter._curr); }

		bool	operator!=(const red_black_tree_iterator& iter) const
		{ return (this->_curr != iter._curr); }

		
		T*		operator->()
		{ return (&(this->_curr->data)); }
		
		red_black_tree_iterator&	operator--(void)
		{
			if (!this->_curr->prev)
			{
				this->_curr = this->_curr->right;
			}
			else if (this->_curr->left)
			{
				this->_curr = this->_curr->left;
				this->_curr = this->_curr->get_far_right();
			}
			else if (this->_curr->prev)
			{
				while (this->_curr->prev && red_black_node::is_on_left(this->_curr))
					this->_curr = this->_curr->prev;
				if (this->_curr->prev)
					this->_curr = this->_curr->prev;
			}
			return (*this);
		}

		red_black_tree_iterator	operator--(int)
		{
			red_black_tree_iterator iter(*this);

			--(*this);
			return (iter);
		}
	};
}
