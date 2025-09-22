#include "Contact.class.hpp"

Contact::Contact(void)
{
    // std::cout << "Constructor called" << std::endl;

    return ;
}
Contact::~Contact(void)
{
    // std::cout << "Destructor called" << std::endl;
    
    return ;
}

int         Contact::getIndex(void)
{
    return (this->_index);
}
void        Contact::setIndex(int nbr)
{
    this->_index = nbr;
    return ;
}

std::string Contact::getFirstName(void)
{
    return (this->_first_name);
}
void        Contact::setFirstName(std::string str)
{
    this->_first_name = str;
    return ;
}

std::string Contact::getLastName(void)
{
    return (this->_last_name);
}
void        Contact::setLastName(std::string str)
{
    this->_last_name = str;
    return ;
}

std::string Contact::getNickname(void)
{
    return (this->_nickname);
}
void        Contact::setNickname(std::string str)
{
    this->_nickname = str;
    return ;
}

std::string Contact::getLogin(void)
{
    return (this->_login);
}
void        Contact::setLogin(std::string str)
{
    this->_login = str;
    return ;
}

std::string Contact::getAddress(void)
{
    return (this->_address);
}
void        Contact::setAddress(std::string str)
{
    this->_address = str;
    return ;
}

std::string Contact::getEmail(void)
{
    return (this->_email);
}
void        Contact::setEmail(std::string str)
{
    this->_email = str;
    return ;
}

std::string Contact::getPhone(void)
{
    return (this->_phone);
}
void        Contact::setPhone(std::string str)
{
    this->_phone = str;
    return ;
}

std::string Contact::getBirthday(void)
{
    return (this->_birthday);
}
void        Contact::setBirthday(std::string str)
{
    this->_birthday = str;
    return ;
}

std::string Contact::getMeal(void)
{
    return (this->_meal);
}
void        Contact::setMeal(std::string str)
{
    this->_meal = str;
    return ;
}

std::string Contact::getUnderwear(void)
{
    return (this->_underwear);
}
void        Contact::setUnderwear(std::string str)
{
    this->_underwear = str;
    return ;
}

std::string Contact::getSecret(void)
{
    return (this->_secret);
}
void        Contact::setSecret(std::string str)
{
    this->_secret = str;
    return ;
}
