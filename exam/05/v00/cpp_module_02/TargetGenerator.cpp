#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    std::vector<ATarget *>::iterator it = _targets.begin();
    std::vector<ATarget *>::iterator ite = _targets.end();

    while (it != ite)
    {
        delete (*it);
        ++it;
    }
    _targets.clear();
}

void TargetGenerator::learnTargetType(ATarget * one)
{
    std::vector<ATarget *>::iterator it = _targets.begin();
    std::vector<ATarget *>::iterator ite = _targets.end();

    if (one)
    {
        while (it != ite)
        {
            if ((*it)->getType() == one->getType())
                return ;
            ++it;
        }
        _targets.push_back(one->clone());
    }
}

void TargetGenerator::forgetTargetType(const std::string & name)
{
    std::vector<ATarget *>::iterator it = _targets.begin();
    std::vector<ATarget *>::iterator ite = _targets.end();

    while (it != ite)
    {
        if ((*it)->getType() == name)
        {
            delete *it;
            _targets.erase(it);
            return ;
        }
        ++it;
    }
}

ATarget * TargetGenerator::createTarget(const std::string & name)
{
    std::vector<ATarget *>::iterator it = _targets.begin();
    std::vector<ATarget *>::iterator ite = _targets.end();

    while (it != ite)
    {
        if ((*it)->getType() == name)
            return (*it);
        ++it;
    }
    return (NULL);
}
