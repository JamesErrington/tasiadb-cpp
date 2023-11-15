#include <iostream>
#include <string>

#include "tasiadb/tasiadb.hpp"

int main() {
    std::string input;
    std::getline(std::cin, input);

    tasiadb::parse(input);
}
