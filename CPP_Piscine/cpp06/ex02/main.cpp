#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int     num = rand() % 3;
    char    c = num + 65;

    std::cout << "gererate: " << c << std::endl;

    if (num == 0)
        return (new A);
    else if (num == 1)
        return (new B);
    return (new C);
}

void identify_from_pointer(Base * p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A";
    if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B";
    if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C";
}

void identify_from_reference(Base & p)
{
    if (dynamic_cast<A*>(&p) != NULL)
        std::cout << "A";
    if (dynamic_cast<B*>(&p) != NULL)
        std::cout << "B";
    if (dynamic_cast<C*>(&p) != NULL)
        std::cout << "C";
}

int main()
{
    srand(time(NULL));

    Base *ptr = generate();

    std::cout << "identify_from_pointer: ";
    identify_from_pointer(ptr);
    std::cout << std::endl;
    std::cout << "identify_from_reference: ";
    identify_from_reference(*ptr);
    std::cout << std::endl;

    return (0);
}
