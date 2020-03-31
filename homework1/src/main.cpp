#include "version.h"
#include "hello_world.hpp"
#include <iostream>

int main (int, char **)
{
    std::cout << "Version: " << version() << std::endl;
    HelloWorld::print();

    return 0;
}
