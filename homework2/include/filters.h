#pragma once

#include "ip_addr/ip_addr.h"
#include <vector>

namespace IPFilter
{
std::vector<IPAddr::IPAddr> filter(const std::vector<IPAddr::IPAddr> &, uint8_t);
std::vector<IPAddr::IPAddr> filter(const std::vector<IPAddr::IPAddr> &, uint8_t, uint8_t);
std::vector<IPAddr::IPAddr> filter_any(const std::vector<IPAddr::IPAddr> &, uint8_t);
} // namespace IPFilter
