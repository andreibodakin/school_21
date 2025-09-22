#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed (void);
        Fixed (const int i);
        Fixed (const float f);
        Fixed (Fixed const & src);
        ~Fixed (void);

        Fixed & operator=(Fixed const & rhs);

        float   toFloat( void ) const;
        int     toInt( void ) const;

        void    setRawBits( int const raw );
        int     getRawBits( void ) const;

    private:
        int                 _i;
        static const int    _bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
