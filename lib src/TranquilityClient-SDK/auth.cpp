#include <iostream>
#include "auth.h"
#define CURL_STATICLIB
#include <curl.h>
#include "networking.hpp"

#include <json.hpp>

#include "./includes.hpp" 

using json = nlohmann::json;

std::size_t Callback(
	const char* in,
	std::size_t size,
	std::size_t num,
	std::string* out
)
{
	const std::size_t totalBytes(size * num);
	out->append(in, totalBytes);
	return totalBytes;
}

loginResponce_t authFunc::login(std::string email, std::string password) {
	loginResponce_t res = loginResponce_t();

	json responce = getRequest(WEB_ROOT + "/api/member/login", "email=" + email + "&password=" + password);
	responce = responce["response"];
	if (responce != nullptr) {
		res.failed = false;
		res.user->id		= responce["id"];
		res.token			= responce["token"];
	}
	return res;
};
