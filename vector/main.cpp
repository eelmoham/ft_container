
#include <iostream>
#include <vector>
#include "vector.hpp"
// #include <stack>
int main()
{
    {
        ft::vector<std::string> v2;
        
        v2.push_back("1");
        v2.push_back("2");
        ft::vector<std::string>::reverse_iterator rv(v2.end());
        std::cout << *rv << std::endl;

        std::cout << "*********\n";
        std::vector<std::string> v;
        v.push_back("mehdi");
        v.push_back("mehdi1");
        v.push_back("mehdi2");
        v.push_back("mehdi3");
        v.push_back("mehdi4");
        v.push_back("mehdi5");
        v.push_back("mehdi5");
        v2.assign(v.begin(), v.end());

        for (size_t i = 0; i < v2.size();i++)
            std::cout << "*> " <<v2[i] << std::endl;

        std::cout << v2.size() << "  " << v2.capacity() << "\n";

    }
    {
        // typedef typename std::stack<T>::container_type::iterator it;
        // system("leaks a.out");
    }
}

