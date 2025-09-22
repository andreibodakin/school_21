#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>

#include "Dummy.hpp" // !!!
#include "Fwoosh.hpp" // !!!

#include <vector>

// class ASpell; - del
// class ATarget; - del

class Warlock
{
    private:
        Warlock();
        Warlock(const Warlock &);
        Warlock & operator=(const Warlock &);

        std::string _name;
        std::string _title;

        std::vector<ASpell*> _spells;   // ASpell* !!!!!!!!
    public:
        Warlock(std::string name, std::string title);
        virtual ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;

        void setTitle(const std::string & title);
        void introduce() const;


        void learnSpell(ASpell *);
        void forgetSpell(std::string);

        void launchSpell(std::string,const ATarget &); // std::string, ATarget & !!! and launch !!
};

#endif
