#include "ip_filter.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace IPFilter;

auto input = std::istringstream{
  "127.0.0.1\ta\tb\n"
  "46.34.54.2\ta\tb\n"
  "46.70.0.0\ta\tb\n"
  "1.45.0.25\ta\tb\n"
  "0.127.46.32\ta\tb\n"
  "1.127.46.32\ta\tb\n"
  "255.255.255.46\ta\tb"
};

auto expected = std::string{
  "255.255.255.46\n"
  "127.0.0.1\n"
  "46.70.0.0\n"
  "46.34.54.2\n"
  "1.127.46.32\n"
  "1.45.0.25\n"
  "0.127.46.32\n"
  "1.127.46.32\n"
  "1.45.0.25\n"
  "46.70.0.0\n"
  "255.255.255.46\n"
  "46.70.0.0\n"
  "46.34.54.2\n"
  "1.127.46.32\n"
  "0.127.46.32\n"
};

TEST(IPFilter, run)
{
  std::stringstream outStream;

  run(input, outStream);

  auto output = outStream.str();

  ASSERT_EQ(output, expected);
}
