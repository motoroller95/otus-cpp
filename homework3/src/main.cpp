#include "map_allocator.h"
#include <iostream>
#include <map>

template<typename T>
void fillMap(T &map)
{
  map[0] = 1;
  for (int i = 1; i < 10; i++)
    map[i] = i * map[i - 1];
}

template <typename T>
void printMap(const T &map)
{
  for (auto [key, value] : map)
    std::cout << "Factorial " << key << ": " << value << std::endl;
}

int main (int, char **)
{
  std::map<int, int> map1;
  fillMap(map1);
  printMap(map1);

  std::map<int, int, std::less<int>, MapAllocator<std::pair<const int, int>, 10>> map2;
  fillMap(map2);
  printMap(map2);

  return 0;
}
