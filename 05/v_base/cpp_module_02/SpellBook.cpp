
#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end();) {
        delete (*i);
        i = _spells.erase(i);
    }
}

void SpellBook::learnSpell(ASpell* spell) {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end(); ++i) {
        if ((*(*i)).getName() == spell->getName()) {
            return;
        }
    }
    _spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string& spell) {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end();) {
        if ((*(*i)).getName() == spell) {
            delete (*i);
            i = _spells.erase(i);
        }
        else
            i++;
    }
}

ASpell* SpellBook::createSpell(const std::string& spell) {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end(); ++i) {
        if ((*(*i)).getName() == spell) {
            return ((*(*i)).clone());
        }
    }
    return NULL;
}
