#ifndef TRANQUILITYSDK_CLIENT_HPP
#define TRANQUILITYSDK_CLIENT_HPP

#include <string>
#include "auth.h"
#include "cache.h"

#ifdef __cplusplus
extern "C" {
#endif

class client_t {
public:
    auth_t* auth = nullptr;
    bool loggedIn = false;
    bool failedLogin = false;

    user_t* user = nullptr;

    cache_t* cache = nullptr;

    //std::vector<guild_t> guilds = {};

    client_t(std::string username, std::string password);
    client_t(std::string token);

    ~client_t() {
//        delete(auth);
    }

};

#ifdef __cplusplus
}
#endif

#endif //TRANQUILITYSDK_CLIENT_HPP
