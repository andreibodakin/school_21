
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    for (std::vector<ATarget*>::iterator i = _targets.begin(); i != _targets.end();) {
        delete (*i);
        i = _targets.erase(i);
    }
}

void TargetGenerator::learnTargetType(ATarget* spell) {
    for (std::vector<ATarget*>::iterator i = _targets.begin(); i != _targets.end(); ++i) {
        if ((*(*i)).getType() == spell->getType()) {
            return;
        }
    }
    _targets.push_back(spell->clone());
}

void TargetGenerator::forgetTargetType(const std::string& spell) {
    for (std::vector<ATarget*>::iterator i = _targets.begin(); i != _targets.end();) {
        if ((*(*i)).getType() == spell) {
            delete (*i);
            i = _targets.erase(i);
        }
        else
            i++;
    }
}

//ATargetarget* TargetGenerator::createTarget(const std::string& spell) {
//    for (std::vector<ATarget*>::iterator i = _targets.begin(); i != _targets.end(); ++i) {
//        if ((*(*i)).getType() == spell) {
//            return ((*(*i)).clone());
//        }
//    }
//    return NULL;
//}
