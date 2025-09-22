#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include <string>
#include <sstream>

#include "PlasmaRifle.hpp"
#include "Enemy.hpp"

class   Character
{
private:
    Character();
    Character(Character const & src);
    std::string _Name;
    int         _AP;
    std::string _Weapon;
    AWeapon     *_Weapon_ptr;

public:
    Character(std::string const & name);
    ~Character();

    Character & operator=(Character const & rhs);

    int                 GetAP() const;
    const std::string & GetWeapon() const;
    void                recoverAP();
    void                equip(AWeapon* one);
    void                attack(Enemy* enemy);
    const std::string & GetName() const;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif
