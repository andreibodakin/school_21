#ifndef DUMMY_H
# define DUMMY_H

// #include <iostream> - del

#include "ATarget.hpp" // !!!

class Dummy : public ATarget
{
    public:  // public !!!
        Dummy();
        Dummy(std::string type);
        Dummy(const Dummy &);
        Dummy & operator=(const Dummy &);

        virtual ~Dummy(); // virtual

        ATarget * clone() const;
};

#endif
