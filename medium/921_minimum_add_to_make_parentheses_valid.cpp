/**
 * 921. Minimum Add to Make Parentheses Valid
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 *
 * A parentheses string is valid if and only if:
 *     - It is the empty string.
 *     - It can be written as AB (A concatenated with B), where A and B
 *       are valid strings.
 *     - It can be written as (A), where A is a valid string.
 *
 * You are given a parentheses string s.
 *
 * In one move, you can insert a parenthesis at any position of the string.
 *
 * Return the minimum number of moves required to make s valid.
 *
 * Example 1:
 *     Input: s = "())"
 *     Output: 1
 *
 * Example 2:
 *     Input: s = "((("
 *     Output: 3
 *
 * Constraints:
 *     1 <= s.length <= 1000
 *     s[i] is either '(' or ')'.
 */

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    int minAddToMakeValid(const std::string& s) {
        int need_close = 0;
        int need_open = 0;
        for (const char c : s) {
            if (c == '(') {
                ++need_close;
            }
            else if (need_close > 0) {
                --need_close;
            } else {
                ++need_open;
            }
        }
        return need_open + need_close;
    }
};

void Test1() {
    const std::string s = "())";
    const int expected = 1;

    const int result = Solution().minAddToMakeValid(s);

    assert(result == expected);
}

void Test2() {
    const std::string s = "(((";
    const int expected = 3;

    const int result = Solution().minAddToMakeValid(s);

    assert(result == expected);
}

void Test3_AlreadyValid() {
    const std::string s = "(()())";
    const int expected = 0;

    const int result = Solution().minAddToMakeValid(s);

    assert(result == expected);
}

void Test4_SingleClosingParenthesis() {
    const std::string s = ")";
    const int expected = 1;

    const int result = Solution().minAddToMakeValid(s);

    assert(result == expected);
}

void Test5_ReversedPair() {
    const std::string s = ")(";
    const int expected = 2;

    const int result = Solution().minAddToMakeValid(s);

    assert(result == expected);
}

int main() {
    Test1();
    Test2();
    Test3_AlreadyValid();
    Test4_SingleClosingParenthesis();
    Test5_ReversedPair();

    std::cout << "All tests passed!\n";
    return 0;
}