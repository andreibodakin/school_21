#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; ++i)
        {
            str = av[i];
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            std::cout << str;
        }
    }
    std::cout << std::endl;
    return (0);
}