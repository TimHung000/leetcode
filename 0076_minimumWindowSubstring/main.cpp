#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if(t.size() == 0) return "";

        std::unordered_map<char,int> umap;
        int leftPtr = 0;
        int minStart = 0;
        int resLength = INT_MAX;
        int tSize = t.size();
        for(int i = 0; i < t.size(); ++i)
            umap[t[i]]++;
        
        for(int rightPtr = 0; rightPtr < s.size(); ++rightPtr) {
            --umap[s[rightPtr]];
            if(umap[s[rightPtr]] >= 0)
                --tSize;
            
            while(tSize == 0) {
                if(rightPtr - leftPtr + 1 < resLength) {
                    resLength = rightPtr - leftPtr + 1; 
                    minStart = leftPtr;
                }

                ++umap[s[leftPtr]];
                if(umap[s[leftPtr]] > 0)
                    ++tSize;
                ++leftPtr;
            }
        }
        return (resLength != INT_MAX) ? s.substr(minStart, resLength) : "";
    }
};

int main()
{
    Solution sol;
    sol.minWindow("ADOBECODEBANC","ABC");
}