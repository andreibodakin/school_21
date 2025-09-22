#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    AMateria* tmp;
    AMateria* tmp2;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);

    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "ice XP: " << tmp->getXP() << std::endl;
    std::cout << "cure XP: " << tmp2->getXP() << std::endl;

    me->use(0, *bob);
	me->use(1, *bob);
    std::cout << "ice XP: " << tmp->getXP() << std::endl;
    std::cout << "cure XP: " << tmp2->getXP() << std::endl;

    me->use(0, *bob);
	me->use(1, *bob);
    std::cout << "ice XP: " << tmp->getXP() << std::endl;
    std::cout << "cure XP: " << tmp2->getXP() << std::endl;

    me->use(1, *bob);
	me->use(1, *bob);
    std::cout << "ice XP: " << tmp->getXP() << std::endl;
    std::cout << "cure XP: " << tmp2->getXP() << std::endl;

    me->use(1, *bob);
	me->use(0, *bob);
    std::cout << "ice XP: " << tmp->getXP() << std::endl;
    std::cout << "cure XP: " << tmp2->getXP() << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}
