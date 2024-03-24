#include <cstdint>
#include <iostream>

namespace {
constexpr std::uint64_t faculty(const std::uint8_t n) {
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}
}  // namespace

namespace mystd {

enum class Status {
    Unkown,
    Connected,
    Disconnected,
};

struct User {
    Status status;
    std::uint64_t id;
};

}  // namespace mystd

int main() {
    // User user1 = {Status::Connected, 27U};
    mystd::User user1 = {.status = mystd::Status::Connected, .id = 27U};

    std::cout << user1.id << "\n";
    std::cout << static_cast<int32_t>(user1.status) << "\n";
    return 0;
}
