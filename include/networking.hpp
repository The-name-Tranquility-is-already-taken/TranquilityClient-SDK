//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_NETWORKING_HPP
#define TRANQUILITYSDK_NETWORKING_HPP

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <curl.h>
#include <nlohmann/json.hpp>
#include "core/user.h"

struct loginResponce_t{
    bool failed = true;

    std::string token = "N/A";
    user_t* user = new user_t();
};
class network {
public:
    static nlohmann::json getRequest(std::string URL, std::string data, std::string token = "");
};
#endif //TRANQUILITYSDK_NETWORKING_HPP
