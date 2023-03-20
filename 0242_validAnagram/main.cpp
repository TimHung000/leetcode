#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        int count = t.size();
        for(int i = 0; i < t.size(); ++i)
            ++umap[t[i]];
        
        for(int i = 0; i < s.size(); ++i)
        {
            --umap[s[i]];
            if(umap[s[i]] < 0)
                return false;
            --count;
        }

        return !count ? true : false;
    }
    bool isAnagram1(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> umap;
        for(int i = 0; i < t.size(); ++i)
        {
            ++umap[s[i]];
            --umap[t[i]];
        }

        for(const auto &pair : umap)
            if(pair.second != 0)
                return false;  
        
        return true;
    }
};