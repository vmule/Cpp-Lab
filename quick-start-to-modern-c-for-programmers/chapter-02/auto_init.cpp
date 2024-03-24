#include <iostream>

int main() {
    float a = 10.0F;

    // std::int32_t b = a;
    // auto c = std::int32_t{a};
    auto d = static_cast<std::int32_t>(a);

    // error detected at compile time
    auto e = std::int32_t{a};

    return 0;
}
