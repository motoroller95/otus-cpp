#include "version.h"
#include "hello_world/hello_world.hpp"
#include <iostream>

int main (int, char **)
{
    std::cout << "Version: " << version() << std::endl;
    std::cout << HelloWorld::message() << std::endl;

    return 0;
}
