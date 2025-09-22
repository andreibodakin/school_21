#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *	_array;
	public:
		Array();
		Array(unsigned int n);
		Array(Array<T> const & src);
		~Array();

		unsigned int size() const;

		class BadIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		T & operator[](unsigned int i);
		Array<T> & operator=(Array<T> const & rhs);
};

template<typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_array = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n]();
}

template<typename T>
Array<T>::Array(Array<T> const & src)
{
	if (src._size > 0)
	{
		this->_array = new T[src._size]();
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
		this->_size = src._size;
	}
	else
	{
		this->_size = 0;
		this->_array = NULL;
	}
}

template<typename T>
Array<T>::~Array()
{
	if (this->_size > 0)
		delete[] this->_array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
const char *Array<T>::BadIndexException::what() const throw()
{
	return "BadIndexException";
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs)
{
	if (this->_size > 0)
		delete[] this->_array;
	if (rhs._size > 0)
	{
		this->_array = new T[rhs._size]();
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
		this->_size = rhs._size;
	}
	else
	{
		this->_size = 0;
		this->_array = NULL;
	}
	return (*this);
}

template<typename T>
T & Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw Array<T>::BadIndexException();
	return (this->_array[i]);
}

#endif
