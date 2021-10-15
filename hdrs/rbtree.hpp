#include "utility.hpp"
#include "utils.hpp"
#include <memory>
#include "vector.hpp"
#include <vector>
#include <string>

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


template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class	red_black_tree
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

	// typedef	typename ft::iterator_traits<iterator>::difference_type
		// difference_type;
	typedef typename Alloc::size_type
		size_type;



	class red_black_node
	{
		friend class red_black_tree;
	private:
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
		{
			return (this->prev && this->prev->prev &&
				this->prev->prev == this && this->_color == RED);
		}


		static Colors	color(red_black_node* node)
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
			if (red_black_node::is_node(node) && red_black_node::color(node) == RED)
				std::cout << RED_NODE;
			else
				std::cout << BLACK_NODE;
			if (red_black_node::is_node(node))
				std::cout << node->_data << CLEAR_COLOR;
			else
				std::cout << "(null)" << CLEAR_COLOR << std::endl;
			// if (red_black_node::is_node(node))
				// printf(" %p %p\n", node, node->prev);
			if (red_black_node::is_node(node))
				red_black_node::print_node(node->left, level + 1);
			if (red_black_node::is_node(node))
				red_black_node::print_node(node->right, level + 1);
		}

		

		bool		is_on_left()
		{
			return (this == this->prev->left);
		}

		bool		is_on_right()
		{
			return (this == this->prev->right);
		}

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

		void			move_down(red_black_node *n_parent)
		{
			if (red_black_node::is_node(this->prev))
			{
				if (this->is_on_left())
					this->prev->left = n_parent;
				else
					this->prev->right = n_parent;
			}
			n_parent->prev = this->prev;
			this->prev = n_parent;
		}
	};

	typedef red_black_node	node_type;

public:
	Alloc		_allocator;
	Compare		_comparator;
	size_type	_size;
	red_black_node		*_root;
	node_type	*_node;

private:

	void	_update_root()
	{
		this->_node->prev = this->_root;
		this->_root->prev = this->_node;
	}

	bool	less(const_reference v1, const_reference v2)
	{ return (this->_comparator(v1, v2)); }

	bool	equal(const_reference v1, const_reference v2)
	{ return (!less(v1, v2) && !less(v2, v1)); }

	bool	is_red_black_tree()
	{
		ft::vector<ft::pair<int, node_type*> >	vec;

		vec.push_back(ft::make_pair(0, this->_node));

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
		// std::cout << "BH - " << i << std::endl;
		for (int j = 1; j < vec.size(); j++)
		{
			if (vec[j].first != i)
				return (false);
		}
		return (true);
	}

	void	left_rotation(node_type *node)
	{
		node_type	*n_parent = node->right;
		
		if (node == this->_node)
		{
			this->_node = n_parent;
			this->_update_root();
		}
		node->move_down(n_parent);

		node->right = n_parent->left;
		if (node_type::is_node(n_parent->left))
			n_parent->left->prev = node;

		n_parent->left = node;
	}

	void	right_rotation(node_type *node)
	{
		node_type	*n_parent = node->left;
		
		if (node == this->_node)
		{
			this->_node = n_parent;
			this->_update_root();
		}
		node->move_down(n_parent);

		node->left = n_parent->right;
		if (node_type::is_node(n_parent->right))
			n_parent->right->prev = node;
	}

	void	swap_colors(node_type *u, node_type *v)
	{
		Colors	temp;

		temp = u->_color;
		u->_color = v->_color
		v->_color = temp;
	}

	void	swap_values(node_type *u, node_type *v)
	{
		value_type	value;

		value = u->_data;
		u->_data = v->_data;
		v->_data = value;
	}


public:
	red_black_tree()
		: _allocator(Alloc()), _size(0), _root(new node_type(value_type(), RED)), _node(nullptr), _comparator(Compare())
	{ }

	void	print()
	{
		if (node_type::is_node(this->_node))
			node_type::print_node (this->_node);
		std::cout << "is rbtree - " << std::boolalpha << this->is_red_black_tree() << std::endl;
	}
	
	node_type*	naiveAdd(node_type* addedNode)
	{
		node_type*	begin = this->_node;
		
		if (!begin)
		{
			this->_node = addedNode; 
			this->_node->_color = BLACK;
			this->_root->prev = this->_node;
			this->_node->prev = this->_root;
			return (begin);
		}

		while (node_type::is_node(begin))
		{
			if (this->less(addedNode->_data, begin->_data))
			{
				if (node_type::is_node(begin->right))
					begin = begin->right;
				else
				{
					begin->right = addedNode;
					addedNode->prev = begin;
					break;
				}
			}
			else if (this->less(begin->_data, addedNode->_data))
			{
				if (node_type::is_node(begin->left))
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


	//	TODO функция должна возвращать итератор
	void	add(const_reference data)
	{
		node_type*	addedNode = new node_type(data, RED);

		node_type*	parentOfAddedNode = naiveAdd(addedNode);

		if (parentOfAddedNode == addedNode)
			return ;		//исправить тут




		// тут отбалансировать





		node_type	*left = this->_node->get_far_left();
		left->left = this->_root;
		this->_root->left = left;

		node_type	*right = this->_node->get_far_right();
		right->right = this->_root;
		this->_root->right = right;
	}

};