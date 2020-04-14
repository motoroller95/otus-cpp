#pragma once

#include "ip_addr/ip_addr.h"

namespace IPFilter::IPAddr
{
  class InvalidIP : public std::exception
  {
    const char *what() const noexcept override { return "Invalid IP address"; }
  };

  namespace Builder
  {
    IPAddr build(const std::string &);
  } // namespace Builder
} // namespace IPFilter::IPAddr
