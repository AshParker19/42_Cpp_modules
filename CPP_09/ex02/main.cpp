#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {   
        PmergeMe PM(ac, av);

        PM.generateSequence();
        PM.handleVector();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}