#pragma once
#include <string>
#include "auth.h"
#include "errors.h"
#include "cache.hpp"

struct client_t {
	auth_t* auth		= nullptr;
	bool loggedIn		= false;
	bool failedLogin	= false;

	cache_t* cache		= nullptr;

	client_t(std::string username, std::string password) {
		try {
			auth = new auth_t(username, password);
			cache = new cache_t(auth);
		}
		catch (loginFailed e) {
			std::cout << "Client Setup Failed." << "\n";
		}
	}

	~client_t() {
		delete(auth);
	}
};
