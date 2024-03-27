#include <array>
#include <cstdint>
#include <iostream>

template <std::size_t len>
void print_array_values(std::array<std::uint32_t, len>* arr) {
    std::cout << "func arr addr: " << arr << "\n";
    for (auto i = 0; i < arr->size(); ++i) {
        std::cout << "Element addr " << &arr[i] << ", value " << (*arr)[i]
                  << "\n";
    }
}

int main() {
    //

    std::cout << "pointers.cpp:\n";

    std::uint32_t value = 42;
    std::uint32_t* value_ptr = &value;

    std::cout << "Pointer content: " << value_ptr << "\n";
    std::cout << "Pointer addr: " << &value_ptr << "\n";
    std::cout << "Value addr: " << &value << "\n";
    std::cout << "Pointed value: " << *value_ptr << "\n";

    auto my_array = std::array<uint32_t, 5U>{1, 2, 3, 4, 5};
    std::cout << "my_array addr: " << &my_array << "\n";

    print_array_values(&my_array);

    return 0;
}
