#include <iostream>
#include <vector>
int main()
{
    std::vector<int> a(200);
    for (int i = 0 ; i < 300; i++)
        a.push_back(200);
    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;

    std::cout<< "****************" << std::endl;
    std::vector<int> c(10, 10);
    for (int i = 0 ; i < 10; i++)
        std::cout << c[i] << std::endl;
    
    std::cout<< "****************" << std::endl;
    std::vector<int> f;

    try
    {
        // std::cout << f.at(10) << std::endl;
        // std::cout << f.front() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}