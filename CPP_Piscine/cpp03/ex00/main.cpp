#include "FragTrap.hpp"

int main(void)
{
    FragTrap robot("Robot");
    FragTrap robocop(robot);
    FragTrap shoebox("Shoebox");

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
    return (0);
}
