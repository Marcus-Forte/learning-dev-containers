#include <Eigen/Dense>
#include <format>
#include <iostream>

#include "lib.h"

void fun(int a) {

}


int main() {
  auto res = Adder::sumInt(5, 10);
  fun(res);

  Eigen::Vector3f vec3;

  std::cout << std::format("Hello! {}", res) << std::endl;
}