/**
 * 416. Partition Equal Subset Sum
 * https://leetcode.com/problems/partition-equal-subset-sum
 * 
 * Given an integer array nums, return true if you can partition the array into two subsets
 * such that the sum of the elements in both subsets is equal or false otherwise.
 * 
 * Example 1:
 *     Input: nums = [1,5,11,5]
 *     Output: true
 *     Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * Example 2:
 *     Input: nums = [1,2,3,5]
 *     Output: false
 *     Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * Constraints:
 *     1 <= nums.length <= 200
 *     1 <= nums[i] <= 100
 */

#include <cassert>
#include <vector>

class Solution {
public:
    bool canPartition(const std::vector<int>& nums) {
        
    }
};

void Test1() {
    std::vector<int> nums = {1, 2, 3, 5};
    assert(Solution().canPartition(nums) == true);
}

void Test2() {
    std::vector<int> nums = {1, 5, 11, 5};
    assert(Solution().canPartition(nums) == false);
}

int main() {
    Test1();
    Test2();
    return 0;
}