#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
    public:
        Pony (void);
        ~Pony (void);

        std::string getName(void);
        void        setName(std::string);
        std::string getColor(void);
        void        setColor(std::string);
        std::string getBirthday(void);
        void        setBirthday(std::string);
        std::string getWeight(void);
        void        setWeight(std::string);

    private:
        std::string _name;
        std::string _color;
        std::string _birthday;
        std::string _weight;
};

#endif
