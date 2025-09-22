#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
private:
    TacticalMarine(TacticalMarine const & src);

public:
    TacticalMarine();
    virtual ~TacticalMarine();

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;

    TacticalMarine & operator=(TacticalMarine const & rhs);
};

#endif
