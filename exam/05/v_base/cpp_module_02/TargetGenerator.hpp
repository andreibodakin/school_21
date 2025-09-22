
#ifndef CPP_MODULE_02_TARGETGENERATOR_HPP
#define CPP_MODULE_02_TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <iostream>
# include <vector>

class TargetGenerator {
private:
    std::vector<ATarget*>    _targets;
    
    TargetGenerator(const TargetGenerator&);
    TargetGenerator& operator = (const TargetGenerator&);
public:
    TargetGenerator();
    virtual ~TargetGenerator();

    void learnTargetType(ATarget*);
    void forgetTargetType(const std::string&);
    ATarget* createTarget(const std::string&);
};


#endif
