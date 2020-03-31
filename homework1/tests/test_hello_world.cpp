#include "hello_world.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(HelloWorld, print)
{
  testing::internal::CaptureStdout();
  HelloWorld::print();
  std::string output = testing::internal::GetCapturedStdout();

  ASSERT_STREQ("Hello world\n", output.c_str());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
