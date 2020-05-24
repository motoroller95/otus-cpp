#pragma once

#include "document.h"
#include "document_format/handler/ihandler.h"
#include <iostream>

namespace DocumentFormat::Handler
{
  struct JPEG : IHandler
  {
    virtual void export_document(const std::shared_ptr<Document> document, const std::string &filename) override {
      std::cout << "- Exporint document to '" << filename << "' as JPEG\n";

      // file.write(...)
    }

    virtual void import_document(std::shared_ptr<Document> document, const std::string &filename) override {
      std::cout << "- Importing '" << filename << "' as JPEG\n";

      // document->add_primitive(...)
    }
  };
}
