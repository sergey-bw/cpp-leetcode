/**
 * 1758. Minimum Changes To Make Alternating Binary String
 * https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string
 * 
 * You are given a string s consisting only of the characters '0' and '1'.
 * In one operation, you can change any '0' to '1' or vice versa.
 * 
 * The string is called alternating if no two adjacent characters are equal.
 * For example, the string "010" is alternating, while the string "0100" is not.
 * 
 * Return the minimum number of operations needed to make s alternating
 * 
 * Example 1:
 * Input: s = "0100"
 * Output: 1
 * Explanation: If you change the last character to '1', s will be "0101", which is alternating.
 * 
 * Example 2:
 * Input: s = "10"
 * Output: 0
 * Explanation: s is already alternating.
 * 
 * Example 3:
 * Input: s = "1111"
 * Output: 2
 * Explanation: You need two operations to reach "0101" or "1010".
 * 
 * Constraints:
 * 1 <= s.length <= 10^4
 * s[i] is either '0' or '1'.
 */

#include <cassert>
#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int mismatches = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            const char expected = "01"[i & 1];
            mismatches += (s[i] != expected);
        }
        return std::min(mismatches, static_cast<int>(s.length()) - mismatches);
    }
};

void Test1() {
    assert(Solution().minOperations("0100") == 1);
}

void Test2() {
    assert(Solution().minOperations("10") == 0);
}

void Test3() {
    assert(Solution().minOperations("1111") == 2);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}