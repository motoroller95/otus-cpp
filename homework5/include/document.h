#pragma once

#include "graphical_primitive/iprimitive.h"
#include "graphical_primitive/circle.h"
#include <iostream>
#include <vector>
#include <memory>

struct Document
{
  using graphical_primitive_t = std::shared_ptr<GraphicalPrimitives::IPrimitive>;

  Document() { std::cout << "- New empty document created\n"; }

  void add_primitive(graphical_primitive_t primitive) {
    std::cout << "- Drawing " << primitive->name() << std::endl;
  }

  void remove_primitive(graphical_primitive_t primitive) {
    std::cout << "- Erasing " << primitive->name() << std::endl;
  }

  graphical_primitive_t get_primitive_by_coordinate() {
    // Для примера просто возвращаю что-нибудь
    return std::make_shared<GraphicalPrimitives::Circle>();
  }
};
