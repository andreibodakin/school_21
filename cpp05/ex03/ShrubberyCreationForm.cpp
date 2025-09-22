#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << " ShrubberyCreationForm - Default constructor call." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target + "_shrubbery";
    this->_tree =   "                                               |   \n" \
                    "                                              -x-  \n" \
                    "                                               |   \n" \
                    "              v .   ._, |_  .,                     \n" \
                    "           `-._\\/  .  \\ /    |/_                   \n" \
                    "               \\  _\\, y | \\//                     \n" \
                    "         _\\_.___\\, \\/ -.\\||                      \n" \
                    "           `7-,--.`._||  / / ,                     \n" \
                    "           /'     `-. `./ / |/_.'                  \n" \
                    "                     |    |//                      \n" \
                    "                     |_    /                       \n" \
                    "                     |-   |                        \n" \
                    "                     |   =|                        \n" \
                    "                     |    |                        \n" \
                    "--------------------/ ,  . \\--------._             \n";

    std::cout << "ShrubberyCreationForm - Assignment constructor call." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm - Destructor call." << std::endl;
}

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);

    std::ofstream outfile (this->_target);
    outfile << this->_tree << std::endl;
    outfile.close();

    std::cout << "ShrubberyCreationForm executed by: " << executor.getName() << std::endl;
    std::cout  << "File: " << this->_target << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src)
{
    this->_target = src._target;
    this->_tree = src._tree;
    std::cout << Form::getName() << " ShrubberyCreationForm - Copy constructor call." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    this->_target = rhs._target;
    this->_tree = rhs._tree;

    return (*this);
}
