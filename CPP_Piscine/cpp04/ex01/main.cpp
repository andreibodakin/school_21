#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main(void)
{
Character* me = new Character("me");
std::cout << *me;
Enemy* b = new RadScorpion();
AWeapon* pr = new PlasmaRifle();
AWeapon* pf = new PowerFist();

Enemy* s = new SuperMutant();

me->equip(pr);
std::cout << *me;
me->equip(pf);
me->attack(b);
std::cout << *me;
me->recoverAP();
std::cout << *me;
me->equip(pr);
std::cout << *me;
me->attack(b);
std::cout << *me;
me->attack(b);
std::cout << *me;
std::cout << std::endl;
me->equip(pf);
std::cout << *me;
me->attack(s);
std::cout << *me;
std::cout << std::endl;
return 0;
}