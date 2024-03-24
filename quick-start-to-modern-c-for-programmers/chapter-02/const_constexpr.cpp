#include <cstdint>
#include <iostream>

// Input only params should be const
constexpr std::uint64_t faculty(const std::uint8_t n) {
    auto result = std::uint64_t{};

    for (std::uint8_t i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}

int main() {
    const auto value = std::uint32_t{42U + 27U};

    // Cannot assign to variable 'value' with
    // const-qualified type 'const std::uint32_t'
    // value = 10U;

    // expression executed at compile time, not runtime
    constexpr auto value2 = std::uint32_t{27U + 1U};

    const auto value3 = faculty(5);
    constexpr auto value4 = faculty(5);
    constexpr static auto value5 = faculty(5);

    std::cout << value3 << "\n";
    std::cout << value4 << "\n";
    std::cout << value5 << "\n";

    return 0;
}
