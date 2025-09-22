#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "Form.hpp"

class   RobotomyRequestForm : public Form
{
    private:
       RobotomyRequestForm();

       std::string  _target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        virtual ~RobotomyRequestForm();

        void    execute(Bureaucrat const & executor) const;

        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);  
};

#endif
