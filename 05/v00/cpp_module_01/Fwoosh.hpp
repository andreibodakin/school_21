#ifndef FWOOSH_H
# define FWOOSH_H

// #include <iostream> - del

#include "ASpell.hpp" // !!!


class Fwoosh : public ASpell
{
    public:  // public !!!
        Fwoosh();
        Fwoosh(std::string name, std::string effects);
        
        Fwoosh(const Fwoosh &);
        Fwoosh & operator=(const Fwoosh &);

        virtual ~Fwoosh(); // virtual!!!

        ASpell * clone() const;
};

#endif
