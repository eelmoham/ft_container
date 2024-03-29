
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
		v2.push_back(2);
		v2.push_back(2);
		v2.push_back(2);
		
		
		v.assign(v2.begin() + 1, v2.end());
		v.assign(6, 0);

		// v.reserve(6);

		for (size_t i = 0;i < v.size();i++)
			std::cout<<"v : "<<v[i]<<std::endl;
		// for (size_t i = 0;i < v2.size();i++)
		//     std::cout<<"v2 : "<<v2[i]<<std::endl;
		// std::cout << v.max_size() << "  " << v2.max_size()<<std::endl;
		std::cout <<"size"<< v.size() << "  " << v.size()<<std::endl;
		std::cout <<"cap" <<v.capacity() << "  " << v.capacity()<<std::endl;
	}
	{
		// system("leaks vec");
	}
}

template < class Key,  class T, class Compare = less<Key>,  class Alloc = allocator<pair<const Key,T> > > class map;