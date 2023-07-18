#include <string>
#include <unordered_map>

const std::string base="http://tinyurl.com/";
const std::string code="abcderfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%0123456789";

class Solution {
private:
    std::unordered_map<std::string, std::string> decodeMap;
    std::unordered_map<std::string, std::string> encodeMap;
    std::string createShortUrl() {
        std::string s = base;
        for(int i = 0; i < 6; ++i) {
            s += code[rand()%67];
        }
        return s;
    }
public:

    // Encodes a URL to a shortened URL.
    std::string encode(std::string longUrl) {
        if(encodeMap.find(longUrl) != encodeMap.end())
            return encodeMap[longUrl];

        std::string shortUrl = createShortUrl();
        while(decodeMap.find(shortUrl) != decodeMap.end())
            shortUrl = createShortUrl();
        encodeMap[longUrl] = shortUrl;
        decodeMap[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));