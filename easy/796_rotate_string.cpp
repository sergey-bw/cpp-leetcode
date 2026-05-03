/**
 * 796. Rotate String
 * https://leetcode.com/problems/rotate-string
 * 
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 * 
 * Example 1:
 *     Input: s = "abcde", goal = "cdeab"
 *     Output: true
 * 
 * Example 2:
 *     Input: s = "abcde", goal = "abced"
 *     Output: false
 * 
 * Constraints:
 *     1 <= s.length, goal.length <= 100
 *     s and goal consist of lowercase English letters.
 */

#include <cassert>
#include <string>

class Solution {
public:
    bool rotateString(const std::string& s, const std::string& goal) {
        return s.length() == goal.length() && (s + s).find(goal) != std::string::npos;
    }
};

void Test1() {
    std::string str = "abcde";
    std::string goal = "cdeab";
    assert(Solution().rotateString(str, goal) == true);
}

void Test2() {
    std::string str = "abcde";
    std::string goal = "abced";
    assert(Solution().rotateString(str, goal) == false);
}

int main() {
    Test1();
    Test2();
    return 0;
}