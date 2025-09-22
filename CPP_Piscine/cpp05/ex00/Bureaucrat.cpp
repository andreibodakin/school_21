#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no_name"), _grade(150)
{
    std::cout << this->_name << " Bureaucrat - Default constructor call." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->_name << " Bureaucrat - Assignment constructor call." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->_name << " Bureaucrat - Copy constructor call." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->_name << " Bureaucrat - Destructor call." << std::endl;
}

const std::string & Bureaucrat::getName() const
{
    return (this->_name);
}

int     Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 > 0)
        this->_grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 < 151)
        this->_grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    this->_grade = rhs._grade;

    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << " have grade: " << rhs.getGrade() << std::endl;

    return (o);
}
