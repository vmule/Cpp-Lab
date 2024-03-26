#include <array>
#include <cstdint>
#include <iostream>

template <std::size_t len>
void print_array_mem_addr_copy(const std::array<std::uint32_t, len> arr) {
    std::cout << "copy array memory address: " << &arr << "\n";
}

template <std::size_t len>
void print_array_mem_addr_reference(const std::array<std::uint32_t, len>& arr) {
    std::cout << "ref array memory address:  " << &arr << "\n";
}

template <std::size_t len>
void double_array_values(std::array<std::uint32_t, len>& arr) {
    for (auto i = 0; i < arr.size(); ++i) {
        arr[i] = arr[i] * 2;
    }
}

template <std::size_t len>
void print_array_values(const std::array<std::uint32_t, len>& arr) {
    for (auto i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << "\n";
    }
}

int main() {
    std::cout << "copy_reference.cpp: \n";

    // C++ array
    auto my_array = std::array<std::uint32_t, 5U>{1, 2, 3, 4, 5};
    std::cout << "my_array memory address:   " << &my_array << "\n";
    print_array_mem_addr_copy(my_array);
    print_array_mem_addr_reference(my_array);

    double_array_values(my_array);
    print_array_values(my_array);

    return 0;
}
