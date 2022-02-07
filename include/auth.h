//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_AUTH_H
#define TRANQUILITYSDK_AUTH_H

#include <string>
#include <iostream>
#define CURL_STATICLIB
#include <curl.h>
#include "errors.h"
#include "networking.hpp"

#include "./includes.h"


loginResponce_t login(std::string username, std::string password);
class auth_t {
public:
    std::string token = "N/A";

    bool loggedIn = false;
    user_t* user = new user_t();

    auth_t(std::string username, std::string password);
    auth_t(std::string token);
};


#endif //TRANQUILITYSDK_AUTH_H
