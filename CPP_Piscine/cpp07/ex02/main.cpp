#include "Array.hpp"

int     main()
{
    srand(time(NULL));

    // int * a = new int();
    // std::cout << *a << std::endl;

    Array<int> arr_empty;
    std::cout << "Empty array:\t\t" << arr_empty.size();
    std::cout << std::endl;

    Array<int> int_zero(10);
    std::cout << "Default int array:\t";
    for (int i = 0; i < int_zero.size(); i++)
        std::cout << int_zero[i] << " ";
    std::cout << std::endl;

    Array<char> char_zero(7);
    std::cout << "Default char array:\t";
    for (int i = 0; i < char_zero.size(); i++)
        std::cout << "\'" << char_zero[i] << "\'" << " ";
    std::cout << std::endl;

    Array<int> arr_int(10);
    std::cout << arr_int.size()  << " int array:\t\t";
    for (int i = 0; i < arr_int.size(); i++)
    {
        arr_int[i] = rand() % 10;
        std::cout << arr_int[i] << " ";
    }
    std::cout << std::endl;

    std::string str = "Abcdefghijklmnopqrstuvwxyz";
    Array<char> arr_char(10);
    std::cout << arr_char.size() << " char array:\t\t";
    for (int i = 0; i < arr_char.size(); i++)
    {
        arr_char[i] = str[rand() % str.size()];
        std::cout << arr_char[i] << " ";
    }
    std::cout << std::endl;

    return (0);
}
