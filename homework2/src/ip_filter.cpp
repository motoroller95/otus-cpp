#include "ip_filter.h"
#include "ip_addr/builder.h"
#include "reader.h"
#include "filters.h"
#include <algorithm>

namespace IPFilter
{
void output(const std::vector<IPAddr::IPAddr> &, std::ostream &);

void run(std::istream &input, std::ostream &out)
{
  auto ips = getIPs(input);

  std::sort(std::begin(ips), std::end(ips), std::greater<IPAddr::IPAddr>());
  output(ips, out);

  output(filter(ips, 1), out);
  output(filter(ips, 46, 70), out);
  output(filter_any(ips, 46), out);
}

void output(const std::vector<IPAddr::IPAddr> &ips, std::ostream &out)
{
  for (auto &ip : ips)
  {
    out << ip << std::endl;
  }
}
} // namespace IPFilter
