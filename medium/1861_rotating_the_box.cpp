/**
 * 1861. Rotating the Box
 * https://leetcode.com/problems/rotating-the-box/
 * 
 * You are given an m x n matrix of characters boxGrid representing a side-view of a box.
 * Each cell of the box is one of the following:
 * - A stone '#'
 * - A stationary obstacle '*'
 * - Empty '.'
 * 
 * The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity.
 * Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box.
 * Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
 * 
 * It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.
 * 
 * Return an n x m matrix representing the box after the rotation described above.
 * 
 * Example 1:
 *     Input: boxGrid = [["#",".","#"]]
 *     Output: [[".",],
 *              ["#",],
 *              ["#"]]
 * 
 * Example 2:
 *     Input: boxGrid = [["#",".","*","."],
 *                       ["#","#","*","."]]
 *     Output: [["#","."],
 *              ["#","#"],
 *              ["*","*"],
 *              [".","."]]
 * 
 * Example 3:
 *     Input: boxGrid = [["#","#","*",".","*","."],
 *                       ["#","#","#","*",".","."],
 *                       ["#","#","#",".","#","."]]
 *     Output: [[".","#","#"],
 *              [".","#","#"],
 *              ["#","#","*"],
 *              ["#","*","."],
 *              ["#",".","*"],
 *              ["#",".","."]]
 * 
 * Constraints:
 *     m == boxGrid.length
 *     n == boxGrid[i].length
 *     1 <= m, n <= 500
 *     boxGrid[i][j] is either '#', '*', or '.'.
 */

#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
        // Гравитация (Имитация на входном векторе)
        for (auto& row : boxGrid) {
            auto drop_it = row.rbegin();
            for (auto it = row.rbegin(); it != row.rend(); ++it) {
                if (*it == '#') {
                    std::swap(*drop_it, *it);
                    ++drop_it;
                } else if (*it == '*') {
                    drop_it = it + 1;
                }
            }
        }

        // Поворот по часовой стрелке
        const int rows = static_cast<int>(boxGrid.size());
        const int cols = static_cast<int>(boxGrid[0].size());
        std::vector<std::vector<char>> res(cols, std::vector<char>(rows, '?'));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res[j][rows - i - 1] = boxGrid[i][j];
            }
        }
        return res;
    }
};

void Test1() {
    std::vector<std::vector<char>> box_grid = {
        {'#', '.', '#'}
    };
    std::vector<std::vector<char>> expected = {
        {'.'},
        {'#'},
        {'#'}
    };
    assert(Solution().rotateTheBox(box_grid) == expected);
}

void Test2() {
    std::vector<std::vector<char>> box_grid = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };
    std::vector<std::vector<char>> expected = {
        {'#', '.'},
        {'#', '#'},
        {'*', '*'},
        {'.', '.'}
    };
    assert(Solution().rotateTheBox(box_grid) == expected);
}

void Test3() {
    std::vector<std::vector<char>> box_grid = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}
    };
    std::vector<std::vector<char>> expected = {
        {'.', '#', '#'},
        {'.', '#', '#'},
        {'#', '#', '*'},
        {'#', '*', '.'},
        {'#', '.', '*'},
        {'#', '.', '.'}
    };
    assert(Solution().rotateTheBox(box_grid) == expected);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}