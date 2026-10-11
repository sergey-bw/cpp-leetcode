/**
 * 1536. Minimum Swaps to Arrange a Binary Grid
 * https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid
 * 
 * Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
 * A grid is said to be valid if all the cells above the main diagonal are zeros.
 * Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid
 * The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
 * 
 * Example 1:
 *  0 0 1       1 1 0       1 1 0       1 0 0
 *  1 1 0   ->  0 0 1   ->  1 0 0   ->  1 1 0
 *  1 0 0       1 0 0       0 0 1       0 0 1
 * Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
 * Output: 3
 * 
 * Example 2:
 *  0 1 1 0
 *  0 1 1 0
 *  0 1 1 0
 *  0 1 1 0
 * Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
 * Output: -1
 * Explanation: All rows are similar, swaps have no effect on the grid.
 * 
 * Example 3:
 *  1 0 0
 *  1 1 0
 *  1 1 1
 * Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
 * Output: 0
 * 
 * Constraints:
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * grid[i][j] is either 0 or 1
 */

#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<int> CountRightZeros(const std::vector<std::vector<int>>& grid) {
        std::vector<int> res;
        res.reserve(grid.size());
        for (const auto& row : grid) {
            int count_zeros = 0;
            for (auto it = row.crbegin(); it != row.crend() && *it == 0; ++it) {
                ++count_zeros;
            }
            res.push_back(count_zeros);
        }
        return res;
    }

    int minSwaps(const std::vector<std::vector<int>>& grid) {
        std::vector<int> count_zeros = CountRightZeros(grid);
        int n = static_cast<int>(count_zeros.size());
        int total_swaps = 0;
        for (int i = 0; i < n; ++i) {
            int target_row = -1;
            for (int j = i; j < n; ++j) {
                if (count_zeros[j] >= n - i - 1) {
                    target_row = j;
                    break;
                }
            }

            if (target_row == -1) {
                return -1;
            }

            for (int j = target_row; j > i; --j) {
                std::swap(count_zeros[j], count_zeros[j-1]);
                ++total_swaps;
            }
        }
        return total_swaps;
    }
};

void Test1() {
    std::vector<std::vector<int>> vct {
        {0, 0, 1},
        {1, 1, 0},
        {1, 0, 0}
    };
    assert(Solution().minSwaps(vct) == 3);
}

void Test2() {
    std::vector<std::vector<int>> vct {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0}
    };
    assert(Solution().minSwaps(vct) == -1);
}

void Test3() {
    std::vector<std::vector<int>> vct {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}
    };
    assert(Solution().minSwaps(vct) == 0);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}