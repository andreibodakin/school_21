#include "Human.hpp"

Human::Human(void)
{
    std::cout << "New Human created" << std::endl;

    return ;
}
Human::~Human(void)
{
    std::cout << "Human say goodbye" << std::endl;
    return ;
}

std::string Human::identify(void) const
{
    return (this->_head.identify());
}

const Brain &Human::getBrain(void)
{
    return (this->_head);
}
