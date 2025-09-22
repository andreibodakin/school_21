#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

// Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
// where elements are inserted and extracted only from one end of the container.

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	protected:
		container_type container;

	public:
		explicit stack(const container_type &ctnr = container_type()) : container(ctnr)
		{
		}

		bool empty() const
		{
			return (container.empty());
		}

		size_type size() const
		{
			return (container.size());
		}

		// Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
		value_type &top()
		{
			return (container.back());
		}

		const value_type &top() const
		{
			return (container.back());
		}

		void push(const value_type &val)
		{
			container.push_back(val);
		}

		void pop()
		{
			container.pop_back();
		}

		friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{
			return (lhs.container == rhs.container);
		}

		friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{
			return (lhs.container != rhs.container);
		}

		friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{
			return (lhs.container < rhs.container);
		}

		friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{
			return (lhs.container > rhs.container);
		}

		friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{
			return (lhs.container <= rhs.container);
		}

		friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{
			return (lhs.c >= rhs.c);
		}
	};
}

#endif