#include "Convert.hpp"

Convert::Convert()
{}

Convert::Convert(char *argv)
{
	std::string			av(argv);
	std::stringstream 	ss;
	long int			tmp_int;
	double				tmp_double;
	char				*pEnd;

	errno = 0;
	if (av.empty())
		throw	Convert::BadString();
	if (av == "-inf" || av == "+inf" || av == "nan")
	{
		this->str_char = "impossible";
		this->str_int = "impossible";
		this->str_float = av + "f";
		this->str_double = av;
		return ;
	}
	else if (av == "-inff" || av == "+inff" || av == "nanf")
	{
		this->str_char = "impossible";
		this->str_int = "impossible";
		this->str_float = av;
		av.erase(av.end() - 1);
		this->str_double = av;
		return ;
	}
	else if (av.find('.') != std::string::npos)
	{
		this->num_double = strtod(argv, &pEnd);

		if (errno == ERANGE)
		{
			this->str_char = "overflow";
			this->str_int = "overflow";
			this->str_float = "overflow";
			this->str_double = "overflow";
			return ;
		}
		else
		{
			ss << this->num_double << ".0";
			this->str_double = ss.str();
			ss.str(std::string());	
		}

		if (this->num_double > std::numeric_limits<float>::max() 
			|| this->num_double < -std::numeric_limits<float>::max())
			this->str_float = "overflow";
		else
		{
			this->num_float = static_cast<float>(this->num_double);

			ss << this->num_float << ".0f";
			this->str_float = ss.str();
			ss.str(std::string());
		}

		if (this->str_float == "overflow" || this->num_float > std::numeric_limits<int>::max() 
			|| this->num_float < std::numeric_limits<int>::min())
			this->str_int = "overflow";
		else
		{
			this->num_int = static_cast<int>(this->num_float);

			ss << this->num_int;
			this->str_int = ss.str();
			ss.str(std::string());
		}
		
		if (this->str_int == "overflow")
			this->str_char = "overflow";
		else
		{
			this->num_char = static_cast<int>(num_double);

			ss << "'" << this->num_char << "'";
			this->str_char = ss.str();
			ss.str(std::string());
		}	
	}
	else if (av.size() == 1 && !isdigit(av[0]))
	{
		this->num_char = av[0];

		this->num_int = static_cast<int>(this->num_char);
		this->num_float = static_cast<float>(this->num_char);
		this->num_double = static_cast<double>(this->num_char);

		ss << "'" << this->num_char << "'";
		this->str_char = ss.str();
		ss.str(std::string());

		ss << this->num_int;
		this->str_int = ss.str();
		ss.str(std::string());		

		ss << this->num_float << ".0f";
		this->str_float = ss.str();
		ss.str(std::string());

		ss << this->num_double << ".0";
		this->str_double = ss.str();
		ss.str(std::string());		
	}
	else if ((tmp_int = strtol(argv, &pEnd, 10)) || (av == "0"))
	{
		if (errno == ERANGE)
		{
			this->str_char = "overflow";
			this->str_int = "overflow";
			this->str_float = "overflow";
			this->str_double = "overflow";
			return ;
		}
		else if (tmp_int > std::numeric_limits<int>::max() 
				|| tmp_int < std::numeric_limits<int>::min())
		{
			this->str_int = "overflow";
			this->str_char = "overflow";

			this->num_float = static_cast<float>(tmp_int);

			ss << this->num_float << ".0f";
			this->str_float = ss.str();
			ss.str(std::string());

			this->num_double = static_cast<double>(tmp_int);

			ss << this->num_double << ".0";
			this->str_double = ss.str();
			ss.str(std::string());
		}
		else
		{
			this->num_int = (int)tmp_int;

			ss << this->num_int;
			this->str_int = ss.str();
			ss.str(std::string());

			this->num_char = static_cast<char>(this->num_int);

			ss << "'" << this->num_char << "'";
			this->str_char = ss.str();
			ss.str(std::string());

			this->num_float = static_cast<float>(this->num_int);

			ss << this->num_float << ".0f";
			this->str_float = ss.str();
			ss.str(std::string());

			this->num_double = static_cast<double>(this->num_int);

			ss << this->num_double << ".0";
			this->str_double = ss.str();
			ss.str(std::string());
		}
	}
	else
		throw	Convert::BadString();

	if (this->str_char == "impossible" || this->str_char == "overflow")
		return ;
	else if (this->num_char < 32 || this->num_char > 126)
		this->str_char = "Non displayable";
	return ;
}

Convert::Convert(Convert const &other)
{
	(void)other;
}

Convert::~Convert()
{}

Convert &Convert::operator=(Convert const &other)
{
	(void)other;
	return(*this);
}

const char* Convert::BadString::what() const throw()
{
	return ("BadString");
}

std::string Convert::getStr_Char() const
{
	return (this->str_char);
}

std::string Convert::getStr_Int() const
{
	return (this->str_int);
}

std::string Convert::getStr_Float() const
{
	return (this->str_float);
}

std::string Convert::getStr_Double() const
{
	return (this->str_double);
}

std::ostream & operator<<(std::ostream & out, Convert const & base)
{
	std::cout << "char:\t" << base.getStr_Char() << std::endl;
	std::cout << "int:\t" << base.getStr_Int() << std::endl;
	std::cout << "float:\t" << base.getStr_Float() << std::endl;
	std::cout << "double:\t" << base.getStr_Double();
	return (out);
}
