#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string alphanumeric;
        for(char c : s)
        {
            if(isalpha(c))
                alphanumeric.push_back(tolower(c));
            if(isdigit(c))
                alphanumeric.push_back(c);
        }
        for(int i = 0; i < alphanumeric.size(); ++i)
        {
            if(alphanumeric[i] != alphanumeric[alphanumeric.size()-i-1])
                return false;
        }
        return true;
    }

    bool isPalindrome1(string s) {
        int size = s.size();
        int left = 0;
        int right = size-1;

        while(left < right)
        {
            while(left < right && !isalnum(s[left]))
                ++left;
            while(left < right && !isalnum(s[right]))
                --right;
            if(tolower(s[left]) != towlower(s[right]))
                return false;
        }
        ++left;--right;

        return true;
    }
};