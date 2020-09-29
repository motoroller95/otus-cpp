#include <iostream>
#include <cstdlib>
#include "bulk_cmd_processor.h"

int main (int argc, char **argv)
{
  if (argc != 2) {
    std::cerr << "Usage: cmd <bulk size>\n";
    return -1;
  }

  unsigned int bulk_size = std::atoi(argv[1]);
  if (bulk_size == 0) {
    std::cerr << "Invalid bulk size. Must be greather than 0\n";
    return -1;
  }

  bulk_cmd_processor::process(bulk_size);

  return 0;
}
