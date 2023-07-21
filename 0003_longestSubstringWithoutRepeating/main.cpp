#include <unordered_map>
#include <iostream>
#include <algorithm>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            std::unordered_map<char, int> umap;
            size_t size = s.size();
            size_t start = 0;
            size_t ret = 0;
            size_t current_length = 0;
            for(int i = 0; i < size; ++i) {
                if(umap.find(s[i]) != umap.end())
                    start = start > umap[s[i]] ? start : umap[s[i]] + 1;
                current_length = i - start + 1;
                ret = ret > current_length ? ret : current_length;
                umap[s[i]] = i;
            }
            return ret;

        }

        int lengthOfLongestSubstring2(std::string s) {
            int map[128];
            std::fill_n(map, 128, -1);
            size_t size = s.size();
            size_t start = 0;
            size_t ret = 0;
            size_t current_length = 0;
            for(int i = 0; i < size; ++i) {
                if(map[s[i]] >= (int)start)
                    start = map[s[i]] + 1;
                current_length = i - start + 1;
                ret = ret > current_length ? ret : current_length;
                map[s[i]] = i;
            }
            return ret;

        }

        int lengthOfLongestSubstring3(std::string s) {
            int map[128] = {0};
            size_t size = s.size();
            size_t ret = 0; 
            size_t start = 0;
            for(int i = 0; i < size; ++i) {
                start = std::max(map[s[i]], (int)start);
                ret = std::max(ret, i - start + 1);
                map[s[i]] = i + 1;
            }
            return ret;

        }
};


int main(int argc, char** argv) {
    Solution sol;
    std::string test2 = "abba";
    std::cout << sol.lengthOfLongestSubstring(test2) << std::endl;
    return 0;
}
