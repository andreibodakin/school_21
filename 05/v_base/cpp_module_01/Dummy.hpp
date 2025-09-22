

#ifndef CPP01_02_DUMMY_HPP
#define CPP01_02_DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget{
public:
    Dummy();
    Dummy(std::string type);
    Dummy(const Dummy&);
    Dummy& operator = (const Dummy&);

    virtual ~Dummy();
    ATarget* clone() const;
};


#endif //CPP01_02_DUMMY_HPP
