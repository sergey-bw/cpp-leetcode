/**
 * 1980. Find Unique Binary String
 * https://leetcode.com/problems/find-unique-binary-string
 * 
 * Given an array of strings nums containing n unique binary strings each of length n,
 * return a binary string of length n that does not appear in nums.
 * If there are multiple answers, you may return any of them.
 * 
 * Example 1:
 * Input: nums = ["01","10"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "00" would also be correct.
 * 
 * Example 2:
 * Input: nums = ["00","01"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "10" would also be correct.
 * 
 * Example 3:
 * Input: nums = ["111","011","001"]
 * Output: "101"
 * Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

 * Constraints:
 * n == nums.length
 * 1 <= n <= 16
 * nums[i].length == n
 * nums[i] is either '0' or '1'.
 * All the strings of nums are unique.
 */

#include <cassert>
#include <vector>
#include <string>
#include <algorithm>


// Диагональный аргумент Кантора
class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::string ans(nums[0].length(), '0');
        for (size_t i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans[i] = curr == '0' ? '1' : '0';
        }
        return ans;
    }
};

void Test1() {
    std::vector<std::string> vct_input({"01", "10"});
    const std::vector<std::string> vct_expected({"00", "11"});
    assert(std::find(vct_expected.cbegin(), vct_expected.cend()
        , Solution().findDifferentBinaryString(vct_input)) != vct_expected.cend());
}

void Test2() {
    std::vector<std::string> vct_input({"00", "01"});
    const std::vector<std::string> vct_expected({"10", "11"});
    assert(std::find(vct_expected.cbegin(), vct_expected.cend()
        , Solution().findDifferentBinaryString(vct_input)) != vct_expected.cend());
}

void Test3() {
    std::vector<std::string> vct_input({"111", "011", "001"});
    const std::vector<std::string> vct_expected({"000", "010", "100", "101", "110"});
    assert(std::find(vct_expected.cbegin(), vct_expected.cend()
        , Solution().findDifferentBinaryString(vct_input)) != vct_expected.cend());
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}