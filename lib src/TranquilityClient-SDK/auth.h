#pragma once
#include <string>
#include "errors.h"
#include "structs.h"

namespace authFunc {
	loginResponce_t login(std::string username, std::string password);
};

struct auth_t {	
	std::string token = "N/A";
	bool loggedIn = false;

	auth_t(std::string username, std::string password) {
		loginResponce_t res = authFunc::login(username, password);

		if (res.failed) {
			throw loginFailed();
		}
	}
};
