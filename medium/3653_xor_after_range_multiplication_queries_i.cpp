/**
 * 3653. XOR After Range Multiplication Queries I
 * https://leetcode.com/problems/xor-after-range-multiplication-queries-i
 * 
 * You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [l[i], r[i], k[i], v[i]].
 * 
 * For each query, you must apply the following operations in order:
 *     Set idx = l[i].
 *     While idx <= ri:
 *         Update: nums[idx] = (nums[idx] * v[i]) % (10^9 + 7)
 *         Set idx += ki.
 * 
 * Return the bitwise XOR of all elements in nums after processing all queries.
 * 
 * Example 1:
 *     Input: nums = [1,1,1], queries = [[0,2,1,4]]
 *     Output: 4
 *     Explanation:
 *         A single query [0, 2, 1, 4] multiplies every element from index 0 through index 2 by 4.
 *         The array changes from [1, 1, 1] to [4, 4, 4].
 *         The XOR of all elements is 4 ^ 4 ^ 4 = 4.
 * 
 * Example 2:
 *     Input: nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]
 *     Output: 31
 *     Explanation:
 *         The first query [1, 4, 2, 3] multiplies the elements at indices 1 and 3 by 3, transforming the array to [2, 9, 1, 15, 4].
 *         The second query [0, 2, 1, 2] multiplies the elements at indices 0, 1, and 2 by 2, resulting in [4, 18, 2, 15, 4].
 *         Finally, the XOR of all elements is 4 ^ 18 ^ 2 ^ 15 ^ 4 = 31.​​​​​​​
 * 
 * Constraints:
 *     1 <= n == nums.length <= 10^3
 *     1 <= nums[i] <= 10^9
 *     1 <= q == queries.length <= 10^3
 *     queries[i] = [l[i], r[i], k[i], v[i]]
 *     0 <= l[i] <= r[i] < n
 *     1 <= k[i] <= n
 *     1 <= v[i] <= 10^5
 */

#include <cassert>
#include <vector>

class Solution {
public:
    int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        long long kMOD = 1e9 + 7;
        for (const auto& query : queries) {
            const int l = query[0];
            const int r = query[1];
            const int k = query[2];
            const int v = query[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % kMOD;
            }
        }
        int res = 0;
        for (auto x : nums) {
            res ^= x;
        }
        return res;
    }
};

void Test1() {
    std::vector<int> nums = {1, 1, 1};
    std::vector<std::vector<int>> queries = {
        {0,2,1,4}
    };
    assert(Solution().xorAfterQueries(nums, queries) == 4);
}

void Test2() {
    std::vector<int> nums = {2, 3, 1, 5, 4};
    std::vector<std::vector<int>> queries = {
        {1, 4, 2, 3},
        {0, 2, 1, 2}
    };
    assert(Solution().xorAfterQueries(nums, queries) == 31);
}

int main() {
    Test1();
    Test2();
    return 0;
}