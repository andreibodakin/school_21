#include "span.hpp"

# define BIG 1000000

int     main()
{
    srand(time(NULL));

    std::cout << std::endl << "Subject Span test:" << std::endl;

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << std::endl;

    std::cout << "Basic Span test:" << std::endl;

	Span myBasicSpan = Span(2);

	try
	{
		myBasicSpan.addNumber(1);
		myBasicSpan.addNumber(1);
		std::cout << "Span size:\t" << myBasicSpan.getSize() << std::endl;
		std::cout << "Shortest span:\t" << myBasicSpan.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << myBasicSpan.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << std::endl << "Big Span test:" << std::endl;
	Span myBigSpan(BIG);
	int	tmp[BIG];

	for(int i = 0; i < BIG; i++)
		tmp[i] = std::rand();

	try
	{
		myBigSpan.addNumber(tmp, tmp + BIG);
		std::cout << "Span size:\t" << myBigSpan.getSize() << std::endl;
		std::cout << "Shortest span:\t" << myBigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << myBigSpan.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "Exception test:" << std::endl;
	Span myExcepSpan(0);

	try
	{
		myExcepSpan.addNumber(1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << myExcepSpan.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << myExcepSpan.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "Int min and max test:" << std::endl;
	Span myMinMaxSpan(3);
	try
	{
		myMinMaxSpan.addNumber(0);
		myMinMaxSpan.addNumber(2147483647);
		myMinMaxSpan.addNumber(-2147483648);
		std::cout << "Shortest span:\t" << myMinMaxSpan.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << myMinMaxSpan.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
