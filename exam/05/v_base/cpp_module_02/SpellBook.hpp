
#ifndef CPP_MODULE_02_SPELLBOOK_HPP
#define CPP_MODULE_02_SPELLBOOK_HPP

# include "ASpell.hpp"
# include <iostream>
# include <vector>

class SpellBook {
private:
    std::vector<ASpell*>    _spells;
    SpellBook(const SpellBook&);
    SpellBook& operator = (const SpellBook&);
public:
    SpellBook();
    virtual ~SpellBook();

    void learnSpell(ASpell*);
    void forgetSpell(const std::string&);
    ASpell* createSpell(const std::string&);
};


#endif 