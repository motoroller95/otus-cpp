#pragma once

#include "document_format/iformat.h"
#include "document_format/handler/png.h"

namespace DocumentFormat
{
  struct PNG : IFormat
  {
    virtual std::shared_ptr<DocumentFormat::Handler::IHandler> handler() override {
      return std::make_shared<DocumentFormat::Handler::PNG>();
    };
  };
}
