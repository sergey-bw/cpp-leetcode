/**
 * 1189. Maximum Number of Balloons
 * https://leetcode.com/problems/maximum-number-of-balloons/
 * 
 * Given a string text, you want to use the characters of text to form as many instances 
 * of the word "balloon" as possible.
 * 
 * You can use each character in text at most once. Return the maximum number of instances 
 * that can be formed.
 * 
 * Example 1:
 *     Input: text = "nlaebolko"
 *     Output: 1
 * 
 * Example 2:
 *     Input: text = "loonbalxballpoon"
 *     Output: 2
 * 
 * Example 3:
 *     Input: text = "leetcode"
 *     Output: 0
 * 
 * Constraints:
 *     1 <= text.length <= 10^4
 *     text consists of lower case English letters only.
 */

#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxNumberOfBalloons(const std::string& text) {
        const size_t kAlphabetSize = 26;
        
        std::vector<int> freq(kAlphabetSize, 0);
        for (const char c : text) {
            ++freq[c - 'a'];
        }

        return std::min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};

void Test1() {
    std::string text = "nlaebolko";
    int result = Solution().maxNumberOfBalloons(text);
    assert(result == 1);
}

void Test2() {
    std::string text = "loonbalxballpoon";
    int result = Solution().maxNumberOfBalloons(text);
    assert(result == 2);
}

void Test3() {
    std::string text = "leetcode";
    int result = Solution().maxNumberOfBalloons(text);
    assert(result == 0);
}

void Test4_NotEnoughDoubleLetters() {
    std::string text = "balon"; // Не хватает одной 'l' и одной 'o'
    int result = Solution().maxNumberOfBalloons(text);
    assert(result == 0);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4_NotEnoughDoubleLetters();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}