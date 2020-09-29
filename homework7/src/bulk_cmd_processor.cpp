#include <string>
#include <vector>
#include "bulk_cmd_processor.h"

void bulk_cmd_processor::process(unsigned int bulk_size) {
  std::string cmd;
  std::vector<std::string> commands;

  while (std::getline(std::cin, cmd)) {
    if (cmd == "{") {
      process_with_clear(commands);
      process_custom_bulk();
      continue;
    }

    commands.emplace_back(cmd);
    if (commands.size() == bulk_size)
      process_with_clear(commands);
  }

  process_bulk(commands);
}

void bulk_cmd_processor::process_custom_bulk() {
  std::string cmd;
  std::vector<std::string> commands;
  unsigned int nesting = 1;

  while (std::getline(std::cin, cmd)) {
    if (cmd == "{") {
      nesting++;
      continue;
    }

    if (cmd == "}") {
      nesting--;

      if (nesting == 0)
        break;

      continue;
    }

    commands.emplace_back(cmd);
  }

  process_bulk(commands);
}

void bulk_cmd_processor::process_bulk(const std::vector<std::string> &bulk) {
  if (bulk.size() > 0)
    std::cout << "Processing: ";

  for (auto& cmd : bulk) 
    std::cout << cmd << " ";

  if (bulk.size() > 0)
    std::cout << "\n";
}

void bulk_cmd_processor::process_with_clear(std::vector<std::string> &commands) {
  process_bulk(commands);
  commands.clear();
}