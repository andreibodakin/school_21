#ifndef BRICKWALL_H
# define BRICKWALL_H

#include <iostream>
#include <string>

#include "ATarget.hpp"
class ATarget;

class BrickWall : public ATarget
{
    public:
        BrickWall();
        BrickWall(std::string type);
        BrickWall(const BrickWall &);
        BrickWall & operator=(const BrickWall &);
        virtual ~BrickWall();
        
        ATarget * clone() const;
};

#endif
