#pragma once

#include "document_builder/ibuilder.h"
#include "document_format/handler/ihandler.h"
#include "document_format/resolver.h"

namespace DocumentBuilder
{
  struct FromFile : IBuilder
  {
    virtual std::shared_ptr<Document> ducument() override {
      auto document = std::make_shared<Document>();
      format()->handler()->import_document(document, "some file name");
      std::cout << "- Document was built from file\n";

      return document;
    }

    virtual std::shared_ptr<DocumentFormat::IFormat> format() override {
      return DocumentFormat::Resolver::call("filename from param");
    }

    void set_param(const std::string &param_name, const std::string &value) {
      std::cout << "- String parameter " << param_name << " was set to '" << value << "'\n";
    }
  };
}
