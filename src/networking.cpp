//
// Created by conni on 2/6/22.
//

#include "../include/networking.hpp"

std::string encodeForUrlQuery(std::string s)
{
    static const char* allowed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~!$&'()*+,;=:@/?";
    std::string::size_type idx = s.find_first_not_of(allowed);
    while (idx != std::string::npos)
    {
        std::ostringstream oss;
        oss << '%' << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (int)s[idx];
        std::string encoded = oss.str();
        s.replace(idx, 1, encoded);
        idx = s.find_first_not_of(allowed, idx + encoded.length());
    }
    return s;
}
size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static bool doneInit = false;
nlohmann::json network::getRequest(std::string URL, std::string data, std::string token) {
    if (!doneInit) {
        curl_global_init(CURL_GLOBAL_ALL);
    }

    std::cout << URL << " = " << data << std::endl;

    nlohmann::json parsed;
    std::string readBuffer;

    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        struct curl_slist* headers = NULL;
        if(token != "") {
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, (std::string("Authorization: Bearer " + token).c_str()));
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());


        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res == CURLE_COULDNT_CONNECT) {
            assert("CURLE_COULDNT_CONNECT");
        }
        parsed = nlohmann::json::parse(readBuffer);
        if (res != CURLE_OK) {
            fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
            assert("getRequest err");
        }
    }
    curl_easy_cleanup(curl);

    return parsed;
}