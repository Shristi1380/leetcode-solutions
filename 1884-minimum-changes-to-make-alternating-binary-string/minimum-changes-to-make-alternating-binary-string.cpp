class Solution {
public:
    int minOperations(string s) {
        int startWith0 = 0;
        int startWith1 = 0;

        for (int i = 0; i < s.length(); i++) {
            // Expected character if pattern starts with '0'
            char expected0 = (i % 2 == 0) ? '0' : '1';

            // Expected character if pattern starts with '1'
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0)
                startWith0++;

            if (s[i] != expected1)
                startWith1++;
        }

        return min(startWith0, startWith1);
    }
};