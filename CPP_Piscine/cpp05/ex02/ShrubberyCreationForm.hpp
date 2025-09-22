#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class   ShrubberyCreationForm : public Form
{
    private:
       ShrubberyCreationForm();

       std::string  _target;
       std::string  _tree;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        virtual ~ShrubberyCreationForm();

        void    execute(Bureaucrat const & executor) const;

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
};

#endif
