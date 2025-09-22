#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T const & min(T const & a, T const & b)
{
    return (a < b ? a : b);
}

template <typename T>
T const & max(T const & a, T const & b)
{
    return (a > b ? a : b);
}

class Awesome 
{
	public:
		Awesome() {}
		Awesome(int n) : _n(n) {}
		bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
		bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }

		int	getN() const { return _n; };
	private:
		int	_n;
};

std::ostream & operator<<(std::ostream & o, const Awesome & rhs)
{
	o << rhs.getN();
	return (o);
}

#endif
