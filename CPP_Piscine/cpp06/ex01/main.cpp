#include "Serialization.hpp"

void *serialize(void)
{
    std::string str = "Abcdefghijklmnopqrstuvwxyz";
    size_t str_size = str.size();
    char *address = new char[21];

    for (int i = 0; i < 8; i++)
        address[i] = str[rand() % str_size];
    
    std::cout << std::endl << "serialize: " << std::endl;

    address[7] = '\0';
    std::cout << "s1:\t" << address << std::endl;

    *(address + 8) = rand() % 100;

    for(int i = 0; i < 8; i++)
        address[i + 12] = str[rand() % str_size];

    address[20] = '\0';

    std::cout << "n:\t" << *reinterpret_cast<int*>(address + 8) << std::endl;
    std::cout << "s2:\t" << address + 12 << std::endl;
    std::cout << std::endl;

    return (reinterpret_cast<void *>(address));
}

Data *deserialize(void *address)
{
    Data *data = new Data;

    data->s1 = std::string(reinterpret_cast<char*>(address), 8);
    data->n = *(reinterpret_cast<int*>(static_cast<char *>(address) + 8));
    data->s2 = std::string(reinterpret_cast<char*>(address) + 12, 8);

    return (data);
}

int main()
{
    srand(time(NULL));

    void *address = serialize();
    Data *data = deserialize(address);

    std::cout << "deserialize: " << std::endl;

    std::cout << "s1:\t" << data->s1 << std::endl;
    std::cout << "n:\t" << data->n << std::endl;
    std::cout << "s2:\t" << data->s2 << std::endl;
    std::cout << std::endl;

    std::cout << "sizeof elements: " << sizeof(data->s1) + sizeof(data->n) +sizeof(data->s2) << std::endl;

    delete (char *)address;
    delete data;

    return (0);
}
