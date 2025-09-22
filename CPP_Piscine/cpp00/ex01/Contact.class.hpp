#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact
{
    public:
        Contact (void);
        ~Contact (void);

        int         getIndex(void);
        void        setIndex(int);

        std::string getFirstName(void);
        void        setFirstName(std::string);

        std::string getLastName(void);
        void        setLastName(std::string);

        std::string getNickname(void);
        void        setNickname(std::string);

        std::string getLogin(void);
        void        setLogin(std::string);

        std::string getAddress(void);
        void        setAddress(std::string);

        std::string getEmail(void);
        void        setEmail(std::string);

        std::string getPhone(void);
        void        setPhone(std::string);

        std::string getBirthday(void);
        void        setBirthday(std::string);

        std::string getMeal(void);
        void        setMeal(std::string);

        std::string getUnderwear(void);
        void        setUnderwear(std::string);

        std::string getSecret(void);
        void        setSecret(std::string);

    private:
        int         _index;
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _login;
        std::string _address;
        std::string _email;
        std::string _phone;
        std::string _birthday;
        std::string _meal;
        std::string _underwear;
        std::string _secret;
};

#endif
