#include "Convert.hpp"

int     main(int argc, char *argv[])
{
    try
    {
        if (argc == 2)
        {
            Convert result(argv[1]);
            std::cout << result << std::endl;
        }
        else
        {
            std::cerr << "Error: Wrong number of arguments!" << std::endl;
            return (1);
        }
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

	// std::cout << "double: " << std::numeric_limits<double>::min() << std::endl;
	// std::cout << "float: " << std::numeric_limits<float>::min() << std::endl;
	// std::cout << "int: " << std::numeric_limits<int>::min() << std::endl;

    return (0);
}
