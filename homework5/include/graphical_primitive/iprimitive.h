#pragma once

namespace GraphicalPrimitives {
  struct IPrimitive
  {
    virtual const char* name() const = 0;
  };
};
