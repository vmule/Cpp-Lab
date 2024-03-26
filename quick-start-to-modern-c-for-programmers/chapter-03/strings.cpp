#include <array>
#include <cstdint>
#include <iostream>

int main() {
    std::cout << "strings.cpp: \n";

    // C-String
    char my_text1[] = "ABCDEFG";

    // C++ Array - DO NOT USE
    auto my_text2 = std::array<char, 2>{'A', 'B'};

    // C++ String
    auto my_text3 = std::string{"ABCDEFG"};
    std::cout << "My C++ string is " << my_text3 << " with size "
              << my_text3.size() << "\n";

    return 0;
}
