
############ CPP_MODULE_00 ########### Polymorphism

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
        Warlock(const std::string &, const std::string &);
        ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;

        void setTitle(const std::string &);
        void introduce() const;
};

#endif



#include "Warlock.hpp"

Warlock::Warlock(const std::string & name, const std::string & title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const
{
    return (_name);
}

const std::string & Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string & title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}





############ CPP_MODULE_01 ########### Inheritance



#ifndef ASPELL_H
# define ASPELL_H

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell();
        ASpell(const std::string &, const std::string &);
        ASpell(const ASpell &);
        ASpell & operator=(const ASpell &);
        virtual ~ASpell();

        const std::string & getName() const;
        const std::string & getEffects() const;

        virtual ASpell * clone() const = 0;
        void launch(const ATarget &) const;
};

#include "ATarget.hpp"

#endif




#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects() {}

ASpell::ASpell(const std::string & name, const std::string & effects) : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell & one) 
{
    *this = one;
}

ASpell & ASpell::operator=(const ASpell & one)
{
    _name = one._name;
    _effects = one._effects;
    return (*this);
}

ASpell::~ASpell() {}

const std::string & ASpell::getName() const
{
    return (_name);
}

const std::string & ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(const ATarget & one) const
{
    one.getHitBySpell(*this);
}



#ifndef ATARGET_H
# define ATARGET_H

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget(const std::string &);
        ATarget(const ATarget &);
        ATarget & operator=(const ATarget &);
        virtual ~ATarget();

        const std::string & getType() const;

        virtual ATarget * clone() const = 0;
        void getHitBySpell(const ASpell &) const;
};

#include "ASpell.hpp"

#endif



#include "ATarget.hpp"

ATarget::ATarget() : _type() {}

ATarget::ATarget(const std::string & type) : _type(type) {}

ATarget::ATarget(const ATarget & one)
{
    *this = one;
}

ATarget & ATarget::operator=(const ATarget & one)
{
    _type = one._type;
    return (*this);
}

ATarget::~ATarget() {}

const std::string & ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(const ASpell & one) const  
{
    std::cout << _type << " has been " << one.getEffects() << "!" << std::endl;
}




#ifndef DUMMY_H
# define DUMMY_H

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        ~Dummy();

        virtual ATarget * clone() const;
};

#endif



#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

ATarget *Dummy::clone() const
{
    return (new Dummy(*this));
}




#ifndef FWOOSH_H
# define FWOOSH_H

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        virtual ~Fwoosh();

        virtual ASpell * clone() const;
};

#endif



#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

ASpell *Fwoosh::clone() const
{
    return (new Fwoosh(*this));
}




#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        Warlock();
        Warlock(const Warlock &);
        Warlock & operator=(const Warlock &);

        std::string _name;
        std::string _title;

        std::vector<ASpell *> _spells;
    public:
        Warlock(const std::string &, const std::string &);
        ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;

        void setTitle(const std::string &);
        void introduce() const;

        void learnSpell(ASpell *);
        void forgetSpell(std::string);
        void launchSpell(std::string, const ATarget &);
};

#endif



#include "Warlock.hpp"

Warlock::Warlock(const std::string & name, const std::string & title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    while (it != ite)
    {
        delete *it;
        ++it;
    }
    _spells.clear();
    std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const
{
    return (_name);
}

const std::string & Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string & title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell * one)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    if (one)
    {
        while (it != ite)
        {
            if ((*it)->getName() == one->getName())
                return ;
            ++it;
        }
        this->_spells.push_back(one->clone());
    }
}

void Warlock::forgetSpell(std::string name)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    while (it != ite)
    {
        if ((*it)->getName() == name)
        {
            delete *it;
            this->_spells.erase(it);
            return ;
        }
        ++it;
    }
}

void Warlock::launchSpell(std::string name, const ATarget & one)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();
    while (it != ite)
    {
        if ((*it)->getName() == name)
        {
            (*it)->launch(one);
            return ;
        }
        ++it;
    }
}




############ CPP_MODULE_02 ########### Encapsulation



#ifndef ASPELL_H
# define ASPELL_H

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell();
        ASpell(const std::string &, const std::string &);
        ASpell(const ASpell &);
        ASpell & operator=(const ASpell &);
        virtual ~ASpell();

        const std::string & getName() const;
        const std::string & getEffects() const;

        virtual ASpell * clone() const = 0;
        void launch(const ATarget &) const;
};

#include "ATarget.hpp"

#endif



#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects() {}

ASpell::ASpell(const std::string & name, const std::string & effects) : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell & one) 
{
    *this = one;
}

ASpell & ASpell::operator=(const ASpell & one)
{
    _name = one._name;
    _effects = one._effects;
    return (*this);
}

ASpell::~ASpell() {}

const std::string & ASpell::getName() const
{
    return (_name);
}

const std::string & ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(const ATarget & one) const
{
    one.getHitBySpell(*this);
}



#ifndef ATARGET_H
# define ATARGET_H

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget(const std::string &);
        ATarget(const ATarget &);
        ATarget & operator=(const ATarget &);
        virtual ~ATarget();

        const std::string & getType() const;

        virtual ATarget * clone() const = 0;
        void getHitBySpell(const ASpell &) const;
};

#include "ASpell.hpp"

#endif



#include "ATarget.hpp"

ATarget::ATarget() : _type() {}

ATarget::ATarget(const std::string & type) : _type(type) {}

ATarget::ATarget(const ATarget & one)
{
    *this = one;
}

ATarget & ATarget::operator=(const ATarget & one)
{
    _type = one._type;
    return (*this);
}

ATarget::~ATarget() {}

const std::string & ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(const ASpell & one) const  
{
    std::cout << _type << " has been " << one.getEffects() << "!" << std::endl;
}




#ifndef BRICKWALL_H
# define BRICKWALL_H

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        ~BrickWall();
        
        virtual ATarget * clone() const;
};

#endif



#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

ATarget * BrickWall::clone() const
{
    return (new BrickWall(*this));
}




#ifndef DUMMY_H
# define DUMMY_H

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        ~Dummy();
        
        virtual ATarget * clone() const;
};

#endif



#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

ATarget * Dummy::clone() const
{
    return (new Dummy(*this));
}




#ifndef FIREBALL_H
# define FIREBALL_H

#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        virtual ~Fireball();
        
        virtual ASpell * clone() const;
};

#endif



#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

ASpell * Fireball::clone() const
{
    return (new Fireball(*this));
}




#ifndef FWOOSH_H
# define FWOOSH_H

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();
        
        virtual ASpell * clone() const;
};

#endif



#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

ASpell * Fwoosh::clone() const
{
    return (new Fwoosh(*this));
}




#ifndef POLYMORPH_H
# define POLYMORPH_H

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        ~Polymorph();
        
        virtual ASpell * clone() const;
};

#endif



#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

ASpell * Polymorph::clone() const
{
    return (new Polymorph(*this));
}




#ifndef SPELLBOOK_H
# define SPELLBOOK_H

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"

class SpellBook
{
    private:
        std::vector<ASpell *> _spells;

        SpellBook(const SpellBook &);
        SpellBook & operator=(const SpellBook &);
    public:
        SpellBook();
        virtual ~SpellBook();

        void learnSpell(ASpell *);
        void forgetSpell(const std::string &);
        ASpell * createSpell(const std::string &);
};

#endif



#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();

    while (it != ite)
    {
        delete *it;
        ++it;
    }
    this->_spells.clear();
}

void SpellBook::learnSpell(ASpell * one)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();

    if (one)
    {
        while (it != ite)
        {
            if ((*it)->getName() == one->getName())
                return ;
            ++it;
        }
        this->_spells.push_back(one->clone());
    }
}

void SpellBook::forgetSpell(const std::string & name)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();

    while (it != ite)
    {
        if ((*it)->getName() == name)
        {
            delete *it;
            this->_spells.erase(it);
            return ;
        }
        ++it;
    }
}

ASpell * SpellBook::createSpell(const std::string & name)
{
    std::vector<ASpell *>::iterator it = this->_spells.begin();
    std::vector<ASpell *>::iterator ite = this->_spells.end();

    while (it != ite)
    {
        if ((*it)->getName() == name)
            return (*it);
        ++it;
    }
    return (NULL);
}




#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::vector<ATarget *> _targets;

        TargetGenerator(const TargetGenerator &);
        TargetGenerator & operator=(const TargetGenerator &);
    public:
        TargetGenerator();
        virtual ~TargetGenerator();

        void learnTargetType(ATarget *);
        void forgetTargetType(const std::string &);
        ATarget * createTarget(const std::string &);
};

#endif



#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    std::vector<ATarget *>::iterator it = this->_targets.begin();
    std::vector<ATarget *>::iterator ite = this->_targets.end();

    while (it != ite)
    {
        delete (*it);
        ++it;
    }
    this->_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget * one)
{
    std::vector<ATarget *>::iterator it = this->_targets.begin();
    std::vector<ATarget *>::iterator ite = this->_targets.end();

    if (one)
    {
        while (it != ite)
        {
            if ((*it)->getType() == one->getType())
                return ;
            ++it;
        }
        this->_targets.push_back(one->clone());
    }
}

void TargetGenerator::forgetTargetType(const std::string & name)
{
    std::vector<ATarget *>::iterator it = this->_targets.begin();
    std::vector<ATarget *>::iterator ite = this->_targets.end();

    while (it != ite)
    {
        if ((*it)->getType() == name)
        {
            delete *it;
            this->_targets.erase(it);
            return ;
        }
        ++it;
    }
}

ATarget * TargetGenerator::createTarget(const std::string & name)
{
    std::vector<ATarget *>::iterator it = this->_targets.begin();
    std::vector<ATarget *>::iterator ite = this->_targets.end();

    while (it != ite)
    {
        if ((*it)->getType() == name)
            return (*it);
        ++it;
    }
    return (NULL);
}




#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        SpellBook _book;;

        Warlock();
        Warlock(const Warlock &);
        Warlock & operator=(const Warlock &);
    public:
        Warlock(const std::string &, const std::string &);
        virtual ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;

        void setTitle(const std::string &);

        void introduce() const;

        void learnSpell(ASpell *);
        void forgetSpell(std::string);
        void launchSpell(std::string, const ATarget &);
};

#endif



#include "Warlock.hpp"

Warlock::Warlock(const std::string & name, const std::string & title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const
{
    return (_name);
}

const std::string & Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string & title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell * one)
{
    _book.learnSpell(one);
}

void Warlock::forgetSpell(std::string name)
{
    _book.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, const ATarget & one)
{
    ASpell *tmp = _book.createSpell(name);
    if (tmp)
        tmp->launch(one);
}
