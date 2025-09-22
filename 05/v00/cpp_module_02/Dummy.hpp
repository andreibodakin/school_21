#ifndef DUMMY_H
# define DUMMY_H

#include <iostream>
#include <string>

#include "ATarget.hpp"
class ATarget;

class Dummy : public ATarget
{
    public:
        Dummy();
        Dummy(std::string type);
        Dummy(const Dummy &);
        Dummy & operator=(const Dummy &);
        virtual ~Dummy();
        
        ATarget * clone() const;
};

#endif
