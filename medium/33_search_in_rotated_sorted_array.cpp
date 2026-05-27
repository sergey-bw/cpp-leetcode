/**
 * 33. Search in Rotated Sorted Array
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 * There is an integer array nums sorted in ascending order (with distinct values).
 * 
 * Prior to being passed to your function, nums is possibly rotated at an unknown
 * pivot index k (1 <= k < nums.length) such that the resulting array is
 * [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target, return the
 * index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 *     Input: nums = [4,5,6,7,0,1,2], target = 0
 *     Output: 4
 * 
 * Example 2:
 *     Input: nums = [4,5,6,7,0,1,2], target = 3
 *     Output: -1
 * 
 * Example 3:
 *     Input: nums = [1], target = 0
 *     Output: -1
 * 
 * Constraints:
 *     1 <= nums.length <= 5000
 *     -10^4 <= nums[i] <= 10^4
 *     All values of nums are unique.
 *     nums is an ascending array that is possibly rotated.
 *     -10^4 <= target <= 10^4
 */

#include <cassert>
#include <vector>

class Solution {
public:
    int SearchSortedStartIndex(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (nums[left] > nums[right]) {
            int mid = left + (right - left) / 2; // Защита от переполнения
            if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int search(const std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        // 1. Найдем стартовый индекс сортированного массива
        int sorted_start = SearchSortedStartIndex(nums);

        // 2. Бинарный поиск в отсортированном массиве со смещением
        const int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            const int sorted_mid = (mid + sorted_start) % n;
            if (target == nums[sorted_mid]) {
                return sorted_mid;
            }
            if (target < nums[sorted_mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

void Test1() {
    const std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(Solution().search(nums, 0) == 4);
}

void Test2() {
    const std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(Solution().search(nums, 3) == -1);
}

void Test3() {
    const std::vector<int> nums = {1};
    assert(Solution().search(nums, 0) == -1);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}