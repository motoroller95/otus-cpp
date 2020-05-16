#include "print_ip.h"
#include <list>
#include <vector>
#include <gtest/gtest.h>

TEST(printIp, unsignedChar)
{
  std::stringstream out;

  unsigned char input = 127;
  printIp(input, out);

  ASSERT_EQ(
    "127", 
    out.str()
  );
}

TEST(printIp, signedChar)
{
  std::stringstream out;

  char input = -2;
  printIp(input, out);

  ASSERT_EQ(
    "254", 
    out.str()
  );
}

TEST(printIp, short)
{
  std::stringstream out;

  short input = 0xFF20;
  printIp(input, out);

  ASSERT_EQ(
    "255.32",
    out.str()
  );
}

TEST(printIp, int)
{
  std::stringstream out;

  int input = 2130706433;
  printIp(input, out);

  ASSERT_EQ(
    "127.0.0.1", 
    out.str()
  );
}

TEST(printIp, long)
{
  std::stringstream out;

  long input = 8875824491850138409;
  printIp(input, out);

  ASSERT_EQ(
    "123.45.67.89.101.112.131.41", 
    out.str()
  );
}

TEST(printIp, string)
{
  std::stringstream out;

  printIp(std::string("127.255.13.53"), out);

  ASSERT_EQ(
    "127.255.13.53", 
    out.str()
  );
}

TEST(printIp, vector4octets)
{
  std::stringstream out;

  printIp(std::vector{255, 244, 233, 211}, out);

  ASSERT_EQ(
    "255.244.233.211", 
    out.str()
  );
}

TEST(printIp, emtpyVector)
{
  std::stringstream out;

  printIp(std::vector<int>(), out);

  ASSERT_EQ(
    "", 
    out.str()
  );
}

TEST(printIp, emtpy1octet)
{
  std::stringstream out;

  printIp(std::vector{245}, out);

  ASSERT_EQ(
    "245", 
    out.str()
  );
}

TEST(printIp, list)
{
  std::stringstream out;

  printIp(std::list{1, 2, 3, 4, 5, 6, 7, 8}, out);

  ASSERT_EQ(
    "1.2.3.4.5.6.7.8", 
    out.str()
  );
}
