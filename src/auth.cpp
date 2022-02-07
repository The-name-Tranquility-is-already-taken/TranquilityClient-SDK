//
// Created by conni on 2/6/22.
//

#include "auth.h"

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

void setupUser(loginResponce_t* loginResponce) {
    json userdataResponse = network::getRequest(WEB_ROOT + "/api/member/" + loginResponce->user->id, "", loginResponce->token);
    std::cout << userdataResponse << std::endl;
    if (userdataResponse == "Un-Authenticated") {
        std::cout << "Failed to login!" << std::endl;
        return;
    }
    std::cout << userdataResponse << std::endl;
    loginResponce->user->id = userdataResponse["id"].get<std::string>();
    loginResponce->user->tag.username = userdataResponse["tag"].get<std::string>().substr(0, userdataResponse["tag"].get<std::string>().find("#"));
//    std::string tagID = (userdataResponse["tag"].get<std::string>()
//                                            .substr(
//                                                    userdataResponse["tag"].get<std::string>().find("#") + 1,
//                                                   userdataResponse["tag"].get<std::string>().size()));
//    std::cout << tagID << std::endl;
    loginResponce->user->tag.tagID = 1; //std::stoi("1");
    loginResponce->user->tag.rootServer = ""; // TODO: Specify root server
    loginResponce->user->email.email = userdataResponse["email"];
    loginResponce->user->email.verified = userdataResponse["email"] != "" ? true : false;

//    loginResponce.user->phoneNumber.number = userdataResponse["phoneNumber"].get<int>();
    loginResponce->user->email.verified = userdataResponse["phoneNumber"] != "N/A" ? true : false;

    loginResponce->user->createdDate = userdataResponse["createdDate"];
}

loginResponce_t login(std::string token) {
    loginResponce_t res = loginResponce_t();

    json responce = network::getRequest(WEB_ROOT + "/api/member/login", "token=" + token);
    responce = responce["response"];
    if (responce == nullptr) {
        return res;
    }
    if (responce == "Un-Authenticated") {
        std::cout << "Failed to login!" << std::endl;
        return res;
    }
    std::cout << responce << std::endl;
    res.failed = false;
    res.user->id = responce["id"];
    res.token = responce["token"];


    std::cout << "GET USER!!!!!!!!!!" << std::endl;
    setupUser(&res);

    return res;
};

loginResponce_t login(std::string email, std::string password) {
    loginResponce_t res = loginResponce_t();

    json responce = network::getRequest(WEB_ROOT + "/api/member/login", "email=" + email + "&password=" + password);
    responce = responce["response"];
    if (responce == nullptr) {
        return res;
    }
    if (responce == "Un-Authenticated") {
        std::cout << "Failed to login!" << std::endl;
        return res;
    }
    std::cout << responce << std::endl;
    res.failed = false;
    res.user->id = responce["id"];
    res.token = responce["token"];


    std::cout << "GET USER!!!!!!!!!!" << std::endl;
    setupUser(&res);

    return res;
};

auth_t::auth_t(std::string username, std::string password) {
    loginResponce_t res = login(username, password);
    if (res.failed) throw loginFailed();

    std::cout << "Logged in as user id - " + res.user->id << std::endl;
    user = res.user;
    token = res.token;

    std::cout << user->id << std::endl;
    std::cout << "tag.username   - " << user->tag.username << std::endl;
    std::cout << "tag.rootServer - " << user->tag.rootServer << std::endl;
    std::cout << "tag.tagID      - " << user->tag.tagID << std::endl;
    std::cout << user->phoneNumber.number << " - " << user->phoneNumber.verified << std::endl;
    std::cout << user->email.email << " - " << user->email.verified << std::endl;
    std::cout << user->createdDate << std::endl;

}

auth_t::auth_t(std::string token) {
    loginResponce_t res = login(token);
    if (res.failed) throw loginFailed();

    std::cout << "Logged in as user id - " + res.user->id << std::endl;
    user = res.user;
    token = res.token;

    std::cout << user->id << std::endl;
    std::cout << "tag.username   - " << user->tag.username << std::endl;
    std::cout << "tag.rootServer - " << user->tag.rootServer << std::endl;
    std::cout << "tag.tagID      - " << user->tag.tagID << std::endl;
    std::cout << user->phoneNumber.number << " - " << user->phoneNumber.verified << std::endl;
    std::cout << user->email.email << " - " << user->email.verified << std::endl;
    std::cout << user->createdDate << std::endl;
}