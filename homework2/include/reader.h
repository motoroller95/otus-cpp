#pragma once

#include "ip_addr/ip_addr.h"
#include <vector>
#include <iostream>
#include <string>

namespace IPFilter
{
  std::vector<IPAddr::IPAddr> getIPs(std::istream&);
} // namespace IPFilter
