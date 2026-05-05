/**
 * 48. Rotate Image
 * https://leetcode.com/problems/rotate-image
 * 
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 * 
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * 
 * Example 1:
 *     [1, 2, 3]        [7, 4, 1]
 *     [4, 5, 6]   =>   [8, 5, 2]
 *     [7, 8, 9]        [9, 6, 3]
 *     Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *     Output: [[7,4,1],[8,5,2],[9,6,3]]
 * 
 * Example 2:
 *     Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 *     Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * Constraints:
 *     n == matrix.length == matrix[i].length
 *     1 <= n <= 20
 *     -1000 <= matrix[i][j] <= 1000
 */

#include <cassert>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        assert(!matrix.empty() && matrix.size() == matrix[0].size());
        const auto n = matrix.size();

        // 1. Транспонирование матрицы
        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. Отражение строк матрицы
        for (auto& row : matrix) {
            std::reverse(row.begin(), row.end());
        }
    }
};

void Test1() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    std::vector<std::vector<int>> result = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3},
    };
    assert(matrix == result);
}

void Test2() {
    std::vector<std::vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    std::vector<std::vector<int>> result = {
        {15, 13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7, 10, 11}
    };
    assert(matrix == result);
}

int main() {
    Test1();
    Test2();
    return 0;
}