/**
 * 3546. Equal Sum Grid Partition I
 * https://leetcode.com/problems/equal-sum-grid-partition-i
 * 
 * You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
 * Each of the two resulting sections formed by the cut is non-empty.
 * The sum of the elements in both sections is equal.
 * Return true if such a partition exists; otherwise return false.
 * 
 * Example 1:
 * | Input: grid = [[1,4],[2,3]]
 * | Output: true
 * | Explanation: A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
 * 
 * Example 2:
 * | Input: grid = [[1,3],[2,4]]
 * | Output: false
 * | Explanation: No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.
 * 
 * Constraints:
 *     1 <= m == grid.length <= 10^5
 *     1 <= n == grid[i].length <= 10^5
 *     2 <= m * n <= 10^5
 *     1 <= grid[i][j] <= 10^5
 */

#include <cassert>
#include <vector>
#include <cstdint>

class Solution {
public:
    bool canPartitionGrid(const std::vector<std::vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        std::vector<int64_t> rows_sums(rows);
        std::vector<int64_t> cols_sums(cols);
        int64_t total_sum = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rows_sums[i] += grid[i][j];
                cols_sums[j] += grid[i][j];
                total_sum += grid[i][j];
            }
        }

        if (total_sum % 2 != 0) {
            return false;
        }

        const int64_t half_sum = total_sum / 2;

        // Горизонтальный срез (по строкам)
        int64_t current_sum = 0;
        for (int i = 0; i < rows - 1; ++i) {
            current_sum += rows_sums[i];
            if (current_sum == half_sum) return true;
            if (current_sum > half_sum) break;
        }
        
        // Вертикальный срез (по столбцам)
        current_sum = 0;
        for (int j = 0; j < cols - 1; ++j) {
            current_sum += cols_sums[j];
            if (current_sum == half_sum) return true;
            if (current_sum > half_sum) break;
        }

        return false;
    }
};

void Test1() {
    std::vector<std::vector<int>> grid = {
        {1, 4},
        {2, 3}
    };
    assert(Solution().canPartitionGrid(grid) == true);
}

void Test2() {
    std::vector<std::vector<int>> grid = {
        {1, 3},
        {2, 4}
    };
    assert(Solution().canPartitionGrid(grid) == false);
}

void Test3() {
    std::vector<std::vector<int>> grid = {
        {1, 3},
    };
    assert(Solution().canPartitionGrid(grid) == false);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}