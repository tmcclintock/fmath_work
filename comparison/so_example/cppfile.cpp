#include "cppfile.hpp"
#include <string>
extern "C"{
  int myfunction(const char *filename) {
    std::string S(filename);
    return 0;
  }
}

