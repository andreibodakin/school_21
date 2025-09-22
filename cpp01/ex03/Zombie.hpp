#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

std::string randomName(void);
std::string randomType(void);

class Zombie
{
    public:
        Zombie (void);
        ~Zombie (void);

        void        setName(std::string name);
        std::string getName(void);
        void        setType(std::string type);
        std::string getType(void);

        void        announce(void);
    private:
        std::string _name;
        std::string _type;
};

#endif
