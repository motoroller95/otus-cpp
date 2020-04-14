#include <iostream>
#include "ip_filter.h"

int main (int, char **)
{
  try
  {
    IPFilter::run(std::cin, std::cout);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
