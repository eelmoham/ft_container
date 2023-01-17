
#include "vector.hpp"
#include <random>
int main()
{
    try
    {
        // Vector<int> v2(5, 1000);
        Vector<int> v(5);
        for (int i = 0; i < 5; i++)
            v[i] = i;
        
        v.back() = 100;

        for (int i = 0; i < 5; i++)
            std::cout << v.at(i) << std::endl;
        
        std::cout << v.back() << std::endl;
    }
    catch(...)
    {
        std::cout << "catch" << std::endl;
    }
    {
        // system("leaks a.out");
    }
}