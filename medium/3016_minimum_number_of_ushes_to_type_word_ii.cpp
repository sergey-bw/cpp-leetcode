/**
 * 3016. Minimum Number of Pushes to Type Word II
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
 * 
 * You are given a string word consisting of lowercase English letters.
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
 *     Input: word = "xyzxyzxyzxyz"
 *     Output: 12
 *     Explanation:
 *     We can remap keys so that "x", "y", "z" all occupy 1-push positions on some keys.
 *     Typing "xyzxyzxyzxyz" then requires 12 pushes.
 * 
 * Example 3:
 *     Input: word = "aabbccddeeffgghhiiiiii"
 *     Output: 24
 *     Explanation:
 *     We can remap keys so that the most frequent letter 'i' is in a 1-push position,
 *     and other frequent letters are placed optimally to minimize total pushes.
 * 
 * Constraints:
 *     1 <= word.length <= 10^5
 *     word consists of lowercase English letters.
 */

#include <cassert>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>

class Solution {
public:
    int minimumPushes(const std::string& word) {
        // 1. Считаем частоты символов
        const size_t kAlphaSize = 26;
        std::array<int, kAlphaSize> char_freq = {0};
        for (char c : word) {
            ++char_freq[c - 'a'];
        }

        // 2. Сортируем. Чем чаще встречается буква, тем меньше должно быть нажатий
        std::sort(char_freq.begin(), char_freq.end(), std::greater<int>());

        // 3. Итоговый подсчет
        int result = 0;
        for (size_t i = 0; i < char_freq.size() && char_freq[i] > 0; ++i) {
            // Каждые 8 букв получают на 1 больше нажатий
            result += char_freq[i] * (i / 8 + 1);
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
    std::string word = "xyzxyzxyzxyz";
    int expected = 12;
    int result = Solution().minimumPushes(word);
    assert(result == expected);
}

void Test3() {
    std::string word = "aabbccddeeffgghhiiiiii";
    int expected = 24;
    int result = Solution().minimumPushes(word);
    assert(result == expected);
}

int main() {
    Test1();
    Test2();
    Test3();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}