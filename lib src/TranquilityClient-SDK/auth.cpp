#include <iostream>
#include "auth.h"
#define CURL_STATICLIB
#include <curl.h>
#include "networking.hpp"

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
	loginResponce_t responcee = loginResponce_t();

	std::cout << "Testt 1!\n";

	getRequest("http://c.spookiebois.club:322/api/member/login", "email=" + email + "&password=" + password);

	return responcee;
};
