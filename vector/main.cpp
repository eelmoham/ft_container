#include "vector.hpp"
#include <iostream>
// #include <vector>
void s()
{
    ft::vector<std::string> v(5, "5");
    v.push_back("5sfv");
    v.push_back("5sfv");
    v.push_back("5sfv");
    v.push_back("5sfv");
    v.push_back("5sfv");
    ft::vector<std::string>::VectorIterator iter = v.begin();
    v.insert(iter + 6, "**********");
    for(ft::vector<std::string>::VectorIterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << v.capacity() << "  " << v.size() << std::endl;
}

int main()
{
    {
        s();
    }
    {
        // system("leaks a.out");
    }
    return 0;
}
