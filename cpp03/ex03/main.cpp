#include "NinjaTrap.hpp"

int main(void)
{
    FragTrap robot("Robot");
    FragTrap robocop(robot);
    FragTrap shoebox("Shoebox");
    ScavTrap terminator("Terminator");
    NinjaTrap ninja("Ninja");

    srand(time(NULL));

    robot.rangedAttack("Cupcake");
    robot.meleeAttack("Mini-muffin");
    robot.takeDamage(50);
    robot.beRepaired(15);
    robot.vaulthunter_dot_exe("one");
    robot.vaulthunter_dot_exe("two");
    robot.vaulthunter_dot_exe("three");
    robot.vaulthunter_dot_exe("four");
    robot.vaulthunter_dot_exe("five");
    terminator.challengeNewcomer("one");
    terminator.challengeNewcomer("two");

    std::cout << std::endl;
    ninja.ninjaShoebox(robot);
    ninja.ninjaShoebox(robocop);
    ninja.ninjaShoebox(terminator);
    ninja.ninjaShoebox(ninja);
    std::cout << std::endl;
    return (0);
}
