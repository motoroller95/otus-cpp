#include "ip_addr/builder.h"
#include "ip_addr/validator.h"
#include <vector>
#include <array>
#include <algorithm>
#include <boost/algorithm/string.hpp>

namespace IPFilter::IPAddr::Builder
{
IPAddr build(const std::string &ipAddress)
{
  std::vector<std::string> octets;
  boost::split(octets, ipAddress, boost::is_any_of("."));
  if (!IPFilter::IPAddr::Validator::isValid(octets))
  {
    throw IPFilter::IPAddr::InvalidIP();
  }

  OctetsContainer binaryOctets;
  std::transform(
    std::begin(octets),
    std::end(octets),
    std::begin(binaryOctets),
    [](auto octet) { return std::stoi(octet); }
  );

  return IPFilter::IPAddr::IPAddr(binaryOctets, ipAddress);
}
} // namespace IPFilter::IPAddr
