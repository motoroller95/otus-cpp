#include "filters.h"
#include <gtest/gtest.h>

using namespace IPFilter;

const std::vector<IPAddr::IPAddr> input {
  {{127, 0, 0, 1}, "127.0.0.1"},
  {{10, 34, 54, 2}, "10.34.54.2"},
  {{15, 35, 34, 0}, "15.35.0.0"},
  {{15, 45, 0, 25}, "15.45.0.25"},
  {{0, 127, 45, 32}, "0.127.45.32"},
  {{255, 255, 255, 0}, "255.255.255.0"}
};

TEST(Filters, FilterFirst)
{
  std::vector<IPAddr::IPAddr> result{
    {{15, 35, 34, 0}, "15.35.0.0"},
    {{15, 45, 0, 25}, "15.45.0.25"},
  };

  EXPECT_EQ(filter(input, 15), result);
}

TEST(Filters, FilterTwo)
{
  std::vector<IPAddr::IPAddr> result{
    {{15, 45, 0, 25}, "15.45.0.25"},
  };

  EXPECT_EQ(filter(input, 15, 45), result);
}

TEST(Filters, FilterAny)
{
  std::vector<IPAddr::IPAddr> result{
    {{127, 0, 0, 1}, "127.0.0.1"},
    {{15, 35, 34, 0}, "15.35.0.0"},
    {{15, 45, 0, 25}, "15.45.0.25"},
    {{0, 127, 45, 32}, "0.127.45.32"},
    {{255, 255, 255, 0}, "255.255.255.0"}
  };

  EXPECT_EQ(filter_any(input, 0), result);
}
