#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const
{
    return (_name);
}

const std::string & Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string & title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


// void Warlock::learnSpell(ASpell * one)
// {
//     for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end(); ++i)
//     {
//         if ((*(*i)).getName() == one->getName())
//             return ;
//     }
//     _spells.push_back(one->clone());
// }

void Warlock::learnSpell(ASpell *one)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    if (one)
    {
        while (it != ite)
        {
            if ((*it)->getName() == one->getName())
                return ;
            ++it;
        }
        this->_spells.push_back(one->clone());
    }
}

void Warlock::forgetSpell(std::string name)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    while (it != ite)
    {
        if ((*it)->getName() == name)
        {
            delete *it;
            this->_spells.erase(it);
            return ;
        }
        ++it;
    }
}

void Warlock::launchSpell(std::string name, ATarget const & one)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    while (it != ite)
    {
        if ((*it)->getName() == name)
        {
            (*it)->launch(one);
            return ;
        }
        ++it;
    }
}
