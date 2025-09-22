#ifndef CPP01_02_FWOOSH_HPP
#define CPP01_02_FWOOSH_HPP

# include "ASpell.hpp"

class Fwoosh : public ASpell {
public:
    Fwoosh();
    Fwoosh(std::string name, std::string effects);
    Fwoosh(const Fwoosh&);
    Fwoosh& operator = (const Fwoosh&);
    virtual ~Fwoosh();

    ASpell* clone() const;
};

#endif //CPP01_02_FWOOSH_HPP
