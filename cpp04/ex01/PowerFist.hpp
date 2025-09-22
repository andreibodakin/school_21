#ifndef POWERFIRST_H
# define POWERFIRST_H

#include "AWeapon.hpp"

class   PowerFist : public AWeapon
{
private:
    PowerFist(PowerFist const & src);
    std::string _name;
    int         _apcost;
    int         _damage;
    std::string _attack;

public:
    PowerFist();
    PowerFist(std::string const & name, int apcost, int damage);
    virtual ~PowerFist();

    void attack() const;

    PowerFist & operator=(PowerFist const & rhs);
};

#endif
