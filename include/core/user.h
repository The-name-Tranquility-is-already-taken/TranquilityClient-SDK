//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_USER_H
#define TRANQUILITYSDK_USER_H

#include "base_object.h"
#define entry(E) std::string E = "";

class accountTag {
public:
    std::string username = "NOT-SET";
    int tagID = -1;
    std::string rootServer = "NOT-SET";
};

class phoneNumber_t {
public:
    int number = -1;
    bool verified = false;
};

class email_t {
public:
    std::string email = "NOT-SET";
    bool verified = false;
};

class user_t : public baseObject {
public:
    accountTag tag = accountTag();
    phoneNumber_t phoneNumber = phoneNumber_t();
    email_t email = email_t();
    std::string createdDate = "NOT-SET";
};


#endif //TRANQUILITYSDK_USER_H
