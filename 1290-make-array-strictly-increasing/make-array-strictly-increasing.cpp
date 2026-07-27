class Solution {
public:
    int makeArrayIncreasing(std::vector<int>& arr1, std::vector<int>& arr2) {
        // Step 1: Preprocess arr2 -> Sort and remove duplicates
        std::sort(arr2.begin(), arr2.end());
        arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());

        // dp maps: last_value_in_arr1 -> min_operations_to_reach_this_value
        std::unordered_map<int, int> dp;
        dp[-1] = 0; // Base case: virtual element before index 0 with value -1 and 0 ops

        for (int x : arr1) {
            std::unordered_map<int, int> next_dp;

            for (auto& [prev_val, ops] : dp) {
                // Option 1: Keep current element arr1[i] (no operation)
                if (x > prev_val) {
                    if (next_dp.find(x) == next_dp.end() || ops < next_dp[x]) {
                        next_dp[x] = ops;
                    }
                }

                // Option 2: Replace current element with the smallest valid element from arr2
                auto it = std::upper_bound(arr2.begin(), arr2.end(), prev_val);
                if (it != arr2.end()) {
                    int new_val = *it;
                    if (next_dp.find(new_val) == next_dp.end() || ops + 1 < next_dp[new_val]) {
                        next_dp[new_val] = ops + 1;
                    }
                }
            }

            // Move to the next state
            dp = std::move(next_dp);
            
            // If dp is empty, it's impossible to make the prefix strictly increasing
            if (dp.empty()) return -1;
        }

        // Find the minimum operations among all valid end values
        int min_ops = INT_MAX;
        for (auto& [val, ops] : dp) {
            min_ops = std::min(min_ops, ops);
        }

        return min_ops == INT_MAX ? -1 : min_ops;
    }
};