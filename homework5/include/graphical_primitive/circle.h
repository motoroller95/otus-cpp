#pragma once

#include "graphical_primitive/iprimitive.h"

namespace GraphicalPrimitives {
  struct Circle : public IPrimitive
  {
    virtual const char* name() const override { return "Circle"; }
  };
};
