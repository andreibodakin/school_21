
#ifndef CPP_MODULE_00_WARLOCK_HPP
#define CPP_MODULE_00_WARLOCK_HPP

# include "Dummy.hpp"
# include "BrickWall.hpp"
# include "Fwoosh.hpp"
# include "Fireball.hpp"
# include "Polymorph.hpp"
# include "SpellBook.hpp"
# include "TargetGenerator.hpp"

class Warlock {
private:
    std::string _name;
    std::string _title;
    std::vector<ASpell*>    _spells;
    Warlock();
    Warlock(const Warlock&);
    Warlock& operator = (const Warlock&);
public:
    Warlock(std::string name, std::string title);
    virtual ~Warlock();

    const std::string &getName() const;
    const std::string &getTitle() const;

    void setTitle(const std::string &title);
    void introduce() const;

    void learnSpell(ASpell*);
    void forgetSpell(std::string);
    void launchSpell(std::string, ATarget&);
};


#endif
