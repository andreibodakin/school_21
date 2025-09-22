#include "easyfind.hpp"

# define N_RED  21
# define RED    "\033[1;31m"
# define RESET  "\033[0m"

void    print(int i)
{
    if (i != N_RED)
        std::cout << i << " ";
    else
        std::cout << RED << i << RESET << " ";
}

int     main()
{
    srand(time(NULL));

    std::cout << std::endl;

    std::cout << "I wiil look for " << N_RED << " in these containers:" << std::endl;
    std::cout << std::endl;
    
    for (int j = 0; j < 10; j++)
    {
        std::set<int> set_test;
        for (int i = 0; i < 21; i++)
            set_test.insert(rand() % 42);
        std::cout << "Set: ";
        std::for_each (set_test.begin(), set_test.end(), print);
        std::cout << std::endl;
        try
        {
            std::set<int>::iterator i = easyfind(set_test, N_RED);
            std::cout << " Number " << N_RED << " found! It's index: " << std::distance(set_test.begin(), i) << std::endl;
        }
        catch(const std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    for (int j = 0; j < 10; j++)
    {
        std::list<int> list_test;
        for (int i = 0; i < 21; i++)
            list_test.push_back(rand() % 42);
        std::cout << "List: ";
        std::for_each (list_test.begin(), list_test.end(), print);
        std::cout << std::endl;
        try
        {
            std::list<int>::iterator i = easyfind(list_test, N_RED);
            std::cout << " Number " << N_RED << " found! It's index: " << std::distance(list_test.begin(), i) << std::endl;
        }
        catch(const std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < 10; j++)
    {
        std::vector<int> vector_test;
        for (int i = 0; i < 21; i++)
            vector_test.push_back(rand() % 42);
        std::cout << "Vector: ";
        std::for_each (vector_test.begin(), vector_test.end(), print);
        std::cout << std::endl;
        try
        {
            std::vector<int>::iterator i = easyfind(vector_test, N_RED);
            std::cout << " Number " << N_RED << " found! It's index: " << std::distance(vector_test.begin(), i) << std::endl;
        }
        catch(const std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }    
}
