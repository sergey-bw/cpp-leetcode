/**
 * 3121. Count the Number of Special Characters II
 * https://leetcode.com/problems/count-the-number-of-special-characters-ii/
 * 
 * You are given a string word. A letter is called special if it appears both
 * in lowercase and uppercase in word, and every lowercase occurrence of that
 * letter appears before the first uppercase occurrence of that letter.
 * 
 * Return the number of special letters in word.
 * 
 * Example 1:
 *     Input: word = "aaAbcBC"
 *     Output: 3
 *     Explanation: The special characters in word are 'a', 'b', and 'c'.
 *                  For 'a', all 'a's appear before the first 'A'.
 * 
 * Example 2:
 *     Input: word = "abc"
 *     Output: 0
 *     Explanation: No character in word appears in uppercase.
 * 
 * Example 3:
 *     Input: word = "AbBCab"
 *     Output: 0
 *     Explanation: There are no special characters in word.
 *                  For 'a', 'a' appears after 'A'.
 *                  For 'b', 'b' appears after 'B'.
 * 
 * Constraints:
 *     1 <= word.length <= 2 * 10^5
 *     word consists of only lowercase and uppercase English letters.
 */

#include <cassert>
#include <string>
#include <vector>
#include <cctype>
#include <cstdint>
#include <bitset>

class Solution {
public:
    int numberOfSpecialChars(const std::string& word) {
        uint32_t upper_bit_mask = 0;
        uint32_t lower_bit_mask = 0;
        uint32_t invalid_mask = 0;

        for (const char c : word) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                upper_bit_mask |= 1u << (c - 'A');
            } else {
                const int bit = 1u << (c - 'a');
                lower_bit_mask |= bit;
                invalid_mask |= (upper_bit_mask & bit);
            }
        }
        return std::bitset<32>(upper_bit_mask & lower_bit_mask & ~invalid_mask).count();
    }
};

void Test1() {
    assert(Solution().numberOfSpecialChars("aaAbcBC") == 3);
}

void Test2() {
    assert(Solution().numberOfSpecialChars("abc") == 0);
}

void Test3() {
    assert(Solution().numberOfSpecialChars("AbBCab") == 0);
}

void Test4() {
    assert(Solution().numberOfSpecialChars("aAa") == 0); // строчная после заглавной
}

void Test5() {
    assert(Solution().numberOfSpecialChars("aA") == 1);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}