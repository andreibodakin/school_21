#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_Energy_points = 50;
    this->_Max_energy_points = 50;
    this->_Melee_attack_damage = 20;
    this->_Ranged_attack_damage = 15;
    this->_Armor_damage_reduction = 3;
    this->_Challenge[0] = "Hot Chili Challenge";
    this->_Challenge[1] = "Brain Freezer Challenge";
    this->_Challenge[2] = "Yoga Pose Challenge";
    this->_Challenge[3] = "Karaoke Challenge";
    this->_Challenge[4] = "Tornado Challenge";
    this->_Type = "ScavTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: I dare you!";
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_Name = name;
    this->_Energy_points = 50;
    this->_Max_energy_points = 50;
    this->_Melee_attack_damage = 20;
    this->_Ranged_attack_damage = 15;
    this->_Armor_damage_reduction = 3;
    this->_Challenge[0] = "Hot Chili Challenge";
    this->_Challenge[1] = "Brain Freezer Challenge";
    this->_Challenge[2] = "Yoga Pose Challenge";
    this->_Challenge[3] = "Karaoke Challenge";
    this->_Challenge[4] = "Tornado Challenge";
    this->_Type = "ScavTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: I dare you!";
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
    *this = src;
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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
    this->_Challenge[0] = rhs._Challenge[0];
    this->_Challenge[1] = rhs._Challenge[1];
    this->_Challenge[2] = rhs._Challenge[2];
    this->_Challenge[3] = rhs._Challenge[3];
    this->_Challenge[4] = rhs._Challenge[4];
    this->_Type = rhs._Type;
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

void    ScavTrap::challengeNewcomer(std::string const & target)
{
    int temp;
    
    temp = rand() % 5;
    std::cout << "There is no way this ends badly! ";
    std::cout << this->_Name;
    std::cout << " challengeNewcomer ";
    std::cout << target;
    std::cout << " with ";
    std::cout <<  _Challenge[temp];
    std::cout << std::endl;
    return ;
}
