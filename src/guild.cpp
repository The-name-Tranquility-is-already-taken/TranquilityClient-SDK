//
// Created by conni on 2/6/22.
//

#include "core/guild.h"
#include "nlohmann/json.hpp"
#include "networking.hpp"
#include "includes.h"
#include "core/channels.h"

guild_t::guild_t() {

}

void populate_thread(auth_t* auth, guild_t* guild) {
    // Populate this guild object with channels etc
    std::cout << "Thread created, populating guild id: " << guild->id << std::endl;

    nlohmann::json responce = network::getRequest(WEB_ROOT + "/api/" + auth->user->id + "/guild/" + guild->id, "", auth->token);
    std::cout << responce << std::endl;
    responce = responce["response"];
    std::cout << responce << std::endl;
    std::cout << responce["name"].get<std::string>() << std::endl;
    std::cout << responce["description"].get<std::string>() << std::endl;
    std::cout << responce["ownerID"].get<std::string>() << std::endl;
    std::cout << responce["createdDate"].get<std::string>() << std::endl;

    for(auto bucket : responce["buckets"]) {
        std::cout << bucket << std::endl;
    }
    for(auto channel_t : responce["channels"]) {
        MessageChannel* channel = new MessageChannel();
        channel->id = channel_t["id"].get<std::string>();
        channel->name = channel_t["name"].get<std::string>();
        channel->parent = std::stoi(channel_t["parentID"].get<std::string>());
        channel->desc = channel_t["desc"].get<std::string>();
    }
    for(auto member : responce["members"]) {
        std::cout << member.get<std::string>() << std::endl;
    }
//    std::cout << responce["buckets"].get<std::string>() << std::endl;
//    std::cout << responce["channels"].get<std::string>() << std::endl;
//    std::cout << responce["members"].get<std::string>() << std::endl;

//    for(auto thing : responce["guilds"]) {
//        std::string t = to_string(thing);
//        if (t.size () > 0)  {
//            t.resize (t.size () - 1);
//            t.substr(1);
//        }
//        std::cout << t <<  std::endl;
//
//        MessageChannel* channel = new MessageChannel();
//        channel->id = t;
//        // TODO: Populate message cache
//        //          and lastSeenMessage/lastSentMessage
//
//        channels->array.push_back(guild);
//    }
//    std::cout << "=" << responce["guilds"].size() << "=" <<  std::endl;
}

void guild_t::populate(auth_t* auth) {
    std::cout << "Populating info for guild id: " << this->id << std::endl;

    populate_thread(auth, this);
    //std::thread(populate_thread, auth, this);
}