#pragma once

#include <iostream>
#include <exception>
#include <string>

struct loginFailed : public std::exception {
    const char* what() const throw () {
        return "AuthFailed";
    }
};

struct customException : public std::exception {
    std::string reason = "";
    customException(std::string reason_t) {
        reason = reason_t;
    }
    const char* what() const throw () {
        return reason.c_str();
    }
};