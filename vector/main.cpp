
#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
    {
        ft::vector<int> v;
        ft::vector<int> v2;
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        // v2.push_back(2);
        // v2.push_back(2);
        // v2.push_back(2);
        // v2.swap(v);
        v.assign(5,0);

        for (size_t i = 0;i < v.size();i++)
            std::cout<<"v : "<<v[i]<<std::endl;
        // for (size_t i = 0;i < v2.size();i++)
        //     std::cout<<"v2 : "<<v2[i]<<std::endl;
        // std::cout << v.max_size() << "  " << v2.max_size()<<std::endl;
        // std::cout <<"size"<< v.size() << "  " << v2.size()<<std::endl;
        // std::cout <<"cap" <<v.capacity() << "  " << v2.capacity()<<std::endl;
    }
    {
        // system("leaks vec");
    }
}
