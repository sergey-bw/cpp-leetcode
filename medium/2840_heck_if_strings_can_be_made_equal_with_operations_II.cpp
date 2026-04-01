/**
 * 2840. Check if Strings Can be Made Equal With Operations II
 * https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii
 * 
 * You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
 * 
 * You can apply the following operation on any of the two strings any number of times:
 *     Choose any two indices i and j such that i < j and the difference j - i is even,
 *     then swap the two characters at those indices in the string.
 * 
 * Return true if you can make the strings s1 and s2 equal, and false otherwise.
 * 
 * Example 1:
 *     Input: s1 = "abcdba", s2 = "cabdab"
 *     Output: true
 *     Explanation: We can apply the following operations on s1:
 *         - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
 *         - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
 *         - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
 * 
 * Example 2:
 *     Input: s1 = "abe", s2 = "bea"
 *     Output: false
 *     Explanation: It is not possible to make the two strings equal.
 * 
 * Constraints:
 *     n == s1.length == s2.length
 *     1 <= n <= 10^5
 *     s1 and s2 consist only of lowercase English letters.
 */

#include <cassert>
#include <string>
#include <array>

class Solution {
public:
    bool checkStrings(const std::string& s1, const std::string& s2) {
        constexpr size_t kAlphabetSize = 26;
        std::array<int, kAlphabetSize> even_freq_diff{};
        std::array<int, kAlphabetSize> odd_freq_diff{};
        
        for (size_t i = 0; i < s1.length(); ++i) {
            const int s1_index = s1[i] - 'a';
            const int s2_index = s2[i] - 'a';
            if (i & 1) {
                ++odd_freq_diff[s1_index];
                --odd_freq_diff[s2_index];
            } else {
                ++even_freq_diff[s1_index];
                --even_freq_diff[s2_index];
            }
        }

        for (size_t i = 0; i < even_freq_diff.size(); ++i) {
            if (even_freq_diff[i] != 0 || odd_freq_diff[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

void Test1() {
    assert(Solution().checkStrings("abcdba", "cabdab") == true);
}

void Test2() {
    assert(Solution().checkStrings("abe", "bea") == false);
}

int main() {
    Test1();
    Test2();
    return 0;
}