#include "reader.h"
#include <gtest/gtest.h>

using namespace IPFilter;

TEST(Reader, ValidInput)
{
  auto input = std::istringstream{
    "127.0.0.1\ta\tb\n"
    "192.168.0.100\tc\td"
  };

  auto result = getIPs(input);

  ASSERT_EQ(result.size(), 2UL);
}

TEST(Reader, InvalidFormat)
{
  auto input = std::istringstream{"127.0.0.1 a b"};

  testing::internal::CaptureStderr();
  auto result = getIPs(input);

  ASSERT_STREQ("Line 1: Invalid input format\n", testing::internal::GetCapturedStderr().c_str());
}

TEST(Reader, InvalidIp)
{
  testing::internal::CaptureStderr();

  auto input = std::istringstream{
    "127.0.0.1\ta\tb\n"
    "192.1asdf68.0.100\tc\td"
  };

  auto result = getIPs(input);

  ASSERT_STREQ("Line 2: Invalid IP address\n", testing::internal::GetCapturedStderr().c_str());
}
