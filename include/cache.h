//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_CACHE_H
#define TRANQUILITYSDK_CACHE_H


#include "auth.h"
#include "core/guild.h"
#include "networking.hpp"

class cache_t {
private:
    auth_t* auth = nullptr;
public:
    std::vector<guild_t*>* guilds;

    cache_t(auth_t* auth);

};

#endif //TRANQUILITYSDK_CACHE_H
