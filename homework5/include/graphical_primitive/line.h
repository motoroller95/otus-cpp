#pragma once

#include "graphical_primitive/iprimitive.h"

namespace GraphicalPrimitives {
  struct Line : public IPrimitive
  {
    virtual const char* name() const override { return "Line"; }
  };
};
