#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_Energy_points = 100;
    this->_Max_energy_points = 100;
    this->_Melee_attack_damage = 30;
    this->_Ranged_attack_damage = 20;
    this->_Armor_damage_reduction = 5;
    this->_Attacks[0] = "Perfect Susanoo";
    this->_Attacks[1] = "Roof Tile Shuriken";
    this->_Attacks[2] = "Hidden Lotus";
    this->_Attacks[3] = "Twin Rising Dragons";
    this->_Attacks[4] = "Full Power Ninja";
    this->_Type = "FragTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! Check out my package!";
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name)
{
    this->_Name = name;

    this->_Energy_points = 100;
    this->_Max_energy_points = 100;
    this->_Melee_attack_damage = 30;
    this->_Ranged_attack_damage = 20;
    this->_Armor_damage_reduction = 5;
    this->_Attacks[0] = "Perfect Susanoo";
    this->_Attacks[1] = "Roof Tile Shuriken";
    this->_Attacks[2] = "Hidden Lotus";
    this->_Attacks[3] = "Twin Rising Dragons";
    this->_Attacks[4] = "Full Power Ninja";
    this->_Type = "FragTrap";
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! Check out my package!";
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const & src)
{
    *this = src;
    std::cout << this->_Type;
    std::cout << " constructed. ";
    std::cout << this->_Name;
    std::cout << " tells: Hey everybody! I've been copied!";
    std::cout << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << this->_Type;
    std::cout << " ";
    std::cout << this->_Name;
    std::cout << " tells: No no no, you're not dead, you're destructed.";
    std::cout << std::endl;
    return ;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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
    this->_Attacks[0] = rhs._Attacks[0];
    this->_Attacks[1] = rhs._Attacks[1];
    this->_Attacks[2] = rhs._Attacks[2];
    this->_Attacks[3] = rhs._Attacks[3];
    this->_Attacks[4] = rhs._Attacks[4];
    this->_Type = rhs._Type;
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    int temp;
    
    if (this->_Energy_points >= 25)
        this->_Energy_points -= 25;
    else
        {
            std::cout << "NO Energy points for vaulthunter" << std::endl;
            return ;
        }
    temp = rand() % 5;
    std::cout << "Let's get this party started!! FR4G-TP ";
    std::cout << this->_Name;
    std::cout << " vaulthunter ";
    std::cout << target;
    std::cout << " with ";
    std::cout <<  _Attacks[temp];
    std::cout << " , causing 25 Energy points. Current EP is ";
    std::cout << this->_Energy_points;
    std::cout << std::endl;
    return ;
}
