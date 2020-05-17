#include "print_ip.h"
#include <list>
#include <vector>
#include <gtest/gtest.h>

TEST(printIp, unsignedChar)
{
  testing::internal::CaptureStdout();

  unsigned char input = 127;
  printIp(input);

  ASSERT_STREQ(
    "127", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, signedChar)
{
  testing::internal::CaptureStdout();

  char input = -2;
  printIp(input);

  ASSERT_STREQ(
    "254", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, short)
{
  testing::internal::CaptureStdout();

  short input = 0xFF20;
  printIp(input);

  ASSERT_STREQ(
    "255.32",
    testing::internal::GetCapturedStdout().c_str() 
  );
}

TEST(printIp, int)
{
  testing::internal::CaptureStdout();

  int input = 2130706433;
  printIp(input);

  ASSERT_STREQ(
    "127.0.0.1", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, long)
{
  testing::internal::CaptureStdout();

  long input = 8875824491850138409;
  printIp(input);

  ASSERT_STREQ(
    "123.45.67.89.101.112.131.41", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, string)
{
  testing::internal::CaptureStdout();

  printIp(std::string("127.255.13.53"));

  ASSERT_STREQ(
    "127.255.13.53", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, vector4octets)
{
  testing::internal::CaptureStdout();

  printIp(std::vector{255, 244, 233, 211});

  ASSERT_STREQ(
    "255.244.233.211", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, emtpyVector)
{
  testing::internal::CaptureStdout();

  printIp(std::vector<int>());

  ASSERT_STREQ(
    "", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, emtpy1octet)
{
  testing::internal::CaptureStdout();

  printIp(std::vector{245});

  ASSERT_STREQ(
    "245", 
    testing::internal::GetCapturedStdout().c_str()
  );
}

TEST(printIp, list)
{
  testing::internal::CaptureStdout();

  printIp(std::list{1, 2, 3, 4, 5, 6, 7, 8});

  ASSERT_STREQ(
    "1.2.3.4.5.6.7.8", 
    testing::internal::GetCapturedStdout().c_str()
  );
}
