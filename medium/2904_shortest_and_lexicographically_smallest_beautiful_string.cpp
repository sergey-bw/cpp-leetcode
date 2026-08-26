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
        const int n = static_cast<int>(s.length());
        int best_left = 0;
        int best_len = n + 1;
        int ones_count = 0;

        for (int left = 0, right = 0; right < n; ++right) {
            if (s[right] == '1') {
                ++ones_count;
            }

            if (ones_count != k) {
                continue;
            }

            while (s[left] == '0') {
                ++left;
            }

            const int candidate_len = right - left + 1;
            const bool is_better =
                candidate_len < best_len ||
                (candidate_len == best_len &&
                 s.compare(left, candidate_len, s, best_left, best_len) < 0);

            if (is_better) {
                best_left = left;
                best_len = candidate_len;
            }

            ++left;
            --ones_count;  // Удаляем ведущую '1', чтобы продолжить поиск.
        }

        return best_len > n ? "" : s.substr(best_left, best_len);
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