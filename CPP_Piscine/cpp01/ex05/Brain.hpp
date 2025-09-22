#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
    public:
        Brain (void);
        ~Brain (void);

        void        setType(std::string str);
        std::string getType(void);
        void        setIq(std::string str);
        std::string getIq(void);

        std::string identify(void) const;
    private:
        std::string _type;
        std::string _iq;
};

#endif
