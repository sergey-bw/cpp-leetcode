/**
 * 3212. Count Submatrices With Equal Frequency of X and Y
 * https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y
 * 
 * Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 *     grid[0][0]
 *     an equal frequency of 'X' and 'Y'.
 *     at least one 'X'.
 * 
 * Example 1:
 * Input: grid = [["X","Y","."],["Y",".","."]]
 * Output: 3
 * Explanation:
 *     [X* Y* .]    [X* Y* .*]    [X* Y  .]
 *     [Y  .  .]    [Y  .  . ]    [Y* .  .]
 * 
 * Example 2:
 * Input: grid = [["X","X"],["X","Y"]]
 * Output: 0
 * Explanation: No submatrix has an equal frequency of 'X' and 'Y'.
 * 
 * Example 3:
 * Input: grid = [[".","."],[".","."]]
 * Output: 0
 * Explanation: No submatrix has at least one 'X'.
 * 
 * Constraints:
 * 1 <= grid.length, grid[i].length <= 1000
 * grid[i][j] is either 'X', 'Y', or '.'.
 */

#include <cassert>
#include <vector>

class Solution {
public:
    int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        std::vector<int> col_accum(cols, 0);
        std::vector<bool> col_has_x(cols, false);
        
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            int row_accum = 0;
            bool row_has_x = false;
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 'X') {
                    col_has_x[j] = true;
                    ++col_accum[j];
                } else if (grid[i][j] == 'Y') {
                    --col_accum[j];
                }
                row_accum += col_accum[j];
                row_has_x = row_has_x || col_has_x[j];
                if (row_accum == 0 && row_has_x) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

void Test1() {
    std::vector<std::vector<char>> grid = {
        {'X', 'Y', '.'},
        {'Y', '.', '.'}
    };
    assert(Solution().numberOfSubmatrices(grid) == 3);
}

void Test2() {
    std::vector<std::vector<char>> grid = {
        {'X', 'X'},
        {'X', 'Y'}
    };
    assert(Solution().numberOfSubmatrices(grid) == 0);
}

void Test3() {
    std::vector<std::vector<char>> grid = {
        {'.', '.'},
        {'.', '.'}
    };
    assert(Solution().numberOfSubmatrices(grid) == 0);
}

void Test4() {
    std::vector<std::vector<char>> grid = {
        {'.', 'X'},
        {'.', 'Y'}
    };
    assert(Solution().numberOfSubmatrices(grid) == 1);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}