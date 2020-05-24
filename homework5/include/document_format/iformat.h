#pragma once

#include "document_format/handler/ihandler.h"
#include <memory>

namespace DocumentFormat
{
  struct IFormat
  {
    virtual std::shared_ptr<DocumentFormat::Handler::IHandler> handler() = 0;
  };
}
