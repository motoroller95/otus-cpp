#pragma once

#include "graphical_primitive/iprimitive.h"

namespace GraphicalPrimitives {
  struct Rectangle : public IPrimitive
  {
    virtual const char* name() const override { return "Rectangle"; }
  };
};
