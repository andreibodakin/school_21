#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main()
{
    std::cout << std::endl;

    try
    {
        Bureaucrat Alex("Alex", 50);
        std::cout << Alex;
        Alex.incrementGrade();
        std::cout << Alex;
        Alex.decrementGrade();
        std::cout << Alex;

        Form Secret("Secret", 10, 1);
        std::cout << Secret;
        Alex.signForm(Secret);
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Form TopSecret("TopSecret", 0, 1);
        std::cout << TopSecret;
    }
    catch(std::exception & e)
    {
        std::cerr << "Form Error: "  << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try
    {
        Bureaucrat Benedict("Benedict", 1);
        std::cout << Benedict;

        Form Secret("Secret", 10, 1);
        std::cout << Secret;
        Benedict.signForm(Secret);
        std::cout << Secret;
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    return (0);
}
