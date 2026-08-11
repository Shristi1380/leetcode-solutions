#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        
        // Step 1: Sum the longest sequential prefix starting at index 0
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // Step 2: Store elements in a hash set for fast lookup
        std::unordered_set<int> present(nums.begin(), nums.end());
        
        // Step 3: Find the smallest missing integer >= sum
        while (present.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};