#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <memory>
#include <limits>
#include <string>
#include <functional>
#include <utility>

// Re-implementation of my_nullptr, because nullptr is C++11 standard

const class my_nullptr_t
{
public:
	/* Return 0 for any class pointer */
	template <typename T>
	operator T *() const
	{
		return 0;
	}

	/* Return 0 for any member pointer */
	template <typename T, typename U>
	operator T U::*() const
	{
		return 0;
	}

	/* Safe boolean conversion */
	operator void *() const
	{
		return 0;
	}

private:
	/* Not allowed to get the address */
	void operator&() const;

} my_nullptr = {};

namespace ft
{
	// // Re-implementation of enable_if, because enable_if is C++11 standard

	template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class Iterator>
	ptrdiff_t difference(Iterator first, Iterator last)
	{
		ptrdiff_t diff = 0;

		while (first != last)
		{
			++diff;
			++first;
		}
		return (diff);
	}

	template <class T>
	void my_swap(T &a, T &b)
	{
		T tmp = a;

		a = b;
		b = tmp;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare_less(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif