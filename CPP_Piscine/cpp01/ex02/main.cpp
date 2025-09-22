#include "Zombie.hpp"
#include "ZombieEvent.hpp"

const std::string Names[10] = 
{
    "Mathias", "Dorian", "Tyreese", "Wade", "Suleman", "Safah", "Huma", "Firat", "Spencer", "Hayley"
};

const std::string Types[10] = 
{
    "Moon", "Merritt", "Wharton", "Price", "Holman", "Mcdonald", "Parsons", "Adkins", "Pike", "Sharp"
};

std::string randomChump(void)
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

    Zombie  Peer(randomChump(), randomType());
    Peer.announce();

    ZombieEvent Bocal;
    Bocal.setZombieType(randomType());
    Zombie *ADM = Bocal.newZombie(randomChump());
    ADM->announce();
    delete ADM;

    return (0);
}