class Solution {
public:
    int concatenatedBinary(int n) {
        long long result = 0;
        int MOD = 1e9 + 7;
        int bitLength = 0;

        for (int i = 1; i <= n; ++i) {
            // Check if 'i' is a power of 2. If so, increment the bit length.
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            
            // Shift current result left by bitLength bits and add 'i'
            result = ((result << bitLength) + i) % MOD;
        }

        return result;
    }
};