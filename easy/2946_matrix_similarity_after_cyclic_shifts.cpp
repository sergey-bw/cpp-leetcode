/**
 * 2946. Matrix Similarity After Cyclic Shifts
 * https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts
 * 
 * You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
 * 
 * The following proccess happens k times:
 *     Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
 *         [1, 2, 3]    =>    [2, 3, 1]
 *             <- <-
 *          ------>
 *     Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.
 *         [1, 2, 3]    =>    [3, 1, 2]
 *          -> ->
 *          <------
 * 
 * Return true if the final modified matrix after k steps is identical to the original matrix,
 * and false otherwise.
 * 
 * Example 1:
 *     Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
 *     Output: false
 *     Explanation: In each step left shift is applied to rows 0 and 2 (even indices),
 *     and right shift to row 1 (odd index).
 *         [1, 2, 3]      [2, 3, 1]      [3, 1, 2]      [1, 2, 3]      [2, 3, 1]
 *         [4, 5, 6]  =>  [6, 4, 5]  =>  [5, 6, 4]  =>  [4, 5, 6]  =>  [6, 4, 5]
 *         [7, 8, 9]      [8, 9, 7]      [9, 7, 8]      [7, 8, 9]      [8, 9, 7]
 * 
 * Example 2:
 *     Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
 *     Output: true
 *     Explanation:
 *         [1, 2, 1, 2]      [2, 1, 2, 1]      [1, 2, 1, 2]
 *         [5, 5, 5, 5]  =>  [5, 5, 5, 5]  =>  [5, 5, 5, 5]
 *         [6, 3, 6, 3]      [3, 6, 3, 6]      [6, 3, 6, 3]
 * 
 * Example 3:
 *     Input: mat = [[2,2],[2,2]], k = 3
 *     Output: true
 *     Explanation: As all the values are equal in the matrix, even after performing
 *     cyclic shifts the matrix will remain the same.
 * 
 * Constraints:
 *     1 <= mat.length <= 25
 *     1 <= mat[i].length <= 25
 *     1 <= mat[i][j] <= 25
 *     1 <= k <= 50
 */

#include <cassert>
#include <vector>

class Solution {
public:
    bool areSimilar(std::vector<std::vector<int>>& mat, int k) {
        const int rows = mat.size();
        const int cols = mat[0].size();

        k = k % cols;
        if (k == 0) {
            return true;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] != mat[i][(j + k + cols) % cols]) {
                    return false;
                }
            }
            k = -k;
        }
        return true;
    }
};

void Test1() {
    std::vector<std::vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    assert(Solution().areSimilar(mat, 4) == false);
}

void Test2() {
    std::vector<std::vector<int>> mat = {
        {1, 2, 1, 2},
        {5, 5, 5, 5},
        {6, 3, 6, 3}
    };
    assert(Solution().areSimilar(mat, 2) == true);
}

void Test3() {
    std::vector<std::vector<int>> mat = {
        {2, 2},
        {2, 2}
    };
    assert(Solution().areSimilar(mat, 3) == true);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}