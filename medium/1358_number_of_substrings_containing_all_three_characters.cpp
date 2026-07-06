/**
 * 1358. Number of Substrings Containing All Three Characters
 * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * 
 * Given a string s consisting only of characters a, b and c.
 * Return the number of substrings containing at least one occurrence of all these characters a, b and c.
 * 
 * Example 1:
 *     Input: s = "abcabc"
 *     Output: 10
 *     Explanation: The substrings containing at least one occurrence of the characters a, b and c are 
 *     "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
 * 
 * Example 2:
 *     Input: s = "aaacb"
 *     Output: 3
 *     Explanation: The substrings containing at least one occurrence of the characters a, b and c are
 *     "aaacb", "aacb" and "acb". 
 * 
 * Example 3:
 *     Input: s = "abc"
 *     Output: 1
 * 
 * Constraints:
 *     3 <= s.length <= 5 * 10^4
 *     s consists only of a, b or c characters.
 */

#include <cassert>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfSubstringsV2(const std::string& s) {
        const size_t n = s.length();
        std::vector<int> char_freq(3, 0); // Строка содержит только символы 'a', 'b', 'c'
        size_t left = 0;
        size_t right = 0;
        int count = 0;
        while (right < n) {
            ++char_freq[s[right] - 'a'];
            while (*std::min_element(char_freq.begin(), char_freq.end()) > 0) {
                count += n - right;
                --char_freq[s[left] - 'a'];
                ++left;
            }
            ++right;
        }
        return count;
    }

    int numberOfSubstrings(const std::string& s) {
        const int n = s.length();
        std::vector<int> last_seen(3, -1);
        int res = 0;
        for (int right = 0; right < n; ++right) {
            last_seen[s[right] - 'a'] = right;
            int min_idx = std::min({last_seen[0], last_seen[1], last_seen[2]});
            // Если все три буквы уже встречались (min_idx != -1)
            if (min_idx != -1) {
                res += min_idx + 1;
            }
        }
        return res;
    }
};

void Test1() {
    std::string s = "abcabc";
    int result = Solution().numberOfSubstrings(s);
    assert(result == 10);
}

void Test2() {
    std::string s = "aaacb";
    int result = Solution().numberOfSubstrings(s);
    assert(result == 3);
}

void Test3() {
    std::string s = "abc";
    int result = Solution().numberOfSubstrings(s);
    assert(result == 1);
}

int main() {
    Test1();
    Test2();
    Test3();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}