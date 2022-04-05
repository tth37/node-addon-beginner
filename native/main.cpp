#include <iostream>
#include "hello.hpp"

int main() {
    std::cout << "Hello, C++!" << std::endl;

    std::cout << Hello::getHello() << std::endl;

    return 0;
}