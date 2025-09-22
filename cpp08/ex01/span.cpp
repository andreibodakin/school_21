#include "span.hpp"

Span::Span(): _n(0), _arr() {}

Span::Span(unsigned int maxSize): _n(maxSize), _arr() {}

Span::Span(const Span & src)
{
	*this = src;
}

Span::~Span() {}

Span & Span::operator=(const Span & src)
{
	if (this == &src)
		return *this;
	_n = src._n;
	_arr = src._arr;
	return (*this);
}

unsigned int	Span::shortestSpan()
{
	if (_arr.size() < 2)
		throw Span::NoSpan();
	unsigned int result;
	std::set<int>::iterator one = _arr.begin();
	std::set<int>::iterator two = _arr.begin();

	++two;
	result = static_cast<unsigned int>(*two) - static_cast<unsigned int>(*one);
	while (two != _arr.end())
	{
		if (static_cast<unsigned int>(*two) - static_cast<unsigned int>(*one) < result)
			result = static_cast<unsigned int>(*two) - static_cast<unsigned int>(*one);
		++one;
		++two;
	}
	return (result);
}

unsigned int	Span::longestSpan()
{
	if (_arr.size() < 2)
		throw Span::NoSpan();
	unsigned int result;

	result = static_cast<unsigned int>(*_arr.rbegin()) - static_cast<unsigned int>(*_arr.begin());
	return (result);
}

void	Span::addNumber(int n)
{
	if (_arr.size() == _n)
		throw Span::NoSize();
	_arr.insert(n);
}

void	Span::addNumber(int* start, int* end)
{
	if (_arr.size() + (end - start) > _n)
		throw Span::NoSize();
	_arr.insert(start, end);
}

unsigned int	Span::getSize()
{
	return (_arr.size());
}

const char* Span::NoSpan::what() const throw()
{
	return ("\x1b[31m No Span exception! \x1b[0m");
}

const char* Span::NoSize::what() const throw()
{
	return ("\x1b[32m No Size exception! \x1b[0m");
}
