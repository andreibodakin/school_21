#ifndef ASPELL_H
# define ASPELL_H

#include <iostream>
#include <string>

#include "ATarget.hpp"
class ATarget;

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
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;
        
        virtual ASpell * clone() const = 0;
        void launch(const ATarget &) const;
};

#endif
