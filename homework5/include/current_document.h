#pragma once

#include "document.h"
#include "document_format/iformat.h"
#include <memory>

struct CurrentDocument
{
  static void set_document(std::shared_ptr<Document> doc) {
    CurrentDocument::document = doc;

    std::cout << "- Currennt document was set\n";
  }

  static void set_format(std::shared_ptr<DocumentFormat::IFormat> fmt) {
    CurrentDocument::format = fmt;

    std::cout << "- Currennt document format was set\n";
  }

  static std::shared_ptr<Document> get_document() {
    return CurrentDocument::document;
  }

  static std::shared_ptr<DocumentFormat::IFormat> get_format() {
    return CurrentDocument::format;
  }

  static void clear() {
    CurrentDocument::format.reset();
    CurrentDocument::document.reset();

    std::cout << "- Currennt document was cleared\n";
  }
private:
  static std::shared_ptr<Document> document;
  static std::shared_ptr<DocumentFormat::IFormat> format;
};


