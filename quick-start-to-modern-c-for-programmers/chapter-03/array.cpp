#include <array>
#include <cstdint>
#include <iostream>

void print_array_values1(const std::uint32_t arr[], const std::size_t len) {
    for (auto i = 0; i < 5; ++i) {
        std::cout << arr[i] << "\n";
    }
}

template <std::size_t len>
void print_array_values2(const std::array<std::uint32_t, len> arr) {
    for (auto i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << "\n";
    }
}

int main() {
    std::cout << "array.cpp: \n";

    // C stye array
    constexpr static auto len = std::size_t{5};
    std::uint32_t my_array[len] = {1, 2, 3, 4, 5};
    print_array_values1(my_array, len);

    // C++ array
    const auto my_array2 = std::array<std::uint32_t, len>{1, 2, 3, 4, 5};
    print_array_values2(my_array2);

    return 0;
}
