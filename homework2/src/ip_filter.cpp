#include "ip_filter.h"

using namespace std;

namespace IPFilter
{
void run(istream &input, ostream &output)
{
  auto ips = getIPs(input);
  output << "Hello world\n";
}

vector<IPAddr::IPAddr> getIPs(istream &input)
{
  // uint32_t i = 1;
  vector<IPAddr::IPAddr> result;
  string line;

  while (getline(input, line))
  {
    vector<string> lineParts;
  }

  return result;
}
} // namespace IPFilter
