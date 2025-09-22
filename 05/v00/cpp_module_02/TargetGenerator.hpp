#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::vector<ATarget *> _targets;

        TargetGenerator(const TargetGenerator &);
        TargetGenerator & operator=(const TargetGenerator &);
    public:
        TargetGenerator();
        virtual ~TargetGenerator();

        void learnTargetType(ATarget *);
        void forgetTargetType(const std::string &);
        ATarget * createTarget(const std::string &);
};

#endif
