#include <cstdint>
#include <iostream>

int main() {

  bool b1 = false;
  bool b2 = true;

  bool c1 = (b1 || b2) && b1;

  if (b1 == true) {
    std::cout << "True!\n";
  } else if (b2 != true) {
    std::cout << "False!\n";
  }

  std::int32_t result;
  if (b1) {
    result = 10;
  } else {
    result = -10;
  }

  std::int32_t result2 = b1 == true ? 10 : -10;
  return 0;
}
