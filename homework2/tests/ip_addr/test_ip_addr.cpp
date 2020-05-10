#include "ip_addr/ip_addr.h"
#include <ostream>
#include <gtest/gtest.h>

using namespace IPFilter::IPAddr;

TEST(IPAddr, EqualOperator)
{
  auto ip1 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  auto ip2 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  ASSERT_EQ(ip1, ip2);

  ip1 = IPAddr{{0, 0, 0, 1}, "0.0.0.0"};
  ip2 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  ASSERT_FALSE(ip1 == ip2);
}

TEST(IPAddr, LessOperator)
{
  auto ip1 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  auto ip2 = IPAddr{{0, 2, 0, 0}, "0.0.0.0"};
  ASSERT_FALSE(ip1 > ip2);

  ip1 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  ip2 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  ASSERT_FALSE(ip1 > ip2);

  ip1 = IPAddr{{0, 0, 0, 1}, "0.0.0.0"};
  ip2 = IPAddr{{0, 0, 0, 0}, "0.0.0.0"};
  ASSERT_TRUE(ip1 > ip2);
}

TEST(IPAddr, Output)
{
  testing::internal::CaptureStdout();

  std::cout << IPAddr {{0, 0, 0, 0}, "0.1.0.0"};

  ASSERT_STREQ("0.1.0.0", testing::internal::GetCapturedStdout().c_str());
}

TEST(IPAddr, getOctets)
{
  auto ip1 = IPAddr{{1, 2, 3, 127}, "1.2.3.127"};
  OctetsContainer expected{1, 2, 3, 127};

  ASSERT_EQ(ip1.getOctets(), expected);
}
