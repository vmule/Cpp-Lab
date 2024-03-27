#include <array>
#include <cstdint>
#include <iostream>

int main() {
    std::cout << "heap.cpp \n";

    // using the stack, memory allocated at compile time
    constexpr static auto len = std::size_t{5};
    std::uint32_t stack_arr[len] = {1, 2, 3, 4, 5};
    std::cout << "stack_arr addr: " << &stack_arr << "\n";

    auto len2 = std::size_t{};
    std::cout << "Input array length: \n";

    std::cin >> len2;

    std::uint32_t* heap_arr = new std::uint32_t[len2];
    std::cout << "heap_arr addr: " << heap_arr << "\n";

    if (heap_arr != nullptr) {
        for (std::uint32_t i = 0; i < len2; ++i) {
            heap_arr[i] = i + 1;
            std::cout << "Array index " << i << ", value " << heap_arr[i]
                      << "\n";
        }
    }

    delete[] heap_arr;
    heap_arr = nullptr;

    if (heap_arr) {
        std::cout << "Array index 1" << ", value " << heap_arr[1] << "\n";
    }

    return 0;
}
