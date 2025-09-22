#ifndef ENEMY_H
# define ENEMY_H

#include <iostream>
#include <string>
#include <sstream>

class Enemy
{
protected:
    Enemy();
    Enemy(Enemy const & src);
    int         _HP;
    std::string _type;
    std::string _die_message;

public:
    Enemy(int hp, std::string const & type);
    virtual ~Enemy();
    const std::string & getType() const;
    int getHP() const;
    virtual void takeDamage(int damage);

    Enemy & operator=(Enemy const & rhs);
};

#endif
