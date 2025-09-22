#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
private:
    SuperMutant(int hp, std::string const & type);
    SuperMutant(SuperMutant const & src);
    int         _HP;
    std::string _type;

public:
    SuperMutant();
    virtual ~SuperMutant();

    void takeDamage(int damage);

    SuperMutant & operator=(SuperMutant const & rhs);
};

#endif
