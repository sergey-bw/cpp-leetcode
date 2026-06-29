/**
 * 1967. Number of Strings That Appear as Substrings in Word
 * https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 * 
 * Given an array of strings patterns and a string word, return the number 
 * of strings in patterns that exist as a substring in word.
 * 
 * A substring is a contiguous sequence of characters within a string.
 * 
 * Example 1:
 *     Input: patterns = ["a","abc","bc","d"], word = "abc"
 *     Output: 3
 *     Explanation:
 *     - "a" appears as a substring in "abc".
 *     - "abc" appears as a substring in "abc".
 *     - "bc" appears as a substring in "abc".
 *     - "d" does not appear as a substring in "abc".
 *     3 of the strings in patterns appear as a substring in word.
 * 
 * Example 2:
 *     Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
 *     Output: 2
 *     Explanation:
 *     - "a" appears as a substring in "aaaaabbbbb".
 *     - "b" appears as a substring in "aaaaabbbbb".
 *     - "c" does not appear as a substring in "aaaaabbbbb".
 *     2 of the strings in patterns appear as a substring in word.
 * 
 * Example 3:
 *     Input: patterns = ["a","a","a"], word = "ab"
 *     Output: 3
 *     Explanation: Each of the patterns appears as a substring in word "ab".
 * 
 * Constraints:
 *     1 <= patterns.length <= 100
 *     1 <= patterns[i].length <= 100
 *     1 <= word.length <= 100
 *     patterns[i] and word consist of lowercase English letters.
 */

#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int numOfStrings(const std::vector<std::string>& patterns, const std::string& word) {
        return std::count_if(patterns.begin(), patterns.end(), [&word](const std::string& pattern) {
            return word.find(pattern) != std::string::npos;
        });
    }
};

void Test1() {
    std::vector<std::string> patterns = {"a", "abc", "bc", "d"};
    std::string word = "abc";
    int result = Solution().numOfStrings(patterns, word);
    assert(result == 3);
}

void Test2() {
    std::vector<std::string> patterns = {"a", "b", "c"};
    std::string word = "aaaaabbbbb";
    int result = Solution().numOfStrings(patterns, word);
    assert(result == 2);
}

void Test3() {
    std::vector<std::string> patterns = {"a", "a", "a"};
    std::string word = "ab";
    int result = Solution().numOfStrings(patterns, word);
    assert(result == 3);
}

int main() {
    Test1();
    Test2();
    Test3();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}