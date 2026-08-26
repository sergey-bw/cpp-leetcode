/**
 * 2904. Shortest and Lexicographically Smallest Beautiful String
 * https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
 *
 * You are given a binary string s and a positive integer k.
 *
 * A substring of s is beautiful if it contains exactly k occurrences of '1'.
 *
 * Let len be the length of the shortest beautiful substring.
 * Return the lexicographically smallest beautiful substring of length len.
 *
 * If s does not contain a beautiful substring, return an empty string.
 *
 * For two strings of the same length, a is lexicographically smaller than b
 * if, at the first position where they differ, a has a smaller character than b.
 *
 * Example 1:
 *     Input: s = "100011001", k = 3
 *     Output: "11001"
 *
 * Example 2:
 *     Input: s = "1011", k = 2
 *     Output: "11"
 *
 * Example 3:
 *     Input: s = "000", k = 1
 *     Output: ""
 *
 * Constraints:
 *     1 <= s.length <= 100
 *     s consists only of '0' and '1'.
 *     1 <= k <= s.length
 */

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string shortestBeautifulSubstring(const std::string& s, int k) {
        const int n = s.length();
        if (n < k) {
            return "";
        }

        int left = 0;
        while (left!= n && s[left] == 0) {
            ++left;
        }
        int right = left;

        int best_left = 0;
        int best_right = 0;
        int ones_count = 0;
        int best_len = n + 1;

        while (right < n - 1) {
            if (ones_count == k) {
                int curr_len = left - right + 1;
                if (curr_len < best_len) {
                    best_left = left;
                    best_right = right;
                    best_len = curr_len;
                } else if (curr_len == best_len) {
                    
                }
            }

            if (ones_count < k) {
                ++right;
            } else {
                ++left;
            } 

        }

        return "";
    }
};

void Test1() {
    const std::string s = "100011001";
    const int k = 3;
    const std::string expected = "11001";

    const std::string result = Solution().shortestBeautifulSubstring(s, k);

    assert(result == expected);
}

void Test2() {
    const std::string s = "1011";
    const int k = 2;
    const std::string expected = "11";

    const std::string result = Solution().shortestBeautifulSubstring(s, k);

    assert(result == expected);
}

void Test3_NoBeautifulSubstring() {
    const std::string s = "000";
    const int k = 1;
    const std::string expected = "";

    const std::string result = Solution().shortestBeautifulSubstring(s, k);

    assert(result == expected);
}

void Test4_OneOneRequired() {
    const std::string s = "00100";
    const int k = 1;
    const std::string expected = "1";

    const std::string result = Solution().shortestBeautifulSubstring(s, k);

    assert(result == expected);
}

int main() {
    Test1();
    Test2();
    Test3_NoBeautifulSubstring();
    Test4_OneOneRequired();

    std::cout << "All tests passed!\n";
    return 0;
}