/**
 * 1833. Maximum Ice Cream Bars
 * https://leetcode.com/problems/maximum-ice-cream-bars/
 * 
 * It is a sweltering summer day, and a boy wants to buy some ice cream bars.
 * At the store, there are n ice cream bars. You are given an array costs of length n, 
 * where costs[i] is the price of the i-th ice cream bar in coins. 
 * The boy initially has coins coins to spend, and he wants to buy as many ice cream 
 * bars as possible. 
 * 
 * Return the maximum number of ice cream bars the boy can buy with coins coins.
 * Note: The boy can buy the ice cream bars in any order.
 * 
 * Example 1:
 *     Input: costs = [1,3,2,4,1], coins = 7
 *     Output: 4
 * 
 * Example 2:
 *     Input: costs = [10,6,8,7,7,8], coins = 5
 *     Output: 0
 * 
 * Example 3:
 *     Input: costs = [1,6,3,1,2,5], coins = 20
 *     Output: 6
 * 
 * Constraints:
 *     costs.length == n
 *     1 <= n <= 10^5
 *     1 <= costs[i] <= 10^5
 *     1 <= coins <= 10^8
 */

#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxIceCream(const vector<int>& costs, int coins) {
        const int kMaxCost = 100000;
        
        // Сортировка подсчетом
        vector<int> count(kMaxCost + 1, 0);
        for (const int cost : costs) {
            ++count[cost];
        }

        int max_ice_creams = 0;
        for (int price = 1; price <= kMaxCost; ++price) {
            if (count[price] == 0) {
                continue;
            }
            
            if (price > coins) {
                break;
            }

            int take = std::min(count[price], coins / price);
            max_ice_creams += take;
            coins -= take * price;
        }
        return max_ice_creams;
    }
};

void Test1() {
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    int result = Solution().maxIceCream(costs, coins);
    assert(result == 4);
}

void Test2() {
    vector<int> costs = {10, 6, 8, 7, 7, 8};
    int coins = 5;
    int result = Solution().maxIceCream(costs, coins);
    assert(result == 0);
}

void Test3() {
    vector<int> costs = {1, 6, 3, 1, 2, 5};
    int coins = 20;
    int result = Solution().maxIceCream(costs, coins);
    assert(result == 6);
}

int main() {
    Test1();
    Test2();
    Test3();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}