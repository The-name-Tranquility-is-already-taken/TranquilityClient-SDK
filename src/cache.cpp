//
// Created by conni on 2/6/22.
//

#include "cache.h"

cache_t::cache_t(auth_t* auth_t) {
    auth = auth_t;

    nlohmann::json responce = network::getRequest(WEB_ROOT + "/api/guild/" + auth->user->id, "", auth->token);
    std::cout << responce << std::endl;
    responce = responce["response"];
    for(auto thing : responce["guilds"]) {
        guild_t* guild = new guild_t();
        guild->id = thing.get<std::string>();
        guild->populate(auth);

        guilds->push_back(guild);
    }
    std::cout << "=" << responce["guilds"].size() << "=" <<  std::endl;

    for(guild_t* guild : *guilds) {
        std::cout << "Handling " << guild->name << std::endl;
        for(baseObject channel : guild->channels->array) {
            std::cout << "Found channel called " << channel.name << std::endl;
        }
    }
}