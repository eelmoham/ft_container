
#include "vector.hpp"
void d()
{
    try
    {
        // Vector<int> v2(5, 1000);
        Vector<int> v(5);
        int i = 0;
        for (i = 0; i < 5; i++)
            v[i] = i;
        std::cout << v.size()<< std::endl;
        // v.reserve(10);
        v[5] = 1000; 
        for (int j = 0; j < 10; j++)
            std::cout << v[j] << std::endl;
        std::cout << v.size()<< std::endl;
    }
    catch(...)
    {
        std::cout << "catch" << std::endl;
    }
    {
        // system("leaks a.out");
    }
}
int main()
{
    {
        d();
    }
    {
        system("leaks a.out");
    }
}