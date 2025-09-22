#ifndef SPELLBOOK_H
# define SPELLBOOK_H

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"

class SpellBook
{
    private:
        std::vector<ASpell *> _spells;


        SpellBook(const SpellBook &);
        SpellBook & operator=(const SpellBook &);
    public:
        SpellBook();
        virtual ~SpellBook();

        void learnSpell(ASpell *);
        void forgetSpell(const std::string &);
        ASpell * createSpell(const std::string &);
};

#endif
