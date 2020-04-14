#include "filters.h"
#include <algorithm>

namespace IPFilter
{
std::vector<IPAddr::IPAddr> filter(const std::vector<IPAddr::IPAddr> &ips, uint8_t octet)
{
  std::vector<IPAddr::IPAddr> result{ips.size()};

  auto it = std::copy_if(
    std::begin(ips),
    std::end(ips),
    std::begin(result),
    [octet](auto ip) { return ip.getOctets()[0] == octet; }
  );
  result.resize(std::distance(std::begin(result), it));

  return result;
}

std::vector<IPAddr::IPAddr> filter(const std::vector<IPAddr::IPAddr> &ips, uint8_t octet1, uint8_t octet2)
{
  std::vector<IPAddr::IPAddr> result{ips.size()};

  auto it = std::copy_if(
    std::begin(ips),
    std::end(ips),
    std::begin(result),
    [octet1, octet2](auto ip) { return ip.getOctets()[0] == octet1 && ip.getOctets()[1] == octet2; }
  );
  result.resize(std::distance(std::begin(result), it));

  return result;
}

std::vector<IPAddr::IPAddr> filter_any(const std::vector<IPAddr::IPAddr> &ips, uint8_t octet)
{
  std::vector<IPAddr::IPAddr> result{ips.size()};

  auto it = std::copy_if(
    std::begin(ips),
    std::end(ips),
    std::begin(result),
    [octet](auto ip) {
      auto start = std::begin(ip.getOctets());
      auto end = std::end(ip.getOctets());

      return std::any_of(start, end, [octet](auto o) { return octet == o; });
  });
  result.resize(std::distance(std::begin(result), it));

  return result;
}
} // namespace IPFilter
