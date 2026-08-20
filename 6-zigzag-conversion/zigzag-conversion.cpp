#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Base case: no zigzag possible if only 1 row or string is shorter than rows
        if (numRows <= 1 || s.length() <= static_cast<size_t>(numRows)) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction when reaching top or bottom boundary
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};