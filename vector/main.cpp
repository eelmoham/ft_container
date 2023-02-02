
#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
    {
        std::vector<int> v;
        ft::vector<int> v2;

        std::cout << v.max_size() << "  " << v2.max_size()<<std::endl;
    }
    {
        // system("leaks vec");
    }
}
