#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

// Queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out),
//  where elements are inserted into one end of the container and extracted from the other.

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	protected:
		container_type container;

	public:
		explicit queue(const container_type &ctnr = container_type()) : container(ctnr)
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

		value_type &front()
		{
			return (container.front());
		}

		const value_type &front() const
		{
			return (container.front());
		}

		value_type &back()
		{
			return (container.back());
		}

		const value_type &back() const
		{
			return (container.back());
		}

		void push(const value_type &val)
		{
			container.push_back(val);
		}

		// The element removed is the "oldest" element in the queue whose value can be retrieved by calling member queue::front.
		void pop()
		{
			container.pop_front();
		}

		friend bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
		{
			return (lhs.container == rhs.container);
		}

		friend bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
		{
			return (lhs.container != rhs.container);
		}

		friend bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
		{
			return (lhs.container < rhs.container);
		}

		friend bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
		{
			return (lhs.container > rhs.container);
		}

		friend bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
		{
			return (lhs.container <= rhs.container);
		}

		friend bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
		{
			return (lhs.container >= rhs.container);
		}
	};
}

#endif