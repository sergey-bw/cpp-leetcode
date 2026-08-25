/**
 * 3718. Smallest Missing Multiple of K
 * https://leetcode.com/problems/smallest-missing-multiple-of-k/
 *
 * Given an integer array nums and an integer k, return the smallest positive
 * multiple of k that is missing from nums.
 *
 * A multiple of k is a positive integer divisible by k.
 *
 * Example 1:
 *     Input: nums = [8, 2, 3, 4, 6], k = 2
 *     Output: 10
 *
 * Example 2:
 *     Input: nums = [1, 4, 7, 10, 15], k = 5
 *     Output: 5
 *
 * Constraints:
 *     1 <= nums.length <= 100
 *     1 <= nums[i] <= 100
 *     1 <= k <= 100
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <array>

class Solution {
public:
    int missingMultiple(const std::vector<int>& nums, int k) {
        constexpr int kMaxNumValue = 100;
        std::array<bool, kMaxNumValue + 1> is_present{};
        for (int num : nums) {
            is_present[num] = true;
        }

        int multiple = k;
        while (multiple <= kMaxNumValue && is_present[multiple]) {
            multiple += k;
        }
        return multiple;
    }
};

void Test1() {
    const std::vector<int> nums = {8, 2, 3, 4, 6};
    const int k = 2;
    const int expected = 10;

    const int result = Solution().missingMultiple(nums, k);

    assert(result == expected);
}

void Test2() {
    const std::vector<int> nums = {1, 4, 7, 10, 15};
    const int k = 5;
    const int expected = 5;

    const int result = Solution().missingMultiple(nums, k);

    assert(result == expected);
}

void Test3() {
    const std::vector<int> nums = {3, 6, 9, 12};
    const int k = 3;
    const int expected = 15;

    const int result = Solution().missingMultiple(nums, k);

    assert(result == expected);
}

int main() {
    Test1();
    Test2();
    Test3();

    std::cout << "All tests passed!\n";
    return 0;
}