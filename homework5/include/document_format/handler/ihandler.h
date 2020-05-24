#pragma once

#include "document.h"
#include <iostream>

namespace DocumentFormat::Handler
{
  struct IHandler
  {
    virtual void export_document(const std::shared_ptr<Document> document, const std::string &filename) = 0;
    virtual void import_document(std::shared_ptr<Document> document, const std::string &filename) = 0;
  };
}
