#include <gtest/gtest.h>
#include "hello_world/hello_world.hpp"

TEST(test_version, version)
{
  ASSERT_STREQ(HelloWorld::message(), "Hello world");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
