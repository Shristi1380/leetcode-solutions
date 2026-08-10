#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] will store true if the player with 'i' stones can force a win, false otherwise.
        std::vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                // If taking k*k stones leaves the opponent in a losing state,
                // the current player wins this state.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Break early once a winning move is found
                }
            }
        }
        
        return dp[n];
    }
};