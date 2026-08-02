class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        string str = s + s;
        string alt1 = "", alt2 = "";

        for (int i = 0; i < 2 * n; i++) {
            alt1 += (i % 2 == 0) ? '0' : '1';
            alt2 += (i % 2 == 0) ? '1' : '0';
        }

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {
            if (str[right] != alt1[right]) diff1++;
            if (str[right] != alt2[right]) diff2++;

            if (right - left + 1 > n) {
                if (str[left] != alt1[left]) diff1--;
                if (str[left] != alt2[left]) diff2--;
                left++;
            }

            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};