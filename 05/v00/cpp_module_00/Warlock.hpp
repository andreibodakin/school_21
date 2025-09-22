#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        
        Warlock();
        Warlock(const Warlock &);
        Warlock & operator=(const Warlock &);
    public:
        Warlock(std::string name, std::string title);
        virtual ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;

        void setTitle(const std::string & title);
        void introduce() const;
};

#endif
