class Solution {
public:
    int oddEvenJumps(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        // higher[i]: Can we reach the end from index i starting with an ODD jump?
        // lower[i] : Can we reach the end from index i starting with an EVEN jump?
        std::vector<bool> higher(n, false);
        std::vector<bool> lower(n, false);

        // Base case: at the last index, you are already at the destination
        higher[n - 1] = true;
        lower[n - 1] = true;

        // Map stores: value -> index
        // Since std::map is automatically sorted by key, we can find target values in O(log N)
        std::map<int, int> valToIdx;
        valToIdx[arr[n - 1]] = n - 1;

        int goodStarts = 1; // Index n - 1 is always good

        // Process backward from n - 2 down to 0
        for (int i = n - 2; i >= 0; --i) {
            
            // 1. Odd Jump: find smallest element >= arr[i]
            // lower_bound gives first element >= arr[i]
            auto hi = valToIdx.lower_bound(arr[i]);
            if (hi != valToIdx.end()) {
                higher[i] = lower[hi->second];
            }

            // 2. Even Jump: find largest element <= arr[i]
            // upper_bound gives first element > arr[i].
            // If it's exact match, lower_bound works; otherwise step back one iterator.
            auto lo = valToIdx.upper_bound(arr[i]);
            if (lo != valToIdx.begin()) {
                --lo; // Step back to get the largest value <= arr[i]
                lower[i] = higher[lo->second];
            }

            // If an odd jump from i leads to the end, i is a valid starting index
            if (higher[i]) {
                goodStarts++;
            }

            // Store/update current element index
            valToIdx[arr[i]] = i;
        }

        return goodStarts;
    }
};