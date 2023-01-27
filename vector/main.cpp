#include "vector.hpp"
// #include <iostream>
// #include <vector>
// #include "vector.hpp"
// void s()
// {
//     const ft::vector<std::string> sourceVector(3, "*");
//     // sourceVector.push_back("4");
//     // sourceVector.push_back("5");
//     // sourceVector.push_back("6");
//     ft::vector<std::string> myVector;
//     myVector.push_back("1");
//     myVector.push_back("2");
//     myVector.push_back("3");
//     myVector.push_back("3");
//     myVector.push_back("3");
//     myVector.push_back("3");
//     myVector.push_back("3");
//     ft::vector<std::string>::iterator it = myVector.begin() + myVector.size();

//     myVector.insert(it, sourceVector.begin(), sourceVector.end());
//     // myVector.pop_back();
//     for (size_t i = 0; i < myVector.size(); i++)
//     {
//         std::cout << myVector[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << myVector.capacity() << "  " << myVector.size() << std::endl;
// }

int main()
{
    {
        ft::vector<std::string> v;
        v.push_back("1");
        v.push_back("0");
        v.push_back("20");
        v.push_back("4");
        v.push_back("5");
        ft::vector<std::string>::iterator it = v.begin() + 2;

        std::cout << "Vector before erase: ";
        for (size_t i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

        v.erase(it); // removes the element at position 2 (value 3)

        std::cout << "Vector after erase: ";
        for (size_t i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

        return 0;
    }
    {
        // system("leaks a.out");
    }
}
