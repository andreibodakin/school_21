#ifndef ATARGET_H
# define ATARGET_H

#include <iostream>

#include "ASpell.hpp" //!!!

class ASpell;
// class ATarget; - del

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget(std::string type);
        ATarget(const ATarget &);
        ATarget & operator=(const ATarget &);

        virtual ~ATarget(); // virtual!!!

        const std::string & getType() const;

        virtual ATarget * clone() const = 0; // virtual!!!

        void getHitBySpell(const ASpell &) const; // const ASpell & !!!
};

#endif
