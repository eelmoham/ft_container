
#include <iostream>
#include <vector>
#include "vector.hpp"
int main()
{
    {
        std::vector<std::string> v2;
        
        v2.push_back("1");
        v2.push_back("2");
        std::vector<std::string>::reverse_iterator rv(v2.end());
        std::cout << *rv << std::endl;
    }
    {
        // system("leaks a.out");
    }
}

