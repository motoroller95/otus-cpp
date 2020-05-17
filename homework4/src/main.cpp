#include <iostream>
#include <vector>
#include <list>
#include "print_ip.h"

int main (int, char **)
{
  char a1 = -1;
  short a2 = 0;
  int a3 = 2130706433;
  long a4 = 8875824491850138409;
  auto a5 = std::vector<int>{1, 2, 3, 4};
  auto a6 = std::list<int>{255, 255, 255, 0};
  auto a7 = std::string("7.8.9.10");

  printIp(a1, std::cout);
  std::cout << std::endl;

  printIp(a2, std::cout);
  std::cout << std::endl;

  printIp(a3, std::cout);
  std::cout << std::endl;

  printIp(a4, std::cout);
  std::cout << std::endl;

  printIp(a7, std::cout);
  std::cout << std::endl;

  printIp(a5, std::cout);
  std::cout << std::endl;

  printIp(a6, std::cout);
  std::cout << std::endl;

  return 0;
}
