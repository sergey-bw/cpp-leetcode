/**
 * 3120. Count the Number of Special Characters I
 * https://leetcode.com/problems/count-the-number-of-special-characters-i/
 * 
 * You are given a string word. A letter is called special if it appears both
 * in lowercase and uppercase in word.
 * 
 * Return the number of special letters in word.
 * 
 * Example 1:
 *     Input: word = "aaAbcBC"
 *     Output: 3
 *     Explanation: The special characters in word are 'a', 'b', and 'c'.
 * 
 * Example 2:
 *     Input: word = "abc"
 *     Output: 0
 *     Explanation: No character in word appears in uppercase.
 * 
 * Example 3:
 *     Input: word = "abBCab"
 *     Output: 1
 *     Explanation: The only special character in word is 'b'.
 * 
 * Constraints:
 *     1 <= word.length <= 50
 *     word consists of only lowercase and uppercase English letters.
 */

#include <cassert>
#include <array>
#include <string>
#include <bitset>
#include <cstdint>

class Solution {
public:
    int numberOfSpecialChars(const std::string& word) {
        constexpr size_t kSize = 26;
        std::array<bool, kSize> has_upper{0};
        std::array<bool, kSize> has_lower{0};
        for (const char c : word) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                has_upper[c - 'A'] = 1;
            } else {
                has_lower[c - 'a'] = 1;
            }
        }
 
        int count = 0;
        for (size_t i = 0; i < kSize; ++i) {
            if (has_upper[i] && has_lower[i]) {
                ++count;
            }
        }
        return count;
    }

    int numberOfSpecialCharsV2(const std::string& word) { // bit_mask
        uint32_t upper_bit_mask = 0;
        uint32_t lower_bit_mask = 0;

        for (const char c : word) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                upper_bit_mask |= 1u << (c - 'A');
            } else {
                lower_bit_mask |= 1u << (c - 'a');
            }
        }
 
        uint32_t bit_mask = upper_bit_mask & lower_bit_mask;
        return std::bitset<32>(bit_mask).count();
    }
};

void Test1() {
    assert(Solution().numberOfSpecialChars("aaAbcBC") == 3);
}

void Test2() {
    assert(Solution().numberOfSpecialChars("abc") == 0);
}

void Test3() {
    assert(Solution().numberOfSpecialChars("abBCab") == 1);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}