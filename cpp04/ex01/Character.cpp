#include "Character.hpp"

Character::Character()
{
    this->_Name = "noname";
    this->_AP = 40;
    this->_Weapon = "is unarmed";
    this->_Weapon_ptr = 0;
    return ;
}

Character::Character(std::string const & name)
{
    this->_Name = name;
    this->_AP = 40;
    this->_Weapon = "is unarmed";
    this->_Weapon_ptr = 0;
    return ;
}

Character::~Character()
{
    return ;
}

const std::string & Character::GetName() const
{
    return (this->_Name);
}

int         Character::GetAP() const
{
    return (this->_AP);
}

const std::string & Character::GetWeapon() const
{
    return (this->_Weapon);
}

void                Character::equip(AWeapon* one)
{
    this->_Weapon = one->getName();
    this->_Weapon_ptr = one;
}

void                Character::recoverAP()
{
    if (this->_AP + 10 < 40)
    {
        std::cout << "Recovering + 10 AP" << std::endl;
        this->_AP += 10;
    }
    else
    {
        std::cout << "Recovering to max AP of 40" << std::endl;
        this->_AP = 40;
    }
}

void                Character::attack(Enemy* enemy)
{
    if (this->_Weapon == "is unarmed")
        std::cout << this->_Name << " " << this->_Weapon << " and I can't attack.." << std::endl;
    else if (this->_AP - _Weapon_ptr->getAPCost() < 0)
        std::cout << "Not enough AP. I can't attack!";
    else
    {
        std::cout << this->_Name << " attacks " << enemy->getType() << " with a " << this->_Weapon << std::endl;
        this->_Weapon_ptr->attack();
        enemy->takeDamage(_Weapon_ptr->getDamage());
        this->_AP = this->_AP - _Weapon_ptr->getAPCost();
    }
}

Character::Character(Character const & src)
{
    *this = src;
    std::cout << "*Character call copy constructor*";
    return ;
}

Character & Character::operator=(Character const & rhs)
{
    this->_Name = rhs._Name;
    this->_AP = rhs._AP;
    this->_Weapon = rhs._Weapon;
    this->_Weapon_ptr = rhs._Weapon_ptr;
    
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Character const & rhs)
{
    if (rhs.GetWeapon() == "is unarmed")
        o << rhs.GetName() << " has " << rhs.GetAP() << " AP and " << rhs.GetWeapon() << std::endl;
    else
        o << rhs.GetName() << " has " << rhs.GetAP() << " AP and wields a " << rhs.GetWeapon() << std::endl;
    return (o);
}
