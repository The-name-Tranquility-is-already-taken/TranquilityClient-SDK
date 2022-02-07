//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_BASE_OBJECT_H
#define TRANQUILITYSDK_BASE_OBJECT_H

#include <string>
#include <vector>

class baseObject {
public:
    baseObject() {

    };
    std::string id = "NOT-SET";
    std::string name = "NOT-SET";
};

class baseStruct_t {
private:
public:
    std::vector<baseObject> array = {};

    std::vector<baseObject> get() {
        return array;
    }

    baseObject find(std::string name) {
        for (baseObject e : array) {
            if (e.name == name) {
                return e;
            }
        }
        return baseObject();
    }
};

#endif //TRANQUILITYSDK_BASE_OBJECT_H
