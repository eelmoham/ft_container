#include "vector.hpp"
#include <vector>
void s()
{
    ft::vector<std::string> v(5);
    v.push_back("5");
    v.push_back("5");
    std::cout <<"done\n"<< std::endl;
    for (iterator<std::string> it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << v.capacity() << "  " << v.size() << std::endl;
}
int main() {
    {
        s();
    }
    {
        system("leaks a.out");
    }
    return 0;
}
