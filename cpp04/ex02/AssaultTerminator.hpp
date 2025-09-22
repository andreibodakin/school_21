#ifndef ASSAULTTERMINATOR_H
# define ASSAULTTERMINATOR_H

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
private:
    AssaultTerminator(AssaultTerminator const & src);

public:
    AssaultTerminator();
    virtual ~AssaultTerminator();

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;

    AssaultTerminator & operator=(AssaultTerminator const & rhs);
};

#endif
