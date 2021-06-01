#pragma once
#include <string>
#include "errors.h"
#include "networking/structs.h"
#include "structs.hpp"

namespace authFunc {
	loginResponce_t login(std::string username, std::string password);
};

struct auth_t {
	user_t* user = new user_t();

	std::string token = "N/A";
	bool loggedIn = false;

	auth_t(std::string username, std::string password) {
		loginResponce_t res = authFunc::login(username, password);

		if (res.failed) throw loginFailed();

		std::cout << "Logged in as user id - " + res.user->id << std::endl;
		user = res.user;
		token = res.token;
	}
};
