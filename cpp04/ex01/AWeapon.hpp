#ifndef AWEAPON_H
# define AWEAPON_H

#include <iostream>
#include <string>
#include <sstream>

class AWeapon
{
protected:
    AWeapon();
    AWeapon(AWeapon const & src);
    std::string _name;
    int         _apcost;
    int         _damage;

public:
    AWeapon(std::string const & name, int apcost, int damage);
    virtual ~AWeapon();
    const std::string & getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;

    AWeapon & operator=(AWeapon const & rhs);
};

#endif
