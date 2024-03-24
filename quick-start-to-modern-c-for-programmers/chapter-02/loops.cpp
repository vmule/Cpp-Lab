#include <cstdint>
#include <iostream>

int main() {

  for (std::uint32_t i = 0U; i < 3U; ++i) {
    std::cout << i << "\n";
  }

  for (std::uint32_t i = 0U; i > 0U; --i) {
    std::cout << i << "\n";
  }

  std::int32_t i = 1;
  std::int32_t result = i++;
  std::cout << "\n" << result << "\n";

  i = 1;
  result = ++i;
  std::cout << "\n" << result << "\n";

  while (true) {
    ++i;
    if (i > 3) {
      break;
    }
  }

  return 0;
}
