#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << " PresidentialPardonForm - Default constructor call." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
    srand(time(NULL));

	this->_target = target;

    std::cout << "PresidentialPardonForm - Assignment constructor call." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm - Destructor call." << std::endl;
}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);

    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src)
{
    this->_target = src._target;

    std::cout << Form::getName() << " PresidentialPardonForm - Copy constructor call." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    this->_target = rhs._target;

    return (*this);
}
