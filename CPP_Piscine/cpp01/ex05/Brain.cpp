#include "Brain.hpp"

Brain::Brain(void)
{
    return ;
}
Brain::~Brain(void)
{
    return ;
}

void        Brain::setType(std::string str)
{
    this->_type = str;
    return ;
}
std::string Brain::getType(void)
{
    return (this->_type);
}

void        Brain::setIq(std::string str)
{
    this->_iq = str;
    return ;
}
std::string Brain::getIq(void)
{
    return (this->_iq);
}

std::string Brain::identify(void) const
{
    std::stringstream   s_strem;
    unsigned long       mem = (unsigned long)this;

    s_strem << "0x" << std::uppercase << std::hex << mem;

    return (s_strem.str());
}