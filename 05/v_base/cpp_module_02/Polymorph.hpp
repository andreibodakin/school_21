

#ifndef CPP_MODULE_02_POLYMORPH_HPP
#define CPP_MODULE_02_POLYMORPH_HPP

# include "ASpell.hpp"

class Polymorph : public ASpell {
public:
    Polymorph();
    Polymorph(std::string name, std::string effects);
    Polymorph(const Polymorph&);
    Polymorph& operator = (const Polymorph&);

    virtual ~Polymorph();
    ASpell* clone() const;
};

#endif 