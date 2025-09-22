#include "whatever.hpp"

int     main()
{
    int e = 21;
    int f = 42;
    Awesome One(1);
    Awesome Two(2);

    std::cout << std::endl;

    std::cout << "21 and 42 before swap: " << e << " " << f << std::endl;
    swap(e, f);
    std::cout << "21 and 42 after swap: " << e << " "  << f << std::endl;

    std::cout << "Awesome before swap: " << One << " " << Two << std::endl;
    swap(One, Two);
    std::cout << "Awesome after swap: " << One << " "  << Two << std::endl;

    std::cout << std::endl;

    std::cout << "Max of 21 and 42 is: " << max(e, f) << std::endl;
    std::cout << "Max of Awesome " << One << " and " << Two << " is: " << max(One, Two) << std::endl;
    
    std::cout << std::endl;

    std::cout << "Min of 21 and 42 is: " << min(e, f) << std::endl;
    std::cout << "Min of Awesome " << One << " and " << Two << " is: " << min(One, Two) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << std::endl;

    return (0);
}
