#include "ip_addr/ip_addr.h"
#include <algorithm>
#include <ostream>

namespace IPFilter::IPAddr
{
IPAddr::IPAddr(
  const std::array<uint8_t, 4> &_octets,
  const std::string &_str
  ) : octets(_octets), str(_str)
{}

bool IPAddr::operator==(const IPAddr &other) const
{
  return octets == other.octets;
}

bool IPAddr::operator>(const IPAddr &other) const
{
  return std::lexicographical_compare(
    std::begin(octets),
    std::end(octets),
    std::begin(other.octets),
    std::end(other.octets),
    [](auto lhs, auto rhs) { return lhs > rhs; }
  );
}

const OctetsContainer& IPAddr::getOctets() const
{
  return octets;
}

std::ostream &operator<<(std::ostream &out, const IPFilter::IPAddr::IPAddr &ip)
{
  out << ip.str;

  return out;
}
} // namespace IPFilter::IPAddr

