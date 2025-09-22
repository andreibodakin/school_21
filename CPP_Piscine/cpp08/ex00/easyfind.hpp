#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

#include <set>
#include <list>
#include <vector>

template <typename T>
typename T::iterator easyfind(T & arr, int num)
{
    typename T::iterator i;
    i = std::find(arr.begin(), arr.end(), num);
    if (i == arr.end())
        throw std::out_of_range(std::string("\x1b[33m Error: Number not found. \x1b[0m"));
    return (i);
}

#endif
