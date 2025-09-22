

#ifndef CPP_MODULE_02_BRICKWALL_HPP
#define CPP_MODULE_02_BRICKWALL_HPP

# include "ATarget.hpp"

class BrickWall : public ATarget{
public:
    BrickWall();
    BrickWall(std::string type);
    BrickWall(const BrickWall&);
    BrickWall& operator = (const BrickWall&);

    virtual ~BrickWall();
    ATarget* clone() const;
};

#endif 
