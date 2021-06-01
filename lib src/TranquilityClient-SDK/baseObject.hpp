#pragma once
#include <string>
#include <vector>
#include "logging.hpp"

struct baseObject {
	std::string id = "-1";
	std::string name = "empty";

	baseObject() {

	};
};

struct baseStruct_t {
private:
	std::vector<baseObject> array = {};
public:
	std::vector<baseObject> get() {
		return array;
	}

	baseObject find(std::string name) {
		for (baseObject e : array) {
			if (e.name == name) {
				logg("Found baseObject by name", "VERBOSE");
				return e;
			}
		}
		logg("Couldnt find baseObject by name", "WARNING");
		return baseObject();
	}
};