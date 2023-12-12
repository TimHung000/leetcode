#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int minDeletions(std::string s) {
        std::unordered_map<char, int> countDict;
        for (int i = 0; i < s.size(); ++i)
            countDict[s[i]]++;

        std::unordered_set<int> usedFreq;
        int res = 0;
        for (std::unordered_map<char, int>::iterator it = countDict.begin(); it != countDict.end(); ++it) {
            while (it->second > 0 && usedFreq.find(it->second) != usedFreq.end()) {
                it->second--;
                res += 1;
            }
            usedFreq.insert(it->second);
        }
        return res;
    }
};