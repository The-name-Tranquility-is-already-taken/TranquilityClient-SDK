#pragma once
#include "../structs.hpp"

struct loginResponce_t{
	bool failed = true;

	std::string token = "N/A";
	user_t* user = new user_t();
};
