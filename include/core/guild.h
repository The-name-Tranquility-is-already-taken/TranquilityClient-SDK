//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_GUILD_H
#define TRANQUILITYSDK_GUILD_H

#include "base_object.h"
#include "auth.h"
#include <string>
#include <iostream>
#include <thread>

class guild_t : public baseObject {
private:
public:
    baseStruct_t* channels = {};
    baseStruct_t* members  = {};

    void populate(auth_t* auth);
    guild_t();
};

#endif //TRANQUILITYSDK_GUILD_H
