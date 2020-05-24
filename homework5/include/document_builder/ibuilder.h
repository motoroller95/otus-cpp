#pragma once

#include "document.h"
#include "document_format/jpeg.h"
#include "document_format/png.h"
#include <memory>
#include <iostream>

namespace DocumentBuilder
{
  struct IBuilder
  {
    virtual std::shared_ptr<Document> ducument() = 0;
    virtual std::shared_ptr<DocumentFormat::IFormat> format() = 0;

    void set_param(const std::string &param_name, int value) {
      std::cout << "- Param " << param_name << " was set to " << value << std::endl;
    }
  };
}
