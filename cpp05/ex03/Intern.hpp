#ifndef INTERN_H
# define INTERN_H

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class   Intern
{
    private:
        Intern(Intern const & src);
        Intern & operator=(Intern const & rhs);
    public:
        Intern();
        virtual ~Intern();

        Form    *makeForm(std::string name, std::string target);

        class UnknownForm : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
