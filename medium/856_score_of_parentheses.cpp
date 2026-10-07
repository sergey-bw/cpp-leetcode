/**
 * 856. Score of Parentheses
 * https://leetcode.com/problems/score-of-parentheses/
 *
 * Given a balanced parentheses string s, return the score of the string.
 *
 * The score of a balanced parentheses string is based on the following rules:
 *     - "()" has score 1.
 *     - AB has score A + B, where A and B are balanced parentheses strings.
 *     - (A) has score 2 * A, where A is a balanced parentheses string.
 *
 * Example 1:
 *     Input: s = "()"
 *     Output: 1
 *
 * Example 2:
 *     Input: s = "(())"
 *     Output: 2
 *
 * Example 3:
 *     Input: s = "()()"
 *     Output: 2
 *
 * Example 4:
 *     Input: s = "(()(()))"
 *     Output: 6
 *
 * Constraints:
 *     2 <= s.length <= 50
 *     s consists only of '(' and ')'.
 *     s is a balanced parentheses string.
 */

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    int scoreOfParentheses(const std::string& s) {
        const int n = static_cast<int>(s.length());
        int score = 0;
        int depth = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }
        return score;
    }
};

void Test1() {
  const std::string s = "()";
  const int expected = 1;
  const int result = Solution().scoreOfParentheses(s);
  assert(result == expected);
}

void Test2_Nested() {
  const std::string s = "(())";
  const int expected = 2;
  const int result = Solution().scoreOfParentheses(s);
  assert(result == expected);
}

void Test3_Adjacent() {
  const std::string s = "()()";
  const int expected = 2;
  const int result = Solution().scoreOfParentheses(s);
  assert(result == expected);
}

void Test4_Mixed() {
  const std::string s = "(()(()))";
  const int expected = 6;
  const int result = Solution().scoreOfParentheses(s);
  assert(result == expected);
}

void Test5_DeepNesting() {
  const std::string s = "((()))";
  const int expected = 4;
  const int result = Solution().scoreOfParentheses(s);
  assert(result == expected);
}

int main() {
  Test1();
  Test2_Nested();
  Test3_Adjacent();
  Test4_Mixed();
  Test5_DeepNesting();

  std::cout << "All tests passed!\n";
  return 0;
}