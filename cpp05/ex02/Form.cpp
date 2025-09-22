#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("no_name"), _sign_grade(1), _exec_grade(1), _sign(false)
{
    std::cout << this->_name << " Form - Default constructor call." << std::endl;
}

Form::Form(const std::string & name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _sign(false)
{
    if (this->_sign_grade < 1 || this->_exec_grade < 1)
        throw Form::GradeTooHighException();
    else if (this->_sign_grade > 150 || this->_exec_grade > 150)
        throw Form::GradeTooLowException();
    std::cout << this->_name << " Form - Assignment constructor call." << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade), _sign(src._sign)
{
    std::cout << this->_name << " Form - Copy constructor call." << std::endl;
}

Form::~Form()
{
    std::cout << this->_name << " Form - Destructor call." << std::endl;
}

const std::string & Form::getName() const
{
    return (this->_name);
}

int     Form::getSign_grade() const
{
    return (this->_sign_grade);
}

int     Form::getExec_grade() const
{
    return (this->_exec_grade);
}

bool     Form::getSign() const
{
    return (this->_sign);
}

Form & Form::operator=(Form const & rhs)
{
    this->_sign = rhs._sign;

    return (*this);
}

bool        Form::beSigned(Bureaucrat const & one)
{
    if (one.getGrade() <= this->_sign_grade)
        this->_sign = true;
    else
        return (false);
    return (true);
}

void        Form::execute(Bureaucrat const & executor) const
{
    if (this->_sign)
    {
        if (executor.getGrade() > this->_exec_grade)
            throw Form::GradeTooLowException();
    }
    else
        throw Form::UnsignedFormException();
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    std::string sign;

    if (rhs.getSign())
        sign = "sign";
    else
        sign = "unsing";

    o << "Form " << rhs.getName() << " is " << sign << ". Sing grade is " << rhs.getSign_grade();
    o << ". Execute grade is " << rhs.getExec_grade() << std::endl;

    return (o);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form: GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form: GradeTooLowException");
}

const char* Form::UnsignedFormException::what() const throw()
{
    return ("Form: UnsignedFormException \nCan't execute form. Form is not singed! \n");
}
