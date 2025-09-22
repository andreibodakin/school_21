#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed
{
    public:
        Fixed (void);
        Fixed (const int i);
        Fixed (Fixed const & src);
        ~Fixed (void);

        Fixed & operator=(Fixed const & rhs);

        void    setRawBits( int const raw );
        int     getRawBits( void ) const;
    private:
        int                 _i;
        static const int    _bits = 8;
};

#endif
