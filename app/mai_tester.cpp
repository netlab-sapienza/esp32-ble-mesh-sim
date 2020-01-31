//
// Created by thecave3 on 31/01/20.
//

#include "handler.hpp"
#include <iostream>

int main() {

  MediumAccessInterface *accessInterface = MediumAccessInterface::getInstance();
  MediumAccessInterface *mediumAccessInterface = MediumAccessInterface::getInstance();

  /* The addresses will be the same. */
  std::cout << accessInterface << std::endl;
  std::cout << mediumAccessInterface << std::endl;
}