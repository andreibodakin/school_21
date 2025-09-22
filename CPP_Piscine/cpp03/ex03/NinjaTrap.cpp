#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
    this->_Hit_points = 60;
    this->_Max_hit_points = 60;
    this->_Energy_points = 120;
    this->_Max_energy_points = 120;
    this->_Melee_attack_damage = 60;
    this->_Ranged_attack_damage = 5;
    this->_Armor_damage_reduction = 0;
    this->_Type = "NinjaTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! Check out my package!";
    std::cout << std::endl;
    return ;
}

NinjaTrap::NinjaTrap(std::string name)
{
    this->_Name = name;

    this->_Hit_points = 60;
    this->_Max_hit_points = 60;
    this->_Energy_points = 120;
    this->_Max_energy_points = 120;
    this->_Melee_attack_damage = 60;
    this->_Ranged_attack_damage = 5;
    this->_Armor_damage_reduction = 0;
    this->_Type = "NinjaTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! Check out my package!";
    std::cout << std::endl;
    return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
    *this = src;
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
{
    this->_Name = rhs._Name;
    this->_Hit_points = rhs._Hit_points;
    this->_Max_hit_points = rhs._Max_hit_points;
    this->_Energy_points = rhs._Energy_points;
    this->_Max_energy_points = rhs._Max_energy_points;
    this->_Level = rhs._Level;
    this->_Melee_attack_damage = rhs._Melee_attack_damage;
    this->_Ranged_attack_damage = rhs._Ranged_attack_damage;
    this->_Armor_damage_reduction = rhs._Armor_damage_reduction;
    this->_Type = rhs._Type;
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}


void    NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
    std::cout << this->_Type << " attacks " << trap.getName() << " with a Sword!" << std::endl;
    trap.takeDamage(this->_Melee_attack_damage);
}

void    NinjaTrap::ninjaShoebox(FragTrap &trap)
{
    std::cout << this->_Type << " attacks " << trap.getName() << " with a Nunchucks!" << std::endl;
    trap.takeDamage(this->_Melee_attack_damage);
}

void    NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
    std::cout << this->_Type << " attacks " << trap.getName() << " with a Ninja Star!" << std::endl;
    trap.takeDamage(this->_Melee_attack_damage);
}

void    NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
    std::cout << this->_Type << " performs the seppuku to " << trap.getName() << " in the code of honor." << std::endl;
}
