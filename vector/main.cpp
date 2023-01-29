
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
        for (ft::vector<std::string>::iterator rit = v2.begin(); rit != v2.end(); ++rit)
        {
            std::cout << *rit << std::endl;
        }
    }
    {
        // system("leaks a.out");
    }
}

