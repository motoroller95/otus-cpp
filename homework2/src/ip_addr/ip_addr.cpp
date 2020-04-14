#include "ip_addr/ip_addr.h"

namespace IPFilter::IPAddr
{
IPAddr::IPAddr(
  const std::array<uint8_t, 4> &_octets,
  const std::string &_str
  ) : octets(_octets), str(_str)
{}
} // namespace IPFilter::IPAddr

// std::ostream &operator<<(std::ostream &out, const IPFilter::IPAddr::IPAddr &ip)
// {
//   out << ip.str;

//   return out;
// }
