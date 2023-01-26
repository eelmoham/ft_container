// #include "vector.hpp"
// #include <iostream>
// #include <vector>
// void s()
// {
//     ft::vector<int> myVec;
//     myVec.push_back(1);
//     myVec.push_back(2);
//     myVec.push_back(3);
//     myVec.push_back(4);
//     ft::vector<int>::iterator it = myVec.begin() + 2;
//     it = myVec.insert(it, 5);
//     ++it;
//     ++it;
//     ++it;
//     std::cout << *it << std::endl;
//     for (ft::vector<int>::iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
//         std::cout << *iter << " ";
// }
#include "vector.hpp"
// #include <iostream>
// #include <vector>

int main()
{
    ft::vector<int> sourceVector;
    sourceVector.push_back(4);
    sourceVector.push_back(5);
    sourceVector.push_back(6);
    ft::vector<int> myVector ;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    ft::vector<int>::iterator it = myVector.begin() + myVector.size();

    myVector.insert(it, sourceVector.begin() + 1, sourceVector.end());

    for (size_t i = 0;i <  myVector.size();i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout<<std::endl;
    return 0;
}

