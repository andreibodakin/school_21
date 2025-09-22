#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <stdexcept>
#include <iostream>
#include <string>

#include "Form.hpp"
// class  Form;

class   Bureaucrat
{
    private:
        Bureaucrat();
        Bureaucrat(Bureaucrat const & src);

        const std::string   _name;
        int                 _grade;

       Bureaucrat & operator=(Bureaucrat const & rhs);
    public:
        Bureaucrat(std::string const & name, int grade);
        virtual ~Bureaucrat();

        const std::string & getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        void                signForm(Form & one);

        class GradeTooHighException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
