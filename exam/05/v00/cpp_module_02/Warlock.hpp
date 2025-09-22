#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <string>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

#include <vector>

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        SpellBook _book;;

        Warlock();
        Warlock(const Warlock &);
        Warlock & operator=(const Warlock &);
    public:
        Warlock(std::string name, std::string title);
        virtual ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;

        void setTitle(const std::string &);
        void introduce() const;

        void learnSpell(ASpell *);
        void forgetSpell(std::string);
        void launchSpell(std::string, const ATarget &);
};

#endif
