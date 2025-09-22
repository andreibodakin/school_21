#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << " RobotomyRequestForm - Default constructor call." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
    srand(time(NULL));

	this->_target = target;

    std::cout << "RobotomyRequestForm - Assignment constructor call." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm - Destructor call." << std::endl;
}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);

    std::cout << "RRRrrrrrhhhh RRRRRrrrrhhh" << std::endl;

    if (rand() % 2)
        std::cout << Form::getName() << " has been robotomized " << this->_target << " successfully execute RobotomyRequestForm." << std::endl;
    else
        std::cout << Form::getName() << " has failure with " << this->_target << " Unsuccessufully execute RobotomyRequestForm." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src)
{
    this->_target = src._target;

    std::cout << Form::getName() << " RobotomyRequestForm - Copy constructor call." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    this->_target = rhs._target;

    return (*this);
}
