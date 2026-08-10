#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> getBiggestThree(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::set<int> unique_sums;

        auto add_sum = [&](int sum) {
            unique_sums.insert(sum);
            if (unique_sums.size() > 3) {
                unique_sums.erase(unique_sums.begin()); // keep top 3 largest
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Radius 0 rhombus (single cell)
                add_sum(grid[i][j]);

                // Radius r > 0 rhombus
                for (int r = 1; i - r >= 0 && i + r < m && j - r >= 0 && j + r < n; ++r) {
                    int current_sum = 0;

                    for (int k = 0; k < r; ++k) {
                        current_sum += grid[i - r + k][j + k];     // Top to Right
                        current_sum += grid[i + k][j + r - k];     // Right to Bottom
                        current_sum += grid[i + r - k][j - k];     // Bottom to Left
                        current_sum += grid[i - k][j - r + k];     // Left to Top
                    }

                    add_sum(current_sum);
                }
            }
        }

        // Return top 3 distinct sums in descending order
        return std::vector<int>(unique_sums.rbegin(), unique_sums.rend());
    }
};