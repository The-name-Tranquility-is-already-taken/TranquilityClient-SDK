#include "../include/client.hpp"
#include <iostream>

client_t::client_t(std::string username, std::string password) {
    try {
        std::cout << "Logging in using creds." << "\n";
        auth = new auth_t(username, password);
        cache = new cache_t(auth);
    }
    catch (loginFailed e) {
        std::cout << "Client Setup Failed." << "\n";
    }
}
client_t::client_t(std::string token) {
    try {
        std::cout << "Logging in using token." << "\n";
        auth = new auth_t(token);
        cache = new cache_t(auth);
    }
    catch (loginFailed e) {
        std::cout << "Client Setup Failed." << "\n";
    }
}

