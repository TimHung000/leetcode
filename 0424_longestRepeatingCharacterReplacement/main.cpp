#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int leftPtr = 0;
        int rightPtr = 0;
        int charCount[26] = {};
        int res = 0;
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            charCount[s[rightPtr]-'A']++;
            if((rightPtr-leftPtr+1)- *max_element(charCount, charCount+26) <= k)
            {
                res = rightPtr - leftPtr + 1;
            }
            else
            {
                charCount[s[leftPtr]-'A']--;
                leftPtr++;
            }
        }
        return res;
    }

    int characterReplacement1(string s, int k) {
        int leftPtr = 0;
        int rightPtr = 0;
        int maxCount = 0;
        int charCount[26] = {};
        int res = 0;
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            charCount[s[rightPtr]-'A']++;
            maxCount = max(charCount[s[rightPtr]-'A'], maxCount);
            if((rightPtr-leftPtr+1)- maxCount <= k)
            {
                res = rightPtr - leftPtr + 1;
            }
            else
            {
                charCount[s[leftPtr]-'A']--;
                leftPtr++;
            }
        }
        return res;
    }
    
};