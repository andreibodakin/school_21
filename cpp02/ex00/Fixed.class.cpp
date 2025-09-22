#include "Fixed.class.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_i = 0;

    return ;
}
Fixed::Fixed(const int i)
{
    std::cout << "Parametric constructor called" << std::endl;
    this->_i = (i << this->_bits);

    return ;
}
Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_i = src.getRawBits();
    *this = src;

    return ;
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    
    return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_i = rhs.getRawBits();

    return (*this);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_i = raw;
    return ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    
    return (this->_i);
}
