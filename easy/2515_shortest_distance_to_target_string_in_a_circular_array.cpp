/**
 * 2515. Shortest Distance to Target String in a Circular Array
 * https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array
 * 
 * You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.
 * Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
 * 
 * Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.
 * 
 * Return shortest distance needed to reach the string target. If the string target does not exist in words, return -1.
 * 
 * Example 1:
 *     Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
 *     Output: 1
 *     Explanation: We start from index 1 and can reach "hello" by
 *         - moving 3 units to the right to reach index 4.
 *         - moving 2 units to the left to reach index 4.
 *         - moving 4 units to the right to reach index 0.
 *         - moving 1 unit to the left to reach index 0.
 *         The shortest distance to reach "hello" is 1.
 * 
 * Example 2:
 *     Input: words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
 *     Output: 1
 *     Explanation: We start from index 0 and can reach "leetcode" by
 *         - moving 2 units to the right to reach index 2.
 *         - moving 1 unit to the left to reach index 2.
 *         The shortest distance to reach "leetcode" is 1.
 * 
 * Example 3:
 *     Input: words = ["i","eat","leetcode"], target = "ate", startIndex = 0
 *     Output: -1
 *     Explanation: Since "ate" does not exist  words, we return -1.
 * 
 * Constraints:
 *     1 <= words.length <= 100
 *     1 <= words[i].length <= 100
 *     words[i] and target consist of only lowercase English letters.
 *     0 <= startIndex < words.length
 */

#include <cassert>
#include <string>
#include <vector>

class Solution {
public:
    int closestTarget(const std::vector<std::string>& words, const std::string& target, int startIndex) {
        const size_t n = words.size();
        const size_t start_idx = static_cast<size_t>(startIndex);
        for (size_t offset = 0; offset <= n / 2; ++offset) {
            size_t left_idx = (start_idx + n - offset) % n;
            size_t right_idx = (start_idx + offset) % n;
            if (words[left_idx] == target
                || (left_idx != right_idx && words[right_idx] == target)) {
                return offset;
            }
        }
        return -1;
    }
};

void Test1() {
    const std::vector<std::string> words = {"hello", "i", "am", "leetcode", "hello"};
    const std::string target = "hello";
    assert(Solution().closestTarget(words, target, 1) == 1);
}

void Test2() {
    const std::vector<std::string> words = {"a","b","leetcode"};
    const std::string target = "leetcode";
    assert(Solution().closestTarget(words, target, 0) == 1);
}

void Test3() {
    const std::vector<std::string> words = {"i","eat","leetcode"};
    const std::string target = "ate";
    assert(Solution().closestTarget(words, target, 0) == -1);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}