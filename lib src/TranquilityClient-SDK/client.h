#pragma once
#include <string>
#include "auth.h"
#include "errors.h"

struct client_t {
	auth_t* auth		= nullptr;
	bool loggedIn		= false;
	bool failedLogin	= false;

	client_t(std::string token_t) {
		try {
			auth = new auth_t(token_t);
		}
		catch (loginFailed e) {
			std::cout << "Auth Failed" << "\n";
		}
	}

	client_t(std::string username, std::string password) {
		try {
			auth = new auth_t(username, password);
		}
		catch (loginFailed e) {
			std::cout << "Auth Failed" << "\n";
		}
	}

	~client_t() {
		delete(auth);
	}
};
