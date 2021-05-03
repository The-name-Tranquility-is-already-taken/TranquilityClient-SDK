#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <curl.h>

std::string encodeForUrlQuery(std::string s)
{
    static const char* allowed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~!$&'()*+,;=:@/?";

    // this is just an example, in practice you should first convert the
    // input string to Unicode and charset-encode it, usually to UTF-8,
    // and then percent-encode the resulting octets...

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

bool doneInit = false;
std::string getRequest(std::string URL, std::string data) {
    if (!doneInit) {
        curl_global_init(CURL_GLOBAL_ALL);
    }

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
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
        std::cout << "\nURL: " << URL << std::endl;
            fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
        }
        else {

        }
    }
    curl_easy_cleanup(curl);

    return std::to_string(res);
}
