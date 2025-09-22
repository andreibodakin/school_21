#include "Zombie.hpp"
#include "ZombieHorde.hpp"

const std::string Names[10] = 
{
    "Mathias", "Dorian", "Tyreese", "Wade", "Suleman", "Safah", "Huma", "Firat", "Spencer", "Hayley"
};

const std::string Types[10] = 
{
    "Moon", "Merritt", "Wharton", "Price", "Holman", "Mcdonald", "Parsons", "Adkins", "Pike", "Sharp"
};

std::string randomName(void)
{
    std::string result;
    int temp;
    
    temp = rand() % 10;
    result = Names[temp];

    return (result);
}

std::string randomType(void)
{
    std::string result;
    int temp;

    temp = rand() % 10;
    result = Types[temp];

    return (result);
}

int     main(void)
{
    srand(time(NULL));

    Zombie  Peer;
    Peer.setName(randomName());
    Peer.setType(randomType());
    Peer.announce();

    ZombieHorde Bocal(5);
    Bocal.announce();

    return (0);
}
