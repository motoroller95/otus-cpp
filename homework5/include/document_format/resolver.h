#pragma once

#include "document_format/png.h"
#include "document_format/jpeg.h"
#include <cstdlib>

namespace DocumentFormat
{
  struct Resolver
  {
    static std::shared_ptr<DocumentFormat::IFormat> call(const std::string &filenames)
    {
      if (rand() & 1)
        return std::make_shared<DocumentFormat::PNG>();
      else
        return std::make_shared<DocumentFormat::JPEG>();
    }
  };
}
