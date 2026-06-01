/**
 * 2144. Minimum Cost of Buying Candies With Discount
 * https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 * 
 * You are given an integer array cost, where cost[i] is the cost of the i-th candy.
 * You can buy any two candies and get a third candy for free, as long as the cost
 * of the free candy is less than or equal to the minimum cost of the two candies
 * you bought.
 * 
 * Return the minimum cost of buying all the candies.
 * 
 * Example 1:
 *     Input: cost = [1,2,3]
 *     Output: 5
 *     Explanation: We buy the candies with costs 2 and 3, and get the candy
 *     with cost 1 for free.
 * 
 * Example 2:
 *     Input: cost = [6,5,7,9,2,2]
 *     Output: 23
 *     Explanation: We buy the candies with costs 9 and 7, and get the candy
 *     with cost 6 for free. Then we buy the candies with costs 5 and 2, and
 *     get the last candy with cost 2 for free.
 * 
 * Example 3:
 *     Input: cost = [5,5]
 *     Output: 10
 * 
 * Constraints:
 *     1 <= cost.length <= 100
 *     1 <= cost[i] <= 100
 */

#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        int result_cost = 0;
        for (size_t i = 0; i < cost.size(); ++i) {
            if (i % 3 != 2) {
                result_cost += cost[i];
            }
        }
        return result_cost;
    }
};

void Test1() {
    std::vector<int> cost = {1, 2, 3};
    assert(Solution().minimumCost(cost) == 5);
}

void Test2() {
    std::vector<int> cost = {6, 5, 7, 9, 2, 2};
    assert(Solution().minimumCost(cost) == 23);
}

void Test3() {
    std::vector<int> cost = {5, 5};
    assert(Solution().minimumCost(cost) == 10);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}