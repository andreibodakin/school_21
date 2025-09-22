#ifndef CONVERT_H
# define CONVERT_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>
#include <string>
#include <cerrno>
#include <float.h>

class Convert
{
	private:
		Convert();

		char 	num_char;
		int 	num_int;
		float 	num_float;
		double 	num_double;

		std::string str_char;
		std::string str_int;
		std::string str_float;
		std::string str_double;
	public:
		Convert(char *argv);
		Convert(Convert const &other);
		~Convert();

		Convert &operator=(Convert const &other);

		std::string getStr_Char() const;
		std::string getStr_Int() const;
		std::string getStr_Float() const;
		std::string getStr_Double() const;

		class BadString: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & out, Convert const & base);

#endif
