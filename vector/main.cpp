
#include <iostream>
#include <vector>
#include "vector.hpp"
int main()
{
    {
        ft::vector<std::string> v2;
        
        v2.push_back("1");
        v2.push_back("2");
        v2.push_back("3");
        v2.push_back("4");
        v2.push_back("5");
        std::cout << "Vector vv before resize: ";
        for (size_t i = 0; i < v2.size(); i++)
        {
            std::cout << v2[i] << " ";
        }
        std::cout <<'\n'<<v2.size()<< std::endl;
        ft::vector<std::string>::iterator x = v2.erase(v2.begin() + 4);
        std::cout << "done : " <<*x << std::endl;
        std::cout << "Vector vv after resize: ";
        for (size_t i = 0; i < v2.size(); i++)
        {
            std::cout << v2[i] << " ";
        }
        std::cout <<'\n'<<v2.size()<< std::endl;
    }
    {
        // system("leaks a.out");
    }
}

