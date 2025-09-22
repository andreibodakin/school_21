#include <iostream>

#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#include "ft_containers.hpp"

int main()
{
    std::list<int> list_a;
    std::vector<int> vector_a;
    std::map<int, char> map_a;
    std::queue<int> queue_a;
    std::stack<int> stack_a;

    ft::list<int> list_b;
    ft::vector<int> vector_b;
    ft::map<int, char> map_b;
    ft::queue<int> queue_b;
    ft::stack<int> stack_b;

    for (int i = 0; i < 21; ++i)
    {
        list_a.push_back(i);
        vector_a.push_back(i);
        map_a.insert(std::pair<int, char>(i, 'a'));
        queue_a.push(i);
        stack_a.push(i);

        list_b.push_back(i);
        vector_b.push_back(i);
        map_b.insert(std::pair<int, char>(i, 'a'));
        ;
        queue_b.push(i);
        stack_b.push(i);
    }

    std::cout << "\n STD and FT containers test" << std::endl;
    std::cout << std::endl;
    std::cout << "Sizes: " << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << "STD list: " << list_a.size() << std::endl;
    std::cout << "FT list: " << list_b.size() << std::endl;
    std::cout << "STD vector: " << vector_a.size() << std::endl;
    std::cout << "FT vector: " << vector_b.size() << std::endl;
    std::cout << "STD map: " << map_a.size() << std::endl;
    std::cout << "FT map: " << map_b.size() << std::endl;
    std::cout << "STD queue: " << queue_a.size() << std::endl;
    std::cout << "FT queue: " << queue_b.size() << std::endl;
    std::cout << "STD stack: " << stack_a.size() << std::endl;
    std::cout << "FT stack: " << stack_b.size() << std::endl;

    std::cout << std::endl;
    std::cout << "Values: " << std::endl;
    std::cout << "**************************" << std::endl;

    std::list<int>::iterator it_a = list_a.begin();
    ft::list<int>::iterator it_b = list_b.begin();

    std::cout << "STD list: ";
    for (; it_a != list_a.end(); it_a++)
        std::cout << *it_a << " ";
    std::cout << std::endl;
    std::cout << " FT list: ";
    for (; it_b != list_b.end(); it_b++)
        std::cout << *it_b << " ";
    std::cout << std::endl;

    std::vector<int>::iterator it_a1 = vector_a.begin();
    ft::vector<int>::iterator it_b1 = vector_b.begin();

    std::cout << "STD vector: ";
    for (; it_a1 != vector_a.end(); it_a1++)
        std::cout << *it_a1 << " ";
    std::cout << std::endl;
    std::cout << " FT vector: ";
    for (; it_b1 != vector_b.end(); it_b1++)
        std::cout << *it_b1 << " ";
    std::cout << std::endl;

    std::map<int, char>::iterator it_a2 = map_a.begin();
    ft::map<int, char>::iterator it_b2 = map_b.begin();

    std::cout << "STD map: ";
    for (; it_a2 != map_a.end(); it_a2++)
        std::cout << it_a2->first << " " << it_a2->second << "; ";
    std::cout << std::endl;
    std::cout << " FT map: ";
    for (; it_b2 != map_b.end(); it_b2++)
        std::cout << it_b2->first << " " << it_b2->second << "; ";
    ;
    std::cout << std::endl;

    std::cout << "STD queue: ";
    for (; queue_a.size(); queue_a.pop())
        std::cout << queue_a.front() << " ";
    std::cout << std::endl;
    std::cout << " FT queue: ";
    for (; queue_b.size(); queue_b.pop())
        std::cout << queue_b.front() << " ";
    std::cout << std::endl;

    std::cout << "STD stack: ";
    for (; stack_a.size(); stack_a.pop())
        std::cout << stack_a.top() << " ";
    std::cout << std::endl;
    std::cout << " FT stack: ";
    for (; stack_b.size(); stack_b.pop())
        std::cout << stack_b.top() << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test leaks and push any button." << std::endl;
    getchar();

    return 0;
}