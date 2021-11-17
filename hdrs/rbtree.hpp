#pragma once
#include "utility.hpp"
#include "utils.hpp"
#include <memory>
#include "vector.hpp"
#include <vector>
#include <string>
// #include "rbiter.hpp"
#include <unistd.h>

// # define B_CYAN "\x1b[46;1m" <<
// # define B_RED  "\x1b[41;1m" <<
// # define YELLOW "\x1b[33;1m" <<
// # define RED    "\x1b[31;1m" <<
// # define GREEN  "\x1b[32;1m" <<
// # define DEFAULT << "\x1b[m"

#define RED_NODE "\x1b[37;41m"
#define BLACK_NODE "\x1b[37;40m"
#define CLEAR_COLOR "\x1b[m"

enum Colors
{
	RED = false,
	BLACK
};

namespace ft
{
template <class T, class P = T*, class R = T&, class diff = ptrdiff_t>
	class	red_black_tree_iterator;
template <class iter>
	class reverse_iterator_rbtree;
}

template <class Iter> class reverse_iterator_rbtree;

template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	red_black_tree
{
public:

	class red_black_node
	{
		typedef T value_type;
		friend class red_black_tree;
	// private:
	public:
		value_type	_data;
		Colors		_color;

	public:
		red_black_node		*prev;
		red_black_node		*left;
		red_black_node		*right;

		red_black_node(const value_type& data, Colors color,
			red_black_node *prev = nullptr, red_black_node *left = nullptr, red_black_node *right = nullptr)
			: _data(data), _color(color), prev(prev), left(left), right(right) {}
		
		bool	operator!() const
		{ return (!this->prev); }

		static Colors	color(const red_black_node* node)
		{
			if (!node)
				return (BLACK);
			return (node->_color);
		}

		static bool		is_node(red_black_node* node)
		{
			if (!node || !(*node))
				return (false);
			return (true);
		}
public:
		static void	print_node(red_black_node *node, int level = 0)
		{
			for (int i = 0; i < level; i++)
				std::cout << "\t";
			if (node && red_black_node::color(node) == RED)
				std::cout << RED_NODE;
			else
				std::cout << BLACK_NODE;
			if (node)
				std::cout << node->_data << CLEAR_COLOR << std::endl;
			else
				std::cout << "(null)" << CLEAR_COLOR << std::endl;
			// if (red_black_node::is_node(node))
				// printf(" %p %p\n", node, node->prev);
			if (node)
			{
				red_black_node::print_node(node->left, level + 1);
				red_black_node::print_node(node->right, level + 1);
			}
		}

		bool		is_on_left()
			{ return (this == this->prev->left); }
		bool		is_on_right()
			{ return (this == this->prev->right); }
		static bool	is_on_left(red_black_node *node)
			{ return (node == node->prev->left); }
		static bool	is_on_right(red_black_node *node)
			{ return (node == node->prev->right); }

		red_black_node	*get_far_left()
		{
			red_black_node	*cpy;

			cpy = this;
			while (red_black_node::is_node(cpy->left))
				cpy = cpy->left;
			return (cpy);
		}

		red_black_node	*get_far_right()
		{
			red_black_node	*cpy;

			cpy = this;
			while (red_black_node::is_node(cpy->right))
				cpy = cpy->right;
			return (cpy);
		}

		red_black_node	*uncle()
		{
			if (!red_black_node::is_node(this) || !red_black_node::is_node(this->prev)
				|| !red_black_node::is_node(this->prev->prev))
				return (nullptr);
			if (red_black_node::is_node(this->prev->is_on_left()))
				return (this->prev->prev->right);
			return (this->prev->prev->left);
		}

		red_black_node	*sibling()
		{
			if (!red_black_node::is_node(this->prev))
				return (nullptr);
			if (this->is_on_left)
				return (this->prev->right);
			return (this->prev->left);
		}
	};


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

	// typedef	typename ft::iterator_traits<iterator>::difference_type
		// difference_type;
	typedef typename Alloc::size_type
		size_type;

	typedef typename Alloc::template rebind<red_black_node>::other allocator_node_type;

	typedef red_black_node	node_type;

	typedef typename ft::red_black_tree_iterator<value_type, pointer, reference>
		iterator;
	typedef typename ft::red_black_tree_iterator<value_type, const_pointer, const_reference>
		const_iterator;

	typedef typename ft::reverse_iterator<iterator>
		reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>
		const_reverse_iterator;


public:
	iterator	begin()
	{
		return (this->_head->get_far_left());
	}

	const_iterator	begin() const
	{
		return (this->_head->get_far_left());
	}

	iterator	end()
	{
		return (this->_head);
	}

	const_iterator	end() const
	{
		return (this->_head);
	}

	reverse_iterator		rbegin()
	{
		return (iterator(this->_head->right));
	}

	const_reverse_iterator	rbegin() const
	{
		return (const_iterator(this->_head->right));
	}

	reverse_iterator		rend()
	{
		return (iterator(this->_head));
	}

	const_reverse_iterator	rend() const
	{
		return (const_iterator(this->_head));
	}

public:
	allocator_type		_allocator;
	allocator_node_type	_allocator_node;
	Compare				_comparator;
	size_type			_size;
	node_type			*_head;
	node_type			*_root;

private:

	node_type	*new_node(const T& value, Colors color = RED)
	{
		node_type	*node = this->_allocator_node.allocate(1);

		this->_allocator_node.construct(node, node_type(value, color));
		return (node);
	}

	bool	less(const_reference v1, const_reference v2)
	{ return (this->_comparator(v1, v2)); }

	bool	equal(const_reference v1, const_reference v2)
	{ return (!less(v1, v2) && !less(v2, v1)); }


public:
	bool	is_red_black_tree()
	{
		ft::vector<ft::pair<int, node_type*> >	vec;

		vec.push_back(ft::make_pair(0, this->_root));

		int i = 0;
		while (1)
		{
			if (vec[i].second)
			{
				if (node_type::is_node(vec[i].second) && (node_type::color(vec[i].second) == RED) &&
					((node_type::is_node(vec[i].second->left) && node_type::color(vec[i].second->left) == RED) ||
					(node_type::is_node(vec[i].second->right) && node_type::color(vec[i].second->right) == RED)))
					return (false);
				if (node_type::is_node(vec[i].second) && node_type::color(vec[i].second) == RED)
				{
					vec.push_back(ft::make_pair(vec[i].first, vec[i].second->left));
					vec.push_back(ft::make_pair(vec[i].first, vec[i].second->right));
				}
				else if (node_type::is_node(vec[i].second))
				{
					vec.push_back(ft::make_pair(vec[i].first + 1, vec[i].second->left));
					vec.push_back(ft::make_pair(vec[i].first + 1, vec[i].second->right));
				}
				vec.erase(vec.begin() + i);
				i = 0;
			}
			else
				i++;
			if (i == vec.size())
				break ;
		}
		i = vec[0].first;
		for (int j = 1; j < vec.size(); j++)
		{
			if (vec[j].first != i)
				return (false);
		}
		return (true);
	}

	void	left_rotation(node_type *node)
	{
		node_type	*new_parent = node->right;

		node_type	*new_right_node_of_old_parent = new_parent->left;

		new_parent->prev = node->prev;
		if (node == this->_root)
		{
			this->_root = new_parent;
			this->_root->prev = this->_head;
		}
		else if (node_type::is_on_left(node))
		{
			new_parent->prev->left = new_parent;
		}
		else if (node_type::is_on_right(node))
		{
			new_parent->prev->right = new_parent;
		}

		new_parent->left = node;
		new_parent->prev = node->prev;

		new_parent->left->right = new_right_node_of_old_parent;
		if (new_right_node_of_old_parent)
			new_parent->left->right->prev = new_parent->left;
		new_parent->left->prev = new_parent;
	}

	void	right_rotation(node_type *node)
	{
		node_type	*new_parent = node->left;

		node_type	*new_left_node_of_old_parent = new_parent->right;

		new_parent->prev = node->prev;
		if (node == this->_root)
		{
			this->_root = new_parent;
			this->_root->prev = this->_head;
		}
		else if (node_type::is_on_left(node))
		{
			new_parent->prev->left = new_parent;
		}
		else if (node_type::is_on_right(node))
		{
			new_parent->prev->right = new_parent;
		}
		new_parent->right = node;

		new_parent->right->left = new_left_node_of_old_parent;
		if (node_type::is_node(new_left_node_of_old_parent))
			new_parent->right->left->prev = new_parent->right;
		new_parent->right->prev = new_parent;
	}

	void	swap_colors(node_type *u, node_type *v)
	{
		Colors	temp;

		temp = u->_color;
		u->_color = v->_color;
		v->_color = temp;
	}

public:
	red_black_tree()
		: _allocator(Alloc()), _size(0), _head(new_node(value_type(), RED)), _root(nullptr), _comparator(Compare())
	{ }

	void	print()
	{
		if (this->_root)
			node_type::print_node (this->_root);
		if (this->_head)
			std::cout << "left node of head : " << this->_head->left->_data << std::endl;
		if (this->_head)
			std::cout << "right node of head : " << this->_head->right->_data << std::endl;
		std::cout << "is rbtree - " << std::boolalpha;
		std::cout << this->is_red_black_tree() << std::noboolalpha << std::endl;
	}
	
	node_type*	naive_add(node_type* addedNode)
	{
		node_type*	begin = this->_root;

		if (!begin)
		{
			this->_root = addedNode;
			this->_root->prev = this->_head;
			this->_root->_color = BLACK;

			this->_head->left = this->_root;
			this->_head->right = this->_root;

			return (this->_head);
		}
		while (begin)
		{
			if (this->less(begin->_data, addedNode->_data))
			{
				if (begin->right)
					begin = begin->right;
				else
				{
					begin->right = addedNode;
					addedNode->prev = begin;
					break;
				}
			}
			else if (this->less(addedNode->_data, begin->_data))
			{
				if (begin->left)
					begin = begin->left;
				else
				{
					begin->left = addedNode;
					addedNode->prev = begin;
					break;
				}
			}
			else
			{
				begin->_data = addedNode->_data;
				break;
			}
		}
		return (begin);
	}


	Colors	color_of_node(node_type *node)
	{
		if (node)
			return (node_type::color(node));
		return (BLACK);
	}

// private:
	public:
	//		case1 = red uncle, red parent and red added
	//		checking becomes from granddad of added ode
	bool	_check_case1(node_type	*grandparent_of_added)
	{
		if (!node_type::is_node(grandparent_of_added) ||
			!node_type::is_node(grandparent_of_added->left) ||
			!node_type::is_node(grandparent_of_added->right))
			return (false);
		if (color_of_node(grandparent_of_added) == BLACK &&
			color_of_node(grandparent_of_added->left) == RED &&
			color_of_node(grandparent_of_added->right) == RED &&
				(color_of_node(grandparent_of_added->left->left) == RED ||
				color_of_node(grandparent_of_added->right->right) == RED ||
				color_of_node(grandparent_of_added->left->right) == RED ||
				color_of_node(grandparent_of_added->right->left) == RED
				) )
		{
			if (grandparent_of_added != this->_root)
				grandparent_of_added->_color = RED;
			grandparent_of_added->left->_color = BLACK;
			grandparent_of_added->right->_color = BLACK;

			return (true);
		}
		return (false);
	}
	
	//		case2 = black uncle, father and dad from different sides
	//		checking becomes from granddad of added ode
	bool	_check_case2(node_type	*grandparent_of_added)
	{
		if (node_type::is_node(grandparent_of_added) &&
			node_type::is_node(grandparent_of_added->right))
		{
			if (color_of_node(grandparent_of_added) == BLACK &&
				color_of_node(grandparent_of_added->left) == BLACK &&
				color_of_node(grandparent_of_added->right) == RED &&
				color_of_node(grandparent_of_added->right->left) == RED)
			{
				this->right_rotation(grandparent_of_added->right);
				this->_check_case3(grandparent_of_added);
				return (true);
			}
		}
		if (node_type::is_node(grandparent_of_added) &&
			node_type::is_node(grandparent_of_added->left))
		{
			if (color_of_node(grandparent_of_added) == BLACK &&
				color_of_node(grandparent_of_added->right) == BLACK &&
				color_of_node(grandparent_of_added->left) == RED &&
				color_of_node(grandparent_of_added->left->right) == RED)
			{
				this->left_rotation(grandparent_of_added->left);
				this->_check_case3(grandparent_of_added);
				return (true);
			}
		}
		return (false);
	}

	//		case3 = black uncle, father and dad on the same side
	bool	_check_case3(node_type	*grandparent_of_added)
	{
		if (grandparent_of_added->_data == 1)
		{
			std::cout << "_______" << std::endl;
			node_type::print_node(grandparent_of_added);
			std::cout << "_______" << std::endl;
		}
		if (grandparent_of_added  &&
			grandparent_of_added->left)
		{
			if (color_of_node(grandparent_of_added)				== BLACK	&&
				color_of_node(grandparent_of_added->right)		== BLACK	&&
				color_of_node(grandparent_of_added->left)		== RED		&&
				color_of_node(grandparent_of_added->left->left) == RED)
			{
				right_rotation(grandparent_of_added);
				grandparent_of_added = grandparent_of_added->prev;
				this->swap_colors(grandparent_of_added, grandparent_of_added->right);
				return (true);
			}
		}
		if (grandparent_of_added  &&
			grandparent_of_added->right)
		{
			if (color_of_node(grandparent_of_added)				== BLACK	&&
				color_of_node(grandparent_of_added->left)		== BLACK	&&
				color_of_node(grandparent_of_added->right)		== RED		&&
				color_of_node(grandparent_of_added->right->right) == RED)
			{
				left_rotation(grandparent_of_added);
				grandparent_of_added = grandparent_of_added->prev;
				this->swap_colors(grandparent_of_added, grandparent_of_added->left);
				return (true);
			}
		}
		return (false);
	}
	
	bool	_check_cases(node_type	*parent_of_added)
	{
		bool	a, b, c;
		if (parent_of_added == this->_head || !parent_of_added)
			return (false);
		a = this->_check_case1(parent_of_added);
		b = this->_check_case2(parent_of_added);
		c = this->_check_case3(parent_of_added);
		if (parent_of_added->prev != this->_head)
		{
			a = this->_check_case1(parent_of_added->prev) || a;
			b = this->_check_case2(parent_of_added->prev) || b;
			c = this->_check_case3(parent_of_added->prev) || c;
		}
		if ((a || b || c) && parent_of_added->prev->prev != this->_head)
			this->_check_cases(parent_of_added->prev->prev);
		return (false);
	}

public:

	//	TODO функция должна возвращать итератор
	void	add(const_reference data)
	{
		node_type*	addedNode = new_node(data, RED);
		node_type*	parentOfAddedNode = naive_add(addedNode);

		if (parentOfAddedNode == addedNode || parentOfAddedNode == this->_head)
		{
			return ;		//исправить тут
		}

		this->_check_cases(parentOfAddedNode);

		this->_size++;
		this->_root->_color = BLACK;

		node_type	*left = this->_root->get_far_left();
		this->_head->left = left;

		node_type	*right = this->_root->get_far_right();
		this->_head->right = right;
	}

	void	clear()
	{
		
	}

	~red_black_tree()
	{

	}
};