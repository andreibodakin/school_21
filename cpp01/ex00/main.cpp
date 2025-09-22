#include "Pony.hpp"

void    ponyOnTheHeap()
{
    Pony    *heap = new Pony;

    heap->setName("Heap");
    std::cout << "Pony name: " << heap->getName() << std::endl;
    heap->setColor("White");
    std::cout << "Pony color: " << heap->getColor() << std::endl;
    heap->setBirthday("25.01.2020");
    std::cout << "Pony birthday: " << heap->getBirthday() << std::endl;
    heap->setWeight("22 killograms");
    std::cout << "Pony weight: " << heap->getWeight() << std::endl;
    std::cout << std::endl;

    delete heap;

    return ;
}

void    ponyOnTheStack()
{
    Pony    stack;

    stack.setName("Stack");
    std::cout << "Pony name: " << stack.getName() << std::endl;
    stack.setColor("Brown");
    std::cout << "Pony color: " << stack.getColor() << std::endl;
    stack.setBirthday("26.01.2020");
    std::cout << "Pony birthday: " << stack.getBirthday() << std::endl;
    stack.setWeight("25 killograms");
    std::cout << "Pony weight: " << stack.getWeight() << std::endl;
    std::cout << std::endl;

    return ;
}

int main(void)
{
    std::cout << std::endl;
    ponyOnTheHeap();
    std::cout << std::endl;
    ponyOnTheStack();
    std::cout << std::endl;

    return (0);
}
