#pragma once
#include "ip_addr/ip_addr.h"
#include <iostream>
#include <vector>

namespace IPFilter
{
  void run(std::istream &, std::ostream &);
  std::vector<IPAddr::IPAddr> getIPs(std::istream &);
}; // namespace IPFilter
