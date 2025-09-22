#include "Bureaucrat.hpp"

int     main()
{
    try
    {
        Bureaucrat Sebastien("Sebastien", 0);
        std::cout << Sebastien;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << "High grade Error: ";
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << "Low grade Error: ";
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: ";
        std::cerr << e.what() << std::endl;
    };

    std::cout << std::endl;

    try
    {
        Bureaucrat Kevin("Kevin", 151);
        std::cout << Kevin;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat Alex("Alex", 50);
        std::cout << Alex;
        Alex.incrementGrade();
        std::cout << Alex;
        Alex.decrementGrade();
        std::cout << Alex;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try
    {
        Bureaucrat Benedict("Benedict", 1);
        std::cout << Benedict;
        Benedict.incrementGrade();
        std::cout << Benedict << "O my god! My grade is 0!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat Tracy("Tracy", 150);
    	std::cout << Tracy;
        Tracy.decrementGrade();
        std::cout << Tracy << "O my god! My grade is 151!!" << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr  << "Error: " << e.what() << std::endl;
    }

    return (0);
}
