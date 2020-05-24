#include "common.h"
#include "current_document.h"
#include "graphical_primitive/line.h"
#include <iostream>

void set_document(DocumentBuilder::IBuilder &builder)
{
  CurrentDocument::set_document(builder.ducument());
  CurrentDocument::set_format(builder.format());
}

void export_document(bool clear_current_document = true)
{
  auto current_document = CurrentDocument::get_document();

  if (current_document) {
    std::cout << "- Saving current document\n";
    auto exporter = CurrentDocument::get_format()->handler();
    exporter->export_document(current_document, "some file name");

    if (clear_current_document)
      CurrentDocument::clear();
  }
}

void create_document()
{
  export_document();

  std::cout << "- Getting document params\n";

  DocumentBuilder::Emtpy builder;
  builder.set_param("format", 1);
  builder.set_param("new_filename", 2);

  set_document(builder);
}

void import_document()
{
  std::cout << "- Asking file name\n";

  DocumentBuilder::FromFile builder;
  builder.set_param("filename", "some file name");

  set_document(builder);
}
