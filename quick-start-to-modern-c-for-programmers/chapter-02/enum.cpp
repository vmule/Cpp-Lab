#include <iostream>

enum class Status {
    Unknown,
    Connected,
    Disconected,
};

enum class UserPermission {
    Unknown,
    User,
    Admin,
};

int main() {
    Status s1 = Status::Unknown;

    UserPermission s2 = UserPermission::Unknown;

    switch (s1) {
        case Status::Unknown: {
            std::cout << "Unkown\n";
            break;
        }
        case Status::Connected: {
            std::cout << "Connected\n";
            break;
        }
        case Status::Disconected: {
            std::cout << "Disconnected\n";
            break;
        }
    }

    if (s1 == Status::Unknown) {
        std::cout << "Unkown\n";
    }
    return 0;
}
