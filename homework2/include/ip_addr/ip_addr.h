#pragma once

#include <string>
#include <exception>
#include <array>

namespace IPFilter::IPAddr
{
  class IPAddr
  {
    std::array<uint8_t, 4> octets;
    std::string str;
  public:
    IPAddr(const std::array<uint8_t, 4> &, const std::string &);

    friend std::ostream &operator<<(std::ostream &, const ::IPFilter::IPAddr::IPAddr &);
  };
} // namespace IPFilter
