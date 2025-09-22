#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
    this->_Hit_points = FragTrap::_Hit_points;
    this->_Max_hit_points = FragTrap::_Max_hit_points;
    this->_Energy_points = NinjaTrap::_Energy_points;
    this->_Max_energy_points = NinjaTrap::_Max_energy_points;
    this->_Melee_attack_damage = NinjaTrap::_Melee_attack_damage;
    this->_Ranged_attack_damage = FragTrap::_Ranged_attack_damage;
    this->_Armor_damage_reduction = FragTrap::_Armor_damage_reduction;
    this->_Type = "SuperTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I love it here!";
    std::cout << std::endl;
    return ;
}

SuperTrap::SuperTrap(std::string name)
{
    this->_Name = name;

    this->_Hit_points = 60;
    this->_Max_hit_points = 60;
    this->_Energy_points = 120;
    this->_Max_energy_points = 120;
    this->_Melee_attack_damage = 60;
    this->_Ranged_attack_damage = 5;
    this->_Armor_damage_reduction = 0;
    this->_Type = "SuperTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I love it here!";
    std::cout << std::endl;
    return ;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
    *this = src;
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

SuperTrap::~SuperTrap(void)
{
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs)
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
