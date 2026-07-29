/**
 * 3517. Smallest Palindromic Rearrangement I
 * https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 * 
 * You are given a palindromic string s.
 * Return the lexicographically smallest palindromic permutation of s.
 * 
 * Example 1:
 *     Input: s = "z"
 *     Output: "z"
 *     Explanation: A string of only one character is already the lexicographically smallest palindrome.
 * 
 * Example 2:
 *     Input: s = "babab"
 *     Output: "abbba"
 *     Explanation: Rearranging "babab" -> "abbba" gives the smallest lexicographic palindrome.
 * 
 * Example 3:
 *     Input: s = "daccad"
 *     Output: "acddca"
 *     Explanation: Rearranging "daccad" -> "acddca" gives the smallest lexicographic palindrome.
 * 
 * Constraints:
 *     1 <= s.length <= 10^5
 *     s consists of lowercase English letters.
 *     s is guaranteed to be palindromic.
 */

#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        const int n = s.length();
        if (n < 4) {
            return s; // Строки из 1, 2 и 3 символов-палиндромов уже минимальны
        }
        
        // 1. Сортируем левую половину (от начала до середины)
        std::sort(s.begin(), s.begin() + n / 2);
        
        // 2. Сортируем правую половину в обратном порядке 
        std::sort(s.rbegin(), s.rbegin() + n / 2);
        
        return s;
    }
};

void Test1() {
    std::string s = "z";
    std::string expected = "z";
    std::string result = Solution().smallestPalindrome(s);
    assert(result == expected);
}

void Test2() {
    std::string s = "babab";
    std::string expected = "abbba";
    std::string result = Solution().smallestPalindrome(s);
    assert(result == expected);
}

void Test3() {
    std::string s = "daccad";
    std::string expected = "acddca";
    std::string result = Solution().smallestPalindrome(s);
    assert(result == expected);
}

int main() {
    Test1();
    Test2();
    Test3();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}