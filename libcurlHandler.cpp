#include <curl/curl.h>
#include <string>
using namespace std;
static class libcurl_handler
{
private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string *) userp)->append((char *) contents, size * nmemb);
        return size * nmemb;
    }

public:
    static std::string GET(std::string url)
    {
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if(res == CURLE_OK)
        {
            return readBuffer;
        }
        else
            return nullptr;
    }
} LibCurlHandler;