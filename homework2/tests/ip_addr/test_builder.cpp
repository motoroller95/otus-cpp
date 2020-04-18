#include "ip_addr/builder.h"
#include <gtest/gtest.h>

using namespace IPFilter::IPAddr::Builder;

TEST(Builder, ValidInput)
{
  auto ip = IPFilter::IPAddr::IPAddr{{192, 168, 0, 100}, "192.168.0.100"};

  ASSERT_EQ(build("192.168.0.100"), ip);
}

TEST(Builder, InvalidInput)
{
  ASSERT_THROW(build("192.0.100"), IPFilter::IPAddr::InvalidIP);
}
