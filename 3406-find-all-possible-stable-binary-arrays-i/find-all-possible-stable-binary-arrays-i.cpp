class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[201][201][2][201];

    int solve(int zero, int one, int last, int cnt, int limit) {
        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][last][cnt] != -1)
            return dp[zero][one][last][cnt];

        long long ans = 0;

        // Place 0
        if (zero > 0) {
            if (last == 0) {
                if (cnt < limit)
                    ans += solve(zero - 1, one, 0, cnt + 1, limit);
            } else {
                ans += solve(zero - 1, one, 0, 1, limit);
            }
        }

        // Place 1
        if (one > 0) {
            if (last == 1) {
                if (cnt < limit)
                    ans += solve(zero, one - 1, 1, cnt + 1, limit);
            } else {
                ans += solve(zero, one - 1, 1, 1, limit);
            }
        }

        return dp[zero][one][last][cnt] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        if (zero > 0)
            ans += solve(zero - 1, one, 0, 1, limit);

        if (one > 0)
            ans += solve(zero, one - 1, 1, 1, limit);

        return ans % MOD;
    }
};