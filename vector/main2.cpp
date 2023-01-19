
#include "vector.hpp"
void d()
{
    try
    {
        // vector<int> v2(5, 1000);
        vector<std::string> v(5);
        int i = 0;
        for (i = 0; i < 5; i++)
            v[i] = "mehdi ";
        std::cout << v.size() << std::endl;
        v.reserve(2);
        for (int j = 0; j < v.size(); j++)
            std::cout << v[j] << std::endl;
        std::cout << v.size() << std::endl;
    }
    catch (...)
    {
        std::cout << "catch" << std::endl;
    }
    {
        system("leaks a.out");
    }
}
int main()
{
    d();
}