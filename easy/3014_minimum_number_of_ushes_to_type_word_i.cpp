/**
 * 3014. Minimum Number of Pushes to Type Word I
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 * 
 * You are given a string word containing distinct lowercase English letters.
 * Telephone keypads have keys mapped with distinct collections of lowercase English letters,
 * which can be used to form words by pushing them.
 * 
 * For example, the key 2 is mapped with ["a","b","c"], 
 * we need to push the key one time to type "a", two times to type "b", and three times to type "c".
 * 
 * It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters.
 * The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key.
 * 
 * You need to find the minimum number of times the keys will be pushed to type the string word.
 * Return the minimum number of pushes needed to type word after remapping the keys.
 * 
 * Example 1:
 *     Input: word = "abcde"
 *     Output: 5
 *     Explanation:
 *     We can map the keys in the following way:
 *     2 -> "abcde"
 *     All other keys do not map to any letters.
 *     To type "abcde", we press key 2 once for each character, for a total of 5 pushes.
 * 
 * Example 2:
 *     Input: word = "xyz"
 *     Output: 3
 *     Explanation:
 *     We can map the keys in the following way:
 *     2 -> "xyz"
 *     All other keys do not map to any letters.
 *     To type "xyz", we press key 2 once for each character, for a total of 3 pushes.
 * 
 * Constraints:
 *     1 <= word.length <= 26
 *     word consists of distinct lowercase English letters.
 */

#include <cassert>
#include <string>
#include <iostream>

class Solution {
public:
    int minimumPushes(const std::string& word) {
        int remaining_letters = static_cast<int>(word.size());
        int result = 0;
        int presses_per_letter = 1;

        while (remaining_letters > 0) {
            int letters_in_block = std::min(8, remaining_letters);
            result += letters_in_block * presses_per_letter;
            remaining_letters -= letters_in_block;
            ++presses_per_letter;
        }

        return result;
    }

    int minimumPushesV2(const std::string& word) {
        int n = static_cast<int>(word.size());
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += i / 8 + 1;
        }
        return result;
    }
};

void Test1() {
    std::string word = "abcde";
    int expected = 5;
    int result = Solution().minimumPushes(word);
    assert(result == expected);
}

void Test2() {
    std::string word = "xyz";
    int expected = 3;
    int result = Solution().minimumPushes(word);
    assert(result == expected);
}

void Test3_SingleChar() {
    std::string word = "a";
    int expected = 1;
    int result = Solution().minimumPushes(word);
    assert(result == expected);
}

int main() {
    Test1();
    Test2();
    Test3_SingleChar();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}