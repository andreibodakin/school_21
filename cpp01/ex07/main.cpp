#include "replace.hpp"

//./replace "dream.txt" "Sing with me" "Code with me"
//diff "dream.txt" "dream.txt.replace"

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string new_name;
    std::string read;
    int n = 0;

    if (ac != 4)
        std::cout << "Wrong arguments number!" << std::endl;
    else
    {
        new_name = av[1];
        new_name.append(".replace");
        s1 = av[2];
        s2 = av[3];


        std::ifstream infile(av[1]);
        if (infile.is_open())
        {
            std::ofstream outfile(new_name);

            while(getline(infile, read))
            {
                n = read.find(s1);
                if (n != -1)
                    read.replace(n, s1.length(), s2);
                outfile << read << std::endl;
            }
        }
        else
            std::cout << "File error.." << std::endl;
    }
    return (0);
}
