#include "vector.hpp"

int main() {
    ft::vector<int> vec(5, 42);
    for (iterator<int> it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
