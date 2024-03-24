#include <cstdint>
#include <iostream>

enum class Status {
    Unkown,
    Connected,
    Disconnected,
};

struct User {
    Status status;
    std::uint64_t id;
};

int main() {
    // User user1 = {Status::Connected, 27U};
    User user1 = {.status = Status::Connected, .id = 27U};

    std::cout << user1.id << "\n";
    std::cout << static_cast<int32_t>(user1.status) << "\n";
    return 0;
}
