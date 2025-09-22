

#ifndef CPP_MODULE_02_FIREBALL_HPP
#define CPP_MODULE_02_FIREBALL_HPP

# include "ASpell.hpp"

class Fireball : public ASpell {
public:
    Fireball();
    Fireball(std::string name, std::string effects);
    Fireball(const Fireball&);
    Fireball& operator = (const Fireball&);

    virtual ~Fireball();
    ASpell* clone() const;
};

#endif 