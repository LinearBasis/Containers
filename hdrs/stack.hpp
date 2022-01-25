#include "vector.hpp"


namespace ft
{
template <class T, class Container = ft::vector<T> > class stack
{
public:
	typedef T value_type;	
	typedef Container container_type;
	typedef size_t size_type;

private:
	Container	c;
public:


	explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}



	bool empty() const
		{ return c.size() == 0; }
	
	void pop()
	{ c.pop_back(); }
	
	void push (const value_type& val)
	{ c.push_back(val); }

	size_type size ()
	{ return c.size(); }

	value_type& top()
	{
		return c.back();
	}

	const value_type& top() const
	{
		return c.back();
	}

	template< class U >
	friend bool operator==( const ft::stack<U>& lhs,
							const ft::stack<U>& rhs);
	template< class U >
	friend bool operator!=( const ft::stack<U>& lhs,
							const ft::stack<U>& rhs);
	template< class U >
	friend bool operator>( const ft::stack<U>& lhs,
							const ft::stack<U>& rhs);
	template< class U >
	friend bool operator<( const ft::stack<U>& lhs,
							const ft::stack<U>& rhs);
	template< class U >
	friend bool operator>=( const ft::stack<U>& lhs,
							const ft::stack<U>& rhs);
	template< class U >
	friend bool operator<=( const ft::stack<U>& lhs,
							const ft::stack<U>& rhs);

	template< class U, class Y >
	friend bool operator==( const ft::stack<U, Y>& lhs,
							const ft::stack<U, Y>& rhs);
	template< class U, class Y >
	friend bool operator!=( const ft::stack<U, Y>& lhs,
							const ft::stack<U, Y>& rhs);
	template< class U, class Y >
	friend bool operator>( const ft::stack<U, Y>& lhs,
							const ft::stack<U, Y>& rhs);
	template< class U, class Y >
	friend bool operator<( const ft::stack<U, Y>& lhs,
							const ft::stack<U, Y>& rhs);
	template< class U, class Y >
	friend bool operator>=( const ft::stack<U, Y>& lhs,
							const ft::stack<U, Y>& rhs);
	template< class U, class Y >
	friend bool operator<=( const ft::stack<U, Y>& lhs,
							const ft::stack<U, Y>& rhs);
};

 template< class T >
    bool    operator==( const ft::stack<T>& lhs,
                      const ft::stack<T>& rhs)
    { return (lhs.c == rhs.c); }

    template< class T >
    bool    operator!=( const ft::stack<T>& lhs,
                      const ft::stack<T>& rhs)
    { return (lhs.c != rhs.c); }

    template< class T >
    bool    operator<( const ft::stack<T>& lhs,
                       const ft::stack<T>& rhs)
    { return (lhs.c < rhs.c); }

    template< class T >
    bool    operator>( const ft::stack<T>& lhs,
                       const ft::stack<T>& rhs)
    { return (lhs.c > rhs.c); }

    template< class T >
    bool    operator<=( const ft::stack<T>& lhs,
                        const ft::stack<T>& rhs)
    { return (lhs.c <= rhs.c); }

    template< class T >
    bool    operator>=( const ft::stack<T>& lhs,
                        const ft::stack<T>& rhs)
    { return (lhs.c >= rhs.c); }

    template< class T, class U >
    bool    operator==( const ft::stack<T, U>& lhs,
                      const ft::stack<T, U>& rhs)
    {
        return (lhs.c == rhs.c);
    }

    template< class T, class U >
    bool    operator!=( const ft::stack<T, U>& lhs,
                      const ft::stack<T, U>& rhs)
    { return (lhs.c != rhs.c); }

    template< class T, class U >
    bool    operator<( const ft::stack<T, U>& lhs,
                       const ft::stack<T, U>& rhs)
    { return (lhs.c < rhs.c); }

    template< class T, class U >
    bool    operator>( const ft::stack<T, U>& lhs,
                       const ft::stack<T, U>& rhs)
    { return (lhs.c > rhs.c); }

    template< class T, class U >
    bool    operator<=( const ft::stack<T, U>& lhs,
                        const ft::stack<T, U>& rhs)
    { return (lhs.c <= rhs.c); }

    template< class T, class U >
    bool    operator>=( const ft::stack<T, U>& lhs,
                        const ft::stack<T, U>& rhs)
    { return (lhs.c >= rhs.c); }
	
}