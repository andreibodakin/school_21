#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    for (std::vector<ASpell *>::iterator i = _spells.begin(); i != _spells.end();)
    {
        delete (*i);
        i = _spells.erase(i);
    }
}

void SpellBook::learnSpell(ASpell * one)
{
    std::vector<ASpell *>::iterator it = _spells.begin();
    std::vector<ASpell *>::iterator ite = _spells.end();

    if (one)
    {
        while (it != ite)
        {
            if ((*it)->getName() == one->getName())
                return ;
            ++it;
        }
        _spells.push_back(one->clone());
    }
}

void SpellBook::forgetSpell(const std::string & name)
{
    std::vector<ASpell *>::iterator it = _spells.begin();
    std::vector<ASpell *>::iterator ite = _spells.end();

    while (it != ite)
    {
        if ((*it)->getName() == name)
        {
            delete *it;
            _spells.erase(it);
            return ;
        }
        ++it;
    }
}

ASpell * SpellBook::createSpell(const std::string & name)
{
    std::vector<ASpell *>::iterator it = _spells.begin();
    std::vector<ASpell *>::iterator ite = _spells.end();

    while (it != ite)
    {
        if ((*it)->getName() == name)
            return (*it);
        ++it;
    }
    return (NULL);
}
