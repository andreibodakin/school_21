#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main()
{
    try
    {
        ShrubberyCreationForm home("home");

        std::cout << std::endl;

        Bureaucrat Nicolas("Nicolas", 150);
        Nicolas.signForm(home);
        home.execute(Nicolas);

        std::cout << "Exeption not catched!!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    try
    {
        ShrubberyCreationForm home("home");

        std::cout << std::endl;

        Bureaucrat Ericson("Ericson", 145);
        Ericson.signForm(home);
        home.execute(Ericson);

        std::cout << "Exeption not catched!!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    try
    {
        std::cout << std::endl;

        Bureaucrat Xander("Xander", 1);

        std::cout << std::endl;

        RobotomyRequestForm dril("dril");
        Xander.signForm(dril);
        dril.execute(Xander);
        dril.execute(Xander);
        dril.execute(Xander);
        dril.execute(Xander);

        std::cout << "Exeption not catched!!!" << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    try
    {
        std::cout << std::endl;

        Bureaucrat Oiro("Oiro", 10);

        std::cout << std::endl;

        PresidentialPardonForm Ted("Ted");
        Oiro.signForm(Ted);
        Ted.execute(Oiro);

        std::cout << "Exeption not catched!!!" << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    try
    {
        std::cout << std::endl;

        Bureaucrat Xander("Xander", 1);

        std::cout << std::endl;

        PresidentialPardonForm Ted("Ted");

        Xander.signForm(Ted);
        Ted.execute(Xander);

        std::cout << "Exeption not catched!!!" << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    return (0);
}
