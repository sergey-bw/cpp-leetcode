/**
 * 2078. Two Furthest Houses With Different Colors
 * https://leetcode.com/problems/two-furthest-houses-with-different-colors
 * 
 * There are n houses evenly lined up on the street, and each house is beautifully painted.
 * You are given a 0-indexed integer array colors of length n, where colors[i] represents 
 * the color of the i-th house.
 * 
 * Return the maximum distance between two houses with different colors.
 * 
 * The distance between the i-th and j-th houses is abs(i - j), where abs(x) is the 
 * absolute value of x.
 * 
 * It is guaranteed that there will always be at least two houses with different colors.
 * 
 * Example 1:
 *     Input: colors = [1,1,1,6,1,1,1]
 *     Output: 3
 *     Explanation: In the above array, color 1 is one color, and color 6 is another.
 *     The furthest two houses with different colors are house 0 and house 3.
 *     House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
 *     Note that houses 3 and 6 can also produce the optimal answer.
 * 
 * Example 2:
 *     Input: colors = [1,8,3,8,3]
 *     Output: 4
 *     Explanation: The furthest two houses with different colors are house 0 and house 4.
 *     House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
 * 
 * Example 3:
 *     Input: colors = [0,1]
 *     Output: 1
 *     Explanation: The furthest two houses with different colors are house 0 and house 1.
 *     House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
 * 
 * Constraints:
 *     n == colors.length
 *     2 <= n <= 100
 *     0 <= colors[i] <= 100
 *     Test data are generated such that at least two houses have different colors.
 */

#include <cassert>
#include <vector>

class Solution {
public:
    int maxDistance(const std::vector<int>& colors) {
        const int n = static_cast<int>(colors.size());
        
        int left = 0;
        while (colors[left] == colors.back()) {
            ++left;
        }
        
        int right = n - 1;
        while (colors[right] == colors.front()) {
            --right;
        }
        
        return std::max(n - 1 - left, right);
    }
};

void Test1() {
    std::vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
    assert(Solution().maxDistance(colors) == 3);
}

void Test2() {
    std::vector<int> colors = {1, 8, 3, 8, 3};
    assert(Solution().maxDistance(colors) == 4);
}

void Test3() {
    std::vector<int> colors = {0, 1};
    assert(Solution().maxDistance(colors) == 1);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}