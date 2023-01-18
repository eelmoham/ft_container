#include <iostream>
#include <vector>

void d()
{
    try
    {
        // Vector<int> v2(5, 1000);
        std::vector<int> v(5);
        int i = 0;
        for (i = 0; i < 5; i++)
            v[i] = i;
        std::cout << v.capacity()<< std::endl;
        v.reserve(100);
        v[5] = 1000; 
        v[6] = 1000; 
        for (int j = 0; j < v.capacity(); j++)
            std::cout << v[j] << std::endl;
        std::cout << v.capacity()<< std::endl;
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