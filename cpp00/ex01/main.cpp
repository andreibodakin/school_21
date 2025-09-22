#include "Contact.class.hpp"

void    search_function_print(Contact *instance)
{
    std::cout << std::endl;
    std::cout << "Here is the information about the contact you selected:" << std::endl;

    std::cout << "First Name: " << instance->getFirstName() << std::endl;
    std::cout << "Last Name: " << instance->getLastName() << std::endl;
    std::cout << "Nickname: " << instance->getNickname() << std::endl;
    std::cout << "Login: " << instance->getLogin() << std::endl;
    std::cout << "Postal Address: " << instance->getAddress() << std::endl;
    std::cout << "Email address: " << instance->getEmail() << std::endl;
    std::cout << "Phone number: " << instance->getPhone() << std::endl;
    std::cout << "Birthday: " << instance->getBirthday() << std::endl;
    std::cout << "Favorite Meal: " << instance->getMeal() << std::endl;
    std::cout << "Underwear color: " << instance->getUnderwear() << std::endl;
    std::cout << "Darkest Secret: " << instance->getSecret() << std::endl;

    std::cout << std::endl;
    std::cout << "Enter \"EXIT\" to exit." << std::endl;
    std::cout << std::endl;
}

int     search_function_select(int  i)
{
    int         result;
    std::string str;
    int         y;
    
    y = 0;
    while (y++ < 45)
        std::cout << "-";
    std::cout << std::endl;
    std::cout << "Please enter the desired contact index: ";
    std::getline(std::cin, str);
    try
    {
        result = std::stoi( str );
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
    }
    while (result > i || result < 1)
    {
        std::cout << "Please enter the VALID contact index: ";
        std::getline(std::cin, str);
        try
        {
            result = std::stoi( str );
        }
        catch (std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << '\n';
        }
    }
    return (result);
}

void    search_function_list()
{
    int     i;
    
    std::cout << "List of available contacts:" << std::endl;
        i = 0;
    while (i++ < 45)
        std::cout << "-";
    std::cout << std::endl;
    std::cout << "|" << "     index" << "|" << "first name" << "|";
    std::cout << " last name" << "|" << "  nickname" << "|" << std::endl;
    i = 0;
    while (i++ < 45)
        std::cout << "-";
    std::cout << std::endl;
}

void    search_function_line(Contact *instance)
{
    std::string temp_str;
    int         temp_nbr;

    std::cout << "|" << "         " << instance->getIndex();
    
    temp_str = instance->getFirstName();
    if (temp_str.size() > 10)
    {
        temp_str.resize(9);
        temp_str = temp_str + ".";
    }
    else if (temp_str.size() < 10)
    {
        temp_nbr = 10 - temp_str.size();
        temp_str.assign(temp_nbr, ' ');
        temp_str = temp_str + instance->getFirstName();
    }
    std::cout << "|" << temp_str;

    temp_str = instance->getLastName();
    if (temp_str.size() > 10)
    {
        temp_str.resize(9);
        temp_str = temp_str + ".";
    }
    else if (temp_str.size() < 10)
    {
        temp_nbr = 10 - temp_str.size();
        temp_str.assign(temp_nbr, ' ');
        temp_str = temp_str + instance->getLastName();
    }
    std::cout << "|" << temp_str;

    temp_str = instance->getNickname();
    if (temp_str.size() > 10)
    {
        temp_str.resize(9);
        temp_str = temp_str + ".";
    }
    else if (temp_str.size() < 10)
    {
        temp_nbr = 10 - temp_str.size();
        temp_str.assign(temp_nbr, ' ');
        temp_str = temp_str + instance->getNickname();
    }
    std::cout << "|" << temp_str;

    std::cout << "|" << std::endl;
}

void    add_function(Contact *instance, int i)
{
    std::string temp;

    instance->setIndex(i);

    std::cout << "Creating new contact." << std::endl;

    std::cout << "Please enter First Name: ";
    std::getline(std::cin, temp);
    instance->setFirstName(temp);

    std::cout << "Please enter Last Name: ";
    std::getline(std::cin, temp);
    instance->setLastName(temp);

    std::cout << "Please enter Nickname: ";
    std::getline(std::cin, temp);
    instance->setNickname(temp);

    std::cout << "Please enter Login: ";
    std::getline(std::cin, temp);
    instance->setLogin(temp);

    std::cout << "Please enter Postal Address: ";
    std::getline(std::cin, temp);
    instance->setAddress(temp);

    std::cout << "Please enter Email address: ";
    std::getline(std::cin, temp);
    instance->setEmail(temp);

    std::cout << "Please enter Phone number: ";
    std::getline(std::cin, temp);
    instance->setPhone(temp);

    std::cout << "Please enter Birthday: ";
    std::getline(std::cin, temp);
    instance->setBirthday(temp);

    std::cout << "Please enter Favorite Meal: ";
    std::getline(std::cin, temp);
    instance->setMeal(temp);

    std::cout << "Please enter Underwear color: ";
    std::getline(std::cin, temp);
    instance->setUnderwear(temp);

    std::cout << "Please enter Darkest Secret: ";
    std::getline(std::cin, temp);
    instance->setSecret(temp);

    std::cout << "New contact created!" << std::endl;
    return ;
}

int main(void)
{
    Contact     instance[8];
    std::string command;
    int         i;
    int         y;
    int         select;

    i = 0;
    std::cout << "Welcome to My Awesome PhoneBook." << std::endl;
    std::cout << "Commands are \"ADD\", \"SEARCH\" and \"EXIT\"." << std::endl;

    while (21)
    {
        std::cout << "Enter your command: ";
        std::getline(std::cin, command);
        if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break ;
        }
        else if (command == "ADD")
        {
            if (i < 8)
            {
                add_function(&instance[i], i + 1);
                i++;
            }
            else
                std::cout << "No memory left!" << std::endl;  
        }
        else if (command == "SEARCH")
        {
            select = 0;
            search_function_list();
            y = 0;
            while(y < i)
                search_function_line(&instance[y++]);
            select = search_function_select(i);
            search_function_print(&instance[select - 1]);
        }
        else
            std::cout << "Wrong command" << std::endl;
    }

    return (0);
}
