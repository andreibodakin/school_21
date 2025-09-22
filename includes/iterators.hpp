#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "utils.hpp"

// https://www.cplusplus.com/reference/list/list/
// https://en.wikipedia.org/wiki/Doubly_linked_list

template <typename T>
struct node
{
	T *data;
	struct node *previous;
	struct node *next;
};

// https://www.cplusplus.com/reference/iterator/iterator/

template <class T>
class bidirectional_iterator
{
private:
	node<T> *_ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	bidirectional_iterator() : _ptr(my_nullptr)
	{
	}

	explicit bidirectional_iterator(node<T> *ptr) : _ptr(ptr)
	{
	}

	bidirectional_iterator(bidirectional_iterator const &other) : _ptr(other._ptr)
	{
	}

	virtual ~bidirectional_iterator()
	{
	}

	bidirectional_iterator &operator=(bidirectional_iterator const &other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	bidirectional_iterator &operator++()
	{
		_ptr = _ptr->next;
		return (*this);
	}

	const bidirectional_iterator operator++(int)
	{
		bidirectional_iterator it(_ptr);
		_ptr = _ptr->next;
		return (it);
	}

	bidirectional_iterator &operator--()
	{
		_ptr = _ptr->previous;
		return (*this);
	}

	const bidirectional_iterator operator--(int)
	{
		bidirectional_iterator it(_ptr);
		_ptr = _ptr->previous;
		return (it);
	}

	bool operator==(bidirectional_iterator const &other)
	{
		return (_ptr == other._ptr);
	}

	bool operator!=(bidirectional_iterator const &other)
	{
		return (_ptr != other._ptr);
	}

	reference operator*()
	{
		return (*_ptr->data);
	}

	pointer operator->()
	{
		return (_ptr->data);
	}

	node<T> *getNode() const
	{
		return (_ptr);
	}
};

template <class T>
class const_bidirectional_iterator
{
private:
	node<T> *_ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	const_bidirectional_iterator() : _ptr(my_nullptr)
	{
	}

	explicit const_bidirectional_iterator(node<T> *ptr) : _ptr(ptr)
	{
	}

	const_bidirectional_iterator(const_bidirectional_iterator const &other) : _ptr(other._ptr)
	{
	}

	const_bidirectional_iterator(bidirectional_iterator<T> const &other) : _ptr(other.getNode())
	{
	}

	virtual ~const_bidirectional_iterator()
	{
	}

	const_bidirectional_iterator &operator=(const_bidirectional_iterator const &other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	const_bidirectional_iterator &operator=(bidirectional_iterator<T> const &other)
	{
		_ptr = other.getNode();
		return (*this);
	}

	const_bidirectional_iterator &operator++()
	{
		_ptr = _ptr->next;
		return (*this);
	}

	const const_bidirectional_iterator operator++(int)
	{
		const_bidirectional_iterator it(_ptr);
		_ptr = _ptr->next;
		return (it);
	}

	const_bidirectional_iterator &operator--()
	{
		_ptr = _ptr->previous;
		return (*this);
	}

	const const_bidirectional_iterator operator--(int)
	{
		const_bidirectional_iterator it(_ptr);
		_ptr = _ptr->previous;
		return (it);
	}

	bool operator==(const_bidirectional_iterator const &other)
	{
		return (_ptr == other._ptr);
	}

	bool operator!=(const_bidirectional_iterator const &other)
	{
		return (_ptr != other._ptr);
	}

	const reference operator*() const
	{
		return (*_ptr->data);
	}

	pointer operator->() const
	{
		return (_ptr->data);
	}
};

template <class T>
class reverse_iterator
{
private:
	node<T> *_ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	reverse_iterator() : _ptr(my_nullptr)
	{
	}

	explicit reverse_iterator(node<T> *ptr) : _ptr(ptr)
	{
	}

	reverse_iterator(reverse_iterator const &other) : _ptr(other._ptr)
	{
	}

	virtual ~reverse_iterator()
	{
	}

	reverse_iterator &operator=(reverse_iterator const &other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	reverse_iterator &operator++()
	{
		_ptr = _ptr->previous;
		return (*this);
	}

	const reverse_iterator operator++(int)
	{
		reverse_iterator it(_ptr);
		_ptr = _ptr->previous;
		return (it);
	}

	reverse_iterator &operator--()
	{
		_ptr = _ptr->next;
		return (*this);
	}

	const reverse_iterator operator--(int)
	{
		reverse_iterator it(_ptr);
		_ptr = _ptr->next;
		return (it);
	}

	bool operator==(reverse_iterator const &other)
	{
		return (_ptr == other._ptr);
	}

	bool operator!=(reverse_iterator const &other)
	{
		return (_ptr != other._ptr);
	}

	reference operator*()
	{
		return (*_ptr->data);
	}

	pointer operator->()
	{
		return (_ptr->data);
	}

	node<T> *getNode() const
	{
		return (_ptr);
	}
};

template <class T>
class const_reverse_iterator
{
private:
	node<T> *_ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	const_reverse_iterator() : _ptr(my_nullptr)
	{
	}

	explicit const_reverse_iterator(node<T> *ptr) : _ptr(ptr)
	{
	}

	const_reverse_iterator(const_reverse_iterator const &other) : _ptr(other._ptr)
	{
	}

	const_reverse_iterator(reverse_iterator<T> const &other) : _ptr(other.getNode())
	{
	}

	virtual ~const_reverse_iterator()
	{
	}

	const_reverse_iterator &operator=(const_reverse_iterator const &other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	const_reverse_iterator &operator++()
	{
		_ptr = _ptr->previous;
		return (*this);
	}

	const const_reverse_iterator operator++(int)
	{
		const_reverse_iterator it(_ptr);
		_ptr = _ptr->previous;
		return (it);
	}

	const_reverse_iterator &operator--()
	{
		_ptr = _ptr->next;
		return (*this);
	}

	const const_reverse_iterator operator--(int)
	{
		const_reverse_iterator it(_ptr);
		_ptr = _ptr->next;
		return (it);
	}

	bool operator==(const_reverse_iterator const &other)
	{
		return (_ptr == other._ptr);
	}

	bool operator!=(const_reverse_iterator const &other)
	{
		return (_ptr != other._ptr);
	}

	const reference operator*() const
	{
		return (*_ptr->data);
	}

	pointer operator->() const
	{
		return (_ptr->data);
	}
};

template <typename T>
class random_access_iterator
{
private:
	T *ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	random_access_iterator() : ptr(my_nullptr)
	{
	}

	explicit random_access_iterator(T *p) : ptr(p)
	{
	}

	random_access_iterator(const random_access_iterator &other)
	{
		*this = other;
	}

	virtual ~random_access_iterator()
	{
	}

	random_access_iterator &operator=(const random_access_iterator &other)
	{
		ptr = other.ptr;

		return (*this);
	}

	random_access_iterator &operator++()
	{
		ptr++;
		return (*this);
	}

	const random_access_iterator operator++(int)
	{
		random_access_iterator ret = random_access_iterator(*this);

		ptr++;
		return (ret);
	}

	const random_access_iterator &operator--()
	{
		ptr--;
		return (*this);
	}

	const random_access_iterator operator--(int)
	{

		random_access_iterator ret = random_access_iterator(*this);

		ptr--;
		return (ret);
	}

	bool operator==(random_access_iterator const &other)
	{
		return (ptr == other.ptr);
	}

	bool operator!=(random_access_iterator const &other)
	{
		return (ptr != other.ptr);
	}

	random_access_iterator operator+(std::ptrdiff_t n)
	{
		random_access_iterator tmp = *this;

		return (tmp += n);
	}

	random_access_iterator &operator+=(std::ptrdiff_t n)
	{
		std::ptrdiff_t i = n;

		if (i >= 0)
			while (i--)
				ptr++;
		else
			while (i++)
				ptr--;
		return (*this);
	}

	random_access_iterator operator-(long n)
	{
		random_access_iterator tmp = *this;

		return (tmp -= n);
	}

	random_access_iterator &operator-=(std::ptrdiff_t n)
	{
		return (*this += -n);
	}

	std::ptrdiff_t operator-(random_access_iterator &other)
	{
		return (ptr - other.ptr);
	}

	reference &operator[](std::ptrdiff_t n)
	{
		return (*(*this + n));
	}

	reference &operator*()
	{
		return (*ptr);
	}

	pointer *operator->()
	{
		return (ptr);
	}

	T *getPtr() const
	{
		return (ptr);
	}
};

template <typename T>
class const_random_access_iterator
{
private:
	T *ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	const_random_access_iterator() : ptr(my_nullptr)
	{
	}

	explicit const_random_access_iterator(T *p) : ptr(p)
	{
	}

	const_random_access_iterator(const const_random_access_iterator &other)
	{
		*this = other;
	}

	const_random_access_iterator(const random_access_iterator<T> &other)
	{
		*this = other;
	}

	virtual ~const_random_access_iterator()
	{
	}

	const_random_access_iterator &operator=(const const_random_access_iterator &other)
	{
		ptr = other.ptr;

		return (*this);
	}

	const_random_access_iterator &operator=(const random_access_iterator<T> &other)
	{
		ptr = other.getPtr();

		return (*this);
	}

	const_random_access_iterator &operator++()
	{
		ptr++;
		return (*this);
	}

	const const_random_access_iterator operator++(int)
	{
		const_random_access_iterator ret = const_random_access_iterator(*this);

		ptr++;
		return (ret);
	}

	const const_random_access_iterator &operator--()
	{
		ptr--;
		return (*this);
	}

	const const_random_access_iterator operator--(int)
	{

		const_random_access_iterator ret = const_random_access_iterator(*this);

		ptr--;
		return (ret);
	}

	bool operator==(const_random_access_iterator const &other)
	{
		return (ptr == other.ptr);
	}

	bool operator!=(const_random_access_iterator const &other)
	{
		return (ptr != other.ptr);
	}

	const_random_access_iterator operator+(std::ptrdiff_t n)
	{
		const_random_access_iterator tmp = *this;

		return (tmp += n);
	}

	const_random_access_iterator &operator+=(std::ptrdiff_t n)
	{
		std::ptrdiff_t i = n;

		if (i >= 0)
			while (i--)
				ptr++;
		else
			while (i++)
				ptr--;
		return (*this);
	}

	const_random_access_iterator operator-(long n)
	{
		const_random_access_iterator tmp = *this;

		return (tmp -= n);
	}

	const_random_access_iterator &operator-=(std::ptrdiff_t n)
	{
		return (*this += -n);
	}

	std::ptrdiff_t operator-(const_random_access_iterator &other)
	{
		return (ptr - other.ptr);
	}

	reference &operator[](std::ptrdiff_t n)
	{
		return (*(*this + n));
	}

	const reference &operator*() const
	{
		return (*ptr);
	}

	pointer *operator->() const
	{
		return (ptr);
	}
};

template <typename T>
class reverse_random_access_iterator
{
private:
	T *ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	reverse_random_access_iterator() : ptr(my_nullptr)
	{
	}

	reverse_random_access_iterator(T *p) : ptr(p)
	{
	}

	reverse_random_access_iterator(const reverse_random_access_iterator &other)
	{
		*this = other;
	}

	virtual ~reverse_random_access_iterator()
	{
	}

	reverse_random_access_iterator &operator=(const reverse_random_access_iterator &other)
	{
		ptr = other.ptr;

		return (*this);
	}

	reverse_random_access_iterator &operator++()
	{
		ptr--;
		return (*this);
	}

	const reverse_random_access_iterator operator++(int)
	{
		reverse_random_access_iterator ret = *this;

		ptr--;
		return (ret);
	}

	const reverse_random_access_iterator &operator--()
	{
		ptr++;
		return (*this);
	}

	const reverse_random_access_iterator operator--(int)
	{
		reverse_random_access_iterator ret = reverse_random_access_iterator(*this);

		ptr++;
		return (ret);
	}

	bool operator==(reverse_random_access_iterator const &other)
	{
		return (ptr == other.ptr);
	}

	bool operator!=(reverse_random_access_iterator const &other)
	{
		return (ptr != other.ptr);
	}

	reverse_random_access_iterator operator+(std::ptrdiff_t n)
	{
		reverse_random_access_iterator tmp = reverse_random_access_iterator(*this);

		return (tmp -= n);
	}

	reverse_random_access_iterator &operator+=(std::ptrdiff_t n)
	{
		std::ptrdiff_t i = n;

		if (i >= 0)
			while (i--)
				ptr--;
		else
			while (i++)
				ptr++;
		return (*this);
	}

	reverse_random_access_iterator operator-(long n)
	{
		reverse_random_access_iterator tmp = *this;

		return (tmp += n);
	}

	reverse_random_access_iterator &operator-=(std::ptrdiff_t n)
	{
		return (*this -= -n);
	}

	std::ptrdiff_t operator-(reverse_random_access_iterator &other)
	{
		return (ptr - other.ptr);
	}

	reference &operator[](std::ptrdiff_t n)
	{
		return (*(*this - n));
	}

	reference &operator*()
	{
		return (*ptr);
	}

	pointer *operator->()
	{
		return (ptr);
	}

	T *getPtr() const
	{
		return (ptr);
	}
};

template <typename T>
class const_reverse_random_access_iterator
{
private:
	T *ptr;

public:
	typedef typename std::allocator<T>::reference reference;
	typedef typename std::allocator<T>::pointer pointer;

	const_reverse_random_access_iterator() : ptr(my_nullptr)
	{
	}

	const_reverse_random_access_iterator(T *p) : ptr(p)
	{
	}

	const_reverse_random_access_iterator(const const_reverse_random_access_iterator &other)
	{
		*this = other;
	}

	const_reverse_random_access_iterator(const reverse_random_access_iterator<T> &other)
	{
		*this = other;
	}

	virtual ~const_reverse_random_access_iterator()
	{
	}

	const_reverse_random_access_iterator &operator=(const const_reverse_random_access_iterator &other)
	{
		ptr = other.ptr;

		return (*this);
	}

	const_reverse_random_access_iterator &operator=(const reverse_random_access_iterator<T> &other)
	{
		ptr = other.getPtr();

		return (*this);
	}

	const_reverse_random_access_iterator &operator++()
	{
		ptr--;
		return (*this);
	}

	const const_reverse_random_access_iterator operator++(int)
	{
		const_reverse_random_access_iterator ret = *this;

		ptr--;
		return (ret);
	}

	const const_reverse_random_access_iterator &operator--()
	{
		ptr++;
		return (*this);
	}

	const const_reverse_random_access_iterator operator--(int)
	{
		const_reverse_random_access_iterator ret = *this;

		ptr++;
		return (ret);
	}

	bool operator==(const_reverse_random_access_iterator const &other)
	{
		return (ptr == other.ptr);
	}

	bool operator!=(const_reverse_random_access_iterator const &other)
	{
		return (ptr != other.ptr);
	}

	const_reverse_random_access_iterator operator+(std::ptrdiff_t n)
	{
		const_reverse_random_access_iterator tmp = *this;

		return (tmp -= n);
	}

	const_reverse_random_access_iterator &operator+=(std::ptrdiff_t n)
	{
		std::ptrdiff_t i = n;

		if (i >= 0)
			while (i--)
				ptr--;
		else
			while (i++)
				ptr++;
		return (*this);
	}

	const_reverse_random_access_iterator &operator-=(std::ptrdiff_t n)
	{
		return (*this -= -n);
	}

	const_reverse_random_access_iterator operator-(long n)
	{
		const_reverse_random_access_iterator tmp = const_reverse_random_access_iterator(*this);

		return (tmp += n);
	}

	std::ptrdiff_t operator-(const_reverse_random_access_iterator &other)
	{
		return (ptr - other.ptr);
	}

	reference &operator[](std::ptrdiff_t n) const
	{
		return (*(*this - n));
	}

	const reference &operator*() const
	{
		return (*ptr);
	}

	pointer *operator->() const
	{
		return (ptr);
	}
};

#endif