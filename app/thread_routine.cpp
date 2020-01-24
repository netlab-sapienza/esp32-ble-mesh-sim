/*
 * thread_routine.cpp
 */

#include <iostream>
#include "core.h"
#include "firmware.hpp"

int main(int argc, char** argv) {
  bemesh::main_routine(NULL);
  ml_core::coreDummy();
}

