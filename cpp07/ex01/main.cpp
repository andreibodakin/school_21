#include "iter.hpp"

int     main()
{
    double tab3[] = {20.21, 20.21, 20.21, 20.21, 20.21};

    int tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[5];

    iter(tab3, 5, increment);

    std::cout << std::endl;

    iter( tab, 5, print);
    iter( tab2, 5, print);

    return (0);
}
