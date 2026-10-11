/**
 * 3548. Equal Sum Grid Partition II
 * https://leetcode.com/problems/equal-sum-grid-partition-ii
 * 
 * You are given an m x n matrix grid of positive integers. Your task is to determine
 * if it is possible to make either one horizontal or one vertical cut on the grid such that:
 *     Each of the two resulting sections formed by the cut is non-empty.
 *     The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
 *     If a cell is discounted, the rest of the section must remain connected.
 * 
 * Return true if such a partition exists; otherwise, return false.
 * 
 * Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.
 * 
 * Example 1:
 * | Input: grid = [[1,4],[2,3]]
 * | Output: true
 * | A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
 * 
 * Example 2:
 * | Input: grid = [[1,2],[3,4]]
 * | Output: true
 * | Explanation:
 * |     A vertical cut after the first column gives sums 1 + 3 = 4 and 2 + 4 = 6.
 * |     By discounting 2 from the right section (6 - 2 = 4), both sections have equal sums and remain connected. Thus, the answer is true.
 * 
 * Example 3:
 * | Input: grid = [[1,2,4],[2,3,5]]
 * | Output: false
 * | Explanation:
 * |     A horizontal cut after the first row gives 1 + 2 + 4 = 7 and 2 + 3 + 5 = 10.
 * |     By discounting 3 from the bottom section (10 - 3 = 7), both sections have equal sums, but they do not remain connected as it splits the bottom section into two parts ([2] and [5]). Thus, the answer is false.
 * 
 * Example 4:
 * | Input: grid = [[4,1,8],[3,2,6]]
 * | Output: false
 * | Explanation: No valid cut exists, so the answer is false.
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
#include <cmath>
#include <numeric>

class Solution {
public:
    bool canPartitionGrid(const std::vector<std::vector<int>>& grid) {
        if (canPartitionHorizontal(grid)) {
            return true;
        }

        const int rows = grid.size();
        const int cols = grid[0].size();
        const auto transposed_grid = [&]() {
            std::vector<std::vector<int>> res(cols, std::vector<int>(rows, 0));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    res[j][i] = grid[i][j];
                }
            }
            return res;
        }();
        return canPartitionHorizontal(transposed_grid);
    }

private:
    bool canPartitionHorizontal(const std::vector<std::vector<int>>& grid) const { 
        const int rows = grid.size();
        const int cols = grid[0].size();

        if (rows < 2) {
            return false;
        }

        // Vector
        if (cols == 1) {
            int64_t s1 = 0;
            int64_t s2 = std::accumulate(grid.begin(), grid.end(), 0LL
                , [](int64_t sum, const std::vector<int>& row) {
                    return sum + row[0];
                }
            );

            for (int i = 1; i < rows; ++i) {
                s1 += grid[i - 1][0];
                s2 -= grid[i - 1][0];
                if (
                    s1 == s2
                    || (s1 - grid[0][0] == s2)
                    || (s1 - grid[i - 1][0] == s2)
                    || (s1 == s2 - grid[i][0])
                    || (s1 == s2 - grid[rows - 1][0])
                ) {
                    return true;
                }
            }
            return false;
        }

        // Matrix
        std::vector<int> min_row(kMaxCellValue, rows);
        std::vector<int> max_row(kMaxCellValue, 0);
        std::vector<int64_t> prefix_sum_rows(rows, 0);
        for (int i = 0; i < rows; ++i) {
            prefix_sum_rows[i] = (i == 0) ? 0 : prefix_sum_rows[i - 1];
            for (int j = 0; j < cols; ++j) {
                if (min_row[grid[i][j]] == rows) {
                    min_row[grid[i][j]] = i;
                }
                max_row[grid[i][j]] = i;
                prefix_sum_rows[i] += grid[i][j];
            }
        }

        for (int i = 1; i < rows; ++i) {
            const int64_t s1 = prefix_sum_rows[i - 1];
            const int64_t s2 = prefix_sum_rows.back() - prefix_sum_rows[i - 1];
            const int64_t x = std::abs(s1 - s2);
            if (x == 0) {
                return true;
            }

            if (s1 > s2) { // В верхней части смотрим лишний элемент
                if (i == 1) { // Тонкая верхняя часть (только строка 0)
                    if (x == grid[0].front() || x == grid[0].back()) return true;
                } else { // Толстая верхняя часть
                    if (x < kMaxCellValue && min_row[x] < i) return true;
                }
            } 
            else { // В нижней части смотрим лишний элемент
                if (i == rows - 1) { // Тонкая нижняя часть (только последняя строка)
                    if (x == grid[rows - 1].front() || x == grid[rows - 1].back()) return true;
                } else { // Толстая нижняя часть
                    if (x < kMaxCellValue && max_row[x] >= i) return true;
                }
            }
        }
        return false;
    }

    const int kMaxCellValue = 100001;
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
        {1, 2},
        {3, 4}
    };
    assert(Solution().canPartitionGrid(grid) == true);
}

void Test3() {
    std::vector<std::vector<int>> grid = {
        {1, 2, 4},
        {2, 3, 5}
    };
    assert(Solution().canPartitionGrid(grid) == false);
}

void Test4() {
    std::vector<std::vector<int>> grid = {
        {4, 1, 8},
        {3, 2, 6}
    };
    assert(Solution().canPartitionGrid(grid) == false);
}

void Test5() {
    std::vector<std::vector<int>> grid = {
        {4, 8, 8},
    };
    assert(Solution().canPartitionGrid(grid) == true);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}