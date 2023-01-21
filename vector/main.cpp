// #include "vector.hpp"

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(5,42);
    std::cout << *v.begin() << std::endl;
    // for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    //     std::cout << *it << std::endl;
    return 0;
}