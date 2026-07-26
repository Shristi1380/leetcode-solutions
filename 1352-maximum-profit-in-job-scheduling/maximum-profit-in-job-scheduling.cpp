struct Job {
    int start;
    int end;
    int profit;
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);

        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        // Step 1: Sort jobs based on their end times
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.end < b.end;
        });

        // dp[i] stores the max profit using a subset of the first i jobs
        vector<int> dp(n, 0);
        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; ++i) {
            // Choice 1: Don't take current job
            int inclProfit = jobs[i].profit;

            // Choice 2: Take current job + max profit from non-overlapping jobs before it
            // Binary search to find the latest job that ends <= jobs[i].start
            int l = 0, r = i - 1;
            int lastCompatible = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (jobs[mid].end <= jobs[i].start) {
                    lastCompatible = mid;
                    l = mid + 1; // Try to find a later compatible job
                } else {
                    r = mid - 1;
                }
            }

            if (lastCompatible != -1) {
                inclProfit += dp[lastCompatible];
            }

            // Max of including or excluding current job
            dp[i] = max(dp[i - 1], inclProfit);
        }

        return dp[n - 1];
    }
};