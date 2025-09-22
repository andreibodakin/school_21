#ifndef RADSCORPION_H
# define RADSCORPION_H

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
private:
    RadScorpion(int hp, std::string const & type);
    RadScorpion(RadScorpion const & src);
    int         _HP;
    std::string _type;

public:
    RadScorpion();
    virtual ~RadScorpion();

    RadScorpion & operator=(RadScorpion const & rhs);
};

#endif
