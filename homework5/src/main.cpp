#include "current_document.h"
#include "common.h"
#include "graphical_primitive/circle.h"
#include "graphical_primitive/line.h"
#include "graphical_primitive/rectangle.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

std::shared_ptr<Document> CurrentDocument::document = nullptr;
std::shared_ptr<DocumentFormat::IFormat> CurrentDocument::format = nullptr;

void test_case1();
void test_case2();

void new_document_menu_item_clckied()
{
  std::cout << "- New document menu item clicked\n";
  create_document();
}

void export_document_menu_item_clickied()
{
  std::cout << "- Export existing document menu item clicked\n";
  export_document(false);
}

void import_document_menu_item_clicked()
{
  std::cout << "- Import existing document menu item clicked\n";
  import_document();
}

int main (int, char **)
{
  std::srand(std::time(0));

  test_case1();
  test_case2();
  return 0;
}

void test_case1()
{
  std::cout << "1. User creates new document, draws picture and closes document\n";

  new_document_menu_item_clckied();

  auto primitive1 = std::make_shared<GraphicalPrimitives::Line>();
  auto primitive2 = std::make_shared<GraphicalPrimitives::Rectangle>();
  CurrentDocument::get_document()->add_primitive(primitive1);
  CurrentDocument::get_document()->add_primitive(primitive2);

  export_document_menu_item_clickied();
}

void test_case2()
{
  std::cout << "2. User importes document, modify it and closes\n";

  import_document_menu_item_clicked();

  auto primitive = CurrentDocument::get_document()->get_primitive_by_coordinate(/* x, y */);
  CurrentDocument::get_document()->remove_primitive(primitive);

  primitive = std::make_shared<GraphicalPrimitives::Rectangle>();
  CurrentDocument::get_document()->add_primitive(primitive);

  export_document_menu_item_clickied();
}
