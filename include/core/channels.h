//
// Created by conni on 2/6/22.
//

#ifndef TRANQUILITYSDK_CHANNELS_H
#define TRANQUILITYSDK_CHANNELS_H

#include "base_object.h"

class MessageChannel : public baseObject {
public:
    int order = -1;
    int parent = -1;

    std::string desc = "-1";

    baseStruct_t* messages = {};
    int lastSeenMessage = 0;
    int lastSentMessage = 0;

};

class VoiceChannel : public baseObject {
public:
    int order = -1;
    int parent = -1;

    baseStruct_t* users = {};
};

#endif //TRANQUILITYSDK_CHANNELS_H
