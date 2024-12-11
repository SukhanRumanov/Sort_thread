#include "help_func.hpp"

void generate(std::vector<int>& vec, unsigned long count)
{
    vec.clear();
    std::srand(std::time(nullptr));
    for (int i = 0; i < count; i++)
    {
        vec.push_back(std::rand() % count);
    }
}

void print_vecs(std::vector<int>& vec)
{
    for(int i:vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
