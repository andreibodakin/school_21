#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

#include "AWeapon.hpp"

class   PlasmaRifle : public AWeapon
{
private:
    PlasmaRifle(PlasmaRifle const & src);
    std::string _name;
    int         _apcost;
    int         _damage;
    std::string _attack;

public:
    PlasmaRifle();
    PlasmaRifle(std::string const & name, int apcost, int damage);
    virtual ~PlasmaRifle();

    void attack() const;

    PlasmaRifle & operator=(PlasmaRifle const & rhs);
};

#endif
