#include <iostream>
#include "auth.h"
#define CURL_STATICLIB
#include <curl.h>

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

loginResponce_t authFunc::login(std::string username, std::string password) {
	loginResponce_t responcee = loginResponce_t();

	std::cout << "Testt 1!\n";

	CURL* curl;
	CURLcode res;

	/* get a curl handle */
	curl = curl_easy_init();
	if (curl)
	{
		/*Create fields */
		std::string fields;
		fields += "email=" + username + "&";
		fields += "password=" + password + "&";
		std::cout << fields << std::endl;
		/* First set the URL that is about to receive our POST. This URL can
		   just as well be a https:// URL if that is what should receive the
		   data.
		*/
		curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:322/api/member/login");
		/* Now specify the POST data */
		curl_easy_setopt(curl,
			CURLOPT_POSTFIELDS,
			fields.c_str()
		);

		std::unique_ptr<std::string> httpData(new std::string());

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());


		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
		//Json::Value jsonData;
		//Json::Reader jsonReader;

		//if (jsonReader.parse(*httpData, jsonData))
		//	return std::make_pair(res, jsonData);

	}

	return responcee;
};
