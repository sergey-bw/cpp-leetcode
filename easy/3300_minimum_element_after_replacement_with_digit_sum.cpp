/**
 * 3300. Minimum Element After Replacement With Digit Sum
 * https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
 * 
 * You are given an integer array nums.
 * 
 * You replace each element in nums with the sum of its digits.
 * 
 * Return the minimum element in nums after all replacements.
 * 
 * Example 1:
 *     Input: nums = [10,12,13,14]
 *     Output: 1
 *     Explanation:
 *     nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
 * 
 * Example 2:
 *     Input: nums = [1,2,3,4]
 *     Output: 1
 *     Explanation:
 *     nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.
 * 
 * Example 3:
 *     Input: nums = [999,19,199]
 *     Output: 10
 *     Explanation:
 *     nums becomes [27, 10, 19] after all replacements, with minimum element 10.
 * 
 * Constraints:
 *     1 <= nums.length <= 100
 *     1 <= nums[i] <= 10^4
 */

#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int minElement(const std::vector<int>& nums) {
        int min_sum = std::numeric_limits<int>::max();
        for (int num : nums) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            min_sum = std::min(sum, min_sum);
        }
        return min_sum;
    }
};

void Test1() {
    const std::vector<int> nums = {10, 12, 13, 14};
    assert(Solution().minElement(nums) == 1);
}

void Test2() {
    const std::vector<int> nums = {1, 2, 3, 4};
    assert(Solution().minElement(nums) == 1);
}

void Test3() {
    const std::vector<int> nums = {999, 19, 199};
    assert(Solution().minElement(nums) == 10);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}