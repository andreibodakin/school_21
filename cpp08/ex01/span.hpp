#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stdexcept>

#include <set>

class   Span
{
    private:
        Span();

        unsigned int        _n;
        std::multiset<int>  _arr;
    
    public:
        Span(unsigned int n);
        Span(const Span & src);
        Span & operator=(Span const & rhs);
        ~Span();

        void                addNumber(int num);
        void                addNumber(int *start, int *end);
        unsigned int        shortestSpan();
        unsigned int        longestSpan();
        unsigned int        getSize();

        class NoSpan : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoSize : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
