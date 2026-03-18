/**
 * 1582. Special Positions in a Binary Matrix
 * https://leetcode.com/problems/special-positions-in-a-binary-matrix
 * 
 * Given an m x n binary matrix mat, return the number of special positions in mat.
 * 
 * A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
 * 
 * Example 1:
 *  1 0 0
 *  0 0 1*
 *  1 0 0
 * Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
 * Output: 1
 * Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
 * 
 * Example 2:
 *  1* 0 0
 *  0 1* 0
 *  0 0 1*
 * Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 * 
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * mat[i][j] is either 0 or 1
 */

#include <cassert>
#include <vector>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        size_t rows = mat.size();
        size_t cols = mat[0].size();
        std::vector<int> row_count_ones(rows, 0);
        std::vector<int> col_count_ones(cols, 0);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    ++row_count_ones[i];
                    ++col_count_ones[j];
                }
            }
        }
        
        int res = 0;
        for (size_t i = 0; i < rows; ++i) {
            if (row_count_ones[i] != 1) {
                continue;
            }
            for (size_t j = 0; j < cols; ++j) {
                if (mat[i][j] == 1 && col_count_ones[j] == 1) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

void Test1() {
    std::vector<std::vector<int>> vct{
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };
    assert(Solution().numSpecial(vct) == 1);
}

void Test2() {
    std::vector<std::vector<int>> vct{
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    assert(Solution().numSpecial(vct) == 3);
}

int main() {
    Test1();
    Test2();
    return 0;
}