#pragma once
#include <iostream>

namespace bulk_cmd_processor {
  void process(unsigned int bulk_size);
  void process_bulk(const std::vector<std::string>&);
  void process_custom_bulk();
  void process_with_clear(std::vector<std::string>&);
};
