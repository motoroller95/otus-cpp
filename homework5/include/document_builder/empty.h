#pragma once

#include "document.h"
#include "document_builder/ibuilder.h"
#include "document_format/jpeg.h"
#include "document_format/png.h"
#include <iostream>
#include <cstdlib>

namespace DocumentBuilder
{
  struct Emtpy : IBuilder
  {
    virtual std::shared_ptr<Document> ducument() override {
      auto document = std::make_shared<Document>();
      std::cout << "- Document was built\n";

      return document;
    }

    virtual std::shared_ptr<DocumentFormat::IFormat> format() override {
      if (rand() & 1)
        return std::make_shared<DocumentFormat::PNG>();
      else
        return std::make_shared<DocumentFormat::JPEG>();
    }
  };
}
