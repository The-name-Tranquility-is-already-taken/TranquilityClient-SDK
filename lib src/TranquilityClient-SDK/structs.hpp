#pragma once
#include <string>
#include "baseObject.hpp"
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

	std::string name = "";

	baseStruct_t channels = {};
	baseStruct_t members  = {};

};