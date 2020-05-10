#include "ip_addr/validator.h"
#include <gtest/gtest.h>

using namespace IPFilter::IPAddr::Validator;

TEST(isValid, ValidInput)
{
  auto input = std::vector<std::string>{"127", "0", "0", "1"};
  ASSERT_TRUE(isValid(input));
}

TEST(isValid, NotOnlyDigits)
{
  auto input = std::vector<std::string>{"127asdf", "0", "0", "1"};
  ASSERT_FALSE(isValid(input));
}

TEST(isValid, NegativeOctet)
{
  auto input = std::vector<std::string>{"-127", "0", "0", "1"};
  ASSERT_FALSE(isValid(input));
}

TEST(isValid, OctetGreaterThan255)
{
  auto input = std::vector<std::string>{"256", "0", "0", "1"};
  ASSERT_FALSE(isValid(input));
}
