#ifndef ATARGET_H
# define ATARGET_H

#include <iostream>
#include <string>

#include "ASpell.hpp" // yes that's important!
class ASpell;

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget(std::string type);
        ATarget(const ATarget &);
        ATarget & operator=(const ATarget &);
        virtual ~ATarget();

        const std::string & getType() const;
        
        virtual ATarget * clone() const = 0;
        void getHitBySpell(const ASpell &) const;
};

#endif
