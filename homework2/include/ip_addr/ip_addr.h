#pragma once

#include <string>
#include <array>

namespace IPFilter::IPAddr
{
using OctetsContainer = std::array<uint8_t, 4>;

class IPAddr
{
  OctetsContainer octets;
  std::string str;

public:
  IPAddr() {}
  IPAddr(const OctetsContainer &, const std::string &);

  const OctetsContainer& getOctets() const;

  bool operator==(const IPAddr &) const;
  bool operator>(const IPAddr &) const;

  friend std::ostream &operator<<(std::ostream &, const IPAddr &);
  };
} // namespace IPFilter
