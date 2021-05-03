#pragma once
#include <string>
#define entry(E) std::string E = "";


struct user_t {
	entry(id);
	entry(tag);
	entry(phoneNumber);
	entry(email);
	entry(createdDate);
};

struct guild_t {
	std::string id = "";

};