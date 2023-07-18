import string
import random

class Codec:
    def __init__(self):
        self.encodeMap = {}
        self.decodeMap = {}
        self.base = "http://tinyurl.com/"
        self.chars = string.ascii_letters + string.digits

    def getShortUrl(self) -> str:
        code = ''.join(random.choice(self.chars) for i in range(6))
        return "http://tinyurl.com/" + code

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        if longUrl in self.decodeMap:
            return self.decodeMap[longUrl]
        
        shortUrl = self.getShortUrl()
        while shortUrl in self.encodeMap: 
            shortUrl = self.getShortUrl()
        self.encodeMap[longUrl] = shortUrl
        self.decodeMap[shortUrl] = longUrl

        return shortUrl
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.decodeMap[shortUrl]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))