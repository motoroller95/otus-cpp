#include "reader.h"
#include "ip_addr/builder.h"
#include <limits>
#include <boost/algorithm/string.hpp>

namespace IPFilter
{
void printError(uint32_t, const char *);

std::vector<IPAddr::IPAddr> getIPs(std::istream &input)
{
  uint32_t lineNumber = 0;
  std::vector<IPAddr::IPAddr> result;
  std::string line;

  while (getline(input, line))
  {
    lineNumber++;
    if (lineNumber == std::numeric_limits<uint32_t>::max())
    {
      throw "Too much data";
    }

    std::vector<std::string> lineParts;
    boost::split(lineParts, line, boost::is_any_of("\t"));
    if (lineParts.size() != 3)
    {
      printError(lineNumber, "Invalid input format");
      continue;
    }

    try
    {
      result.push_back(IPAddr::Builder::build(lineParts[0]));
    }
    catch (const IPAddr::InvalidIP &error)
    {
      printError(lineNumber, error.what());
    }
  }

  return result;
}

void printError(uint32_t line, const char *message)
{
  std::cerr << "Line " << line << ": " << message << std::endl;
}
} // namespace IPFilter
