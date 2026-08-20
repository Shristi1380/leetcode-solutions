#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 1;
        
        // Helper lambda to expand outward from a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if (currentLen > maxLen) {
                    start = left;
                    maxLen = currentLen;
                }
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i);     // Odd-length palindromes (e.g., "aba")
            expandAroundCenter(i, i + 1); // Even-length palindromes (e.g., "abba")
        }
        
        return s.substr(start, maxLen);
    }
};