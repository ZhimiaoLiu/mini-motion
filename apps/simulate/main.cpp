#include <iostream>

#include "motion/version.hpp"

int main() {
    std::cout << "mini-motion " << motion::version() << '\n';
    return 0;
}
