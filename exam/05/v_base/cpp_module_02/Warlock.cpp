
#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << _name << ": My job here is done!" << std::endl;
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end();) {
        delete (*i);
        i = _spells.erase(i);
    }
}

const std::string &Warlock::getName() const {
    return _name;
}

const std::string &Warlock::getTitle() const {
    return _title;
}

void Warlock::setTitle(const std::string &title) {
    _title = title;
}

void Warlock::introduce() const {
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end(); ++i) {
        if ((*(*i)).getName() == spell->getName()) {
            return;
        }
    }
    _spells.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string spell) {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end();) {
        if ((*(*i)).getName() == spell) {
            delete (*i);
            i = _spells.erase(i);
        }
        else
            i++;
    }
}

void Warlock::launchSpell(std::string spell, ATarget& target) {
    for (std::vector<ASpell*>::iterator i = _spells.begin(); i != _spells.end(); ++i) {
        if ((*(*i)).getName() == spell) {
            (*(*i)).launch(target);
            return;
        }
    }
}
