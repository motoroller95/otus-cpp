#include "ip_addr/validator.h"
#include <cctype>
#include <algorithm>

namespace IPFilter::IPAddr::Validator
{
bool isValid(std::vector<std::string> &octets)
{
  return std::all_of(
      std::begin(octets),
      std::end(octets),
      [](auto octet) {
        return std::all_of(std::begin(octet), std::end(octet), std::isdigit) &&
               (std::stoi(octet) >= 0 && std::stoi(octet) <= 255);
      });
}
} // namespace IPFilter::IPAddr::Validator
