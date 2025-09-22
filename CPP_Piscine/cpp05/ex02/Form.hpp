#ifndef FORM_H
# define FORM_H

// #include "Bureaucrat.hpp"

#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        const int           _sign_grade;
        const int           _exec_grade;
        bool                _sign;
    protected:
        Form();
        Form(Form const & src);
        Form & operator=(Form const & rhs);
    public:
        Form(const std::string & name, const int sign_grade, const int exec_grade);
        virtual ~Form();

        const std::string & getName() const;
        int                 getSign_grade() const;
        int                 getExec_grade() const;
        bool                getSign() const;

        bool                beSigned(Bureaucrat const & one);
        virtual void        execute(Bureaucrat const & executor) const = 0;

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

        class UnsignedFormException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
