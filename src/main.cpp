#include <Eigen/Dense>
#include <format>
#include <iostream>

#include "lib.h"

void some_function(std::string val) { std::cout << val << std::endl; }

int main() {
  Eigen::Vector2d v{1.0, 0.0};

  some_function("Hello world");
}