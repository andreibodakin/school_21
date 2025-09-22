#ifndef ASPELL_H
# define ASPELL_H

#include <string>
// #include <iostream>


#include "ATarget.hpp" //!!!!
class ATarget;

// class ASpell; -del

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell();
        ASpell(std::string name, std::string effects);
        ASpell(const ASpell &);
        ASpell & operator=(const ASpell &);
        virtual ~ASpell(); //vitual!!

        const std::string & getName() const;
        const std::string & getEffects() const;

        virtual ASpell * clone() const = 0; //virtual!!
        void launch(const ATarget &) const; // const!!
};

#endif
