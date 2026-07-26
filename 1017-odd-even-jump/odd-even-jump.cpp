class Solution {
public:
    int oddEvenJumps(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        // DP tables:
        // higher[i]: Can we reach the end starting from index i with an ODD jump?
        // lower[i] : Can we reach the end starting from index i with an EVEN jump?
        std::vector<bool> higher(n, false);
        std::vector<bool> lower(n, false);

        // Base case: The last index is already at the destination
        higher[n - 1] = true;
        lower[n - 1] = true;

        // Map stores: array_value -> index
        // std::map maintains keys in sorted order, allowing O(log N) searches.
        std::map<int, int> valToIdx;
        valToIdx[arr[n - 1]] = n - 1;

        int goodStarts = 1; // Index n - 1 is always a valid starting point

        // Process backward from n - 2 down to 0
        for (int i = n - 2; i >= 0; --i) {
            
            // 1. ODD JUMP: Find smallest value >= arr[i] to the right
            // lower_bound gives the first element with key >= arr[i]
            auto hi = valToIdx.lower_bound(arr[i]);
            if (hi != valToIdx.end()) {
                higher[i] = lower[hi->second];
            }

            // 2. EVEN JUMP: Find largest value <= arr[i] to the right
            // upper_bound gives the first element with key > arr[i]
            auto lo = valToIdx.upper_bound(arr[i]);
            if (lo != valToIdx.begin()) {
                --lo; // Step back one position to get the largest value <= arr[i]
                lower[i] = higher[lo->second];
            }

            // If an odd jump from i leads to the end, i is a good starting index
            if (higher[i]) {
                goodStarts++;
            }

            // Insert / update current value and its index in the map
            valToIdx[arr[i]] = i;
        }

        return goodStarts;
    }
};