
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
        std::cout << std::endl;

        v2.resize(8, "c"); // adds 3 elements to the vector with value -1

        std::cout << "Vector vv after resize: ";
        for (size_t i = 0; i < v2.size(); i++)
        {
            std::cout << v2[i] << " ";
        }
        std::cout << std::endl;
    }
    {
        // system("leaks a.out");
    }
}

// Vector v before resize: 1 2 3 4 5
// Vector v after resize: 1 2 3
// Vector vv before resize: 1 2 3 4 5
// Vector vv after resize: 1 2 3 4 5 -1 -1 -1
