
#include "vector.hpp"

int s()
{
  vector<std::string> s;
  std::cout << "c " << s.capacity() << " s : "<< s.size()<<std::endl;
  s.push_back("mehdi");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  s.push_back("mehdi2");
  for (size_t i = 0; i < s.size(); i++)
    std::cout <<"value : "<< s[i]<<std::endl;
  s.clear();
  s.push_back("***************");
  for (size_t i = 0; i < s.size(); i++)
    std::cout <<"value : "<< s[i]<<std::endl;
  std::cout << "c " << s.capacity() << " s : "<< s.size()<<std::endl;
  return 0;
}

int main ()
{
  {s();
  }
  {
    system("leaks a.out");
  }
  return 0;
}