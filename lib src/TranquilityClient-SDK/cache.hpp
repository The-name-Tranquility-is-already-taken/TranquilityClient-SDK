#pragma once
#include <vector>
#include "logging.hpp"

#define LOG_ERROR(Message) LOG_ERROR_DEF(Message, "cache.hpp")
#define LOG_WARNING(Message) LOG_WARNING_DEF(Message, "cache.hpp")

struct cache_t {
	std::vector<guild_t>* guilds;

	cache_t(auth_t* auth) {
		
	}
};