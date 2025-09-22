#ifndef ITER_H
# define ITER_H

#include <iostream>
#include <cstdlib>

class Awesome
{
    public:
        Awesome(void) : _n(42) { return; }
        int get(void) const { return this->_n; }
    private:
        int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

template< typename T>
void print(T & x)
{
    std::cout << x << std::endl;
    return; 
}

template< typename T>
void increment(T & x)
{
    x += 1;
    std::cout << x << std::endl;
    return; 
}

template< typename T>
void    iter(T *tab, int len, void f(T &))
{
    for (int i = 0; i < len; i++)
        f(tab[i]);
}

#endif
