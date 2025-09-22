#include "Intern.hpp"

Intern::Intern()
{
    std::cout << " Intern - Default constructor call." << std::endl;
}

Intern::Intern(Intern const & src)
{
    (void)src;
    std::cout << " Intern - Copy constructor call." << std::endl;
}

Intern::~Intern()
{
    std::cout << " Intern - Destructor call." << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
    (void)rhs;

    return (*this);
}

Form    *Intern::makeForm(std::string name, std::string target)
{
    Form        *result;
    std::string test[3] = {"hrubbery", "obotomy", "residential"};
    int         type = -1;

    while (++type < 3)
    {
        if (name.find(test[type]) != std::string::npos)
            break;
    }

    switch(type)
    {
        case 0:
            result = new ShrubberyCreationForm(target);
            std::cout << "Inter creates: ShrubberyCreationForm" << std::endl;
            break;
        case 1:
            result = new RobotomyRequestForm(target);
            std::cout << "Inter creates: RobotomyRequestForm" << std::endl;
            break;
        case 2:
            result = new PresidentialPardonForm(target);
            std::cout << "Inter creates: PresidentialPardonForm" << std::endl;
            break;
        default:
            throw Intern::UnknownForm();
            break;
    }

    std::cout << "Form target is: " << target << std::endl;

    return (result);
}

const char* Intern::UnknownForm::what() const throw()
{
    return ("Intern: I don't know this form! \n");
}
