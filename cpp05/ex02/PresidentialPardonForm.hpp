#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class   PresidentialPardonForm : public Form
{
    private:
       PresidentialPardonForm();

       std::string  _target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        virtual ~PresidentialPardonForm();

        void    execute(Bureaucrat const & executor) const;

        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);  
};

#endif
