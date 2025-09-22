#ifndef ISQUAD_H
# define ISQUAD_H

#include <iostream>
#include <string>
#include <sstream>
#include <new>

#include "ISpaceMarine.hpp"

class ISquad
{
    public:
    virtual ~ISquad() {}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int unit) const = 0;
    virtual int push(ISpaceMarine* one) = 0;
};

#endif
