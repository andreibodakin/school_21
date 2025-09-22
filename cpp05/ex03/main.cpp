#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int     main()
{
    try
    {
        Intern  someRandomIntern;
        Form    *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        std::cout << "Exeption not catched!!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Intern  someRandomIntern;
        Form    *rrf;

        rrf = someRandomIntern.makeForm("Presidential Pardon", "Tom");

        std::cout << "Exeption not catched!!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Intern  someRandomIntern;
        Form    *rrf;

        rrf = someRandomIntern.makeForm("wrong form", "test");

        std::cout << "Exeption not catched!!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat Leto("Leto", 15);
        Intern  newIntern;
        Form    *tree;

        tree = newIntern.makeForm("shrubbery creation", "tree");

        Leto.signForm(*tree);
        (*tree).execute(Leto);

        std::cout << "Exeption not catched!!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    return (0);
}
