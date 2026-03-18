/**
 * 1888. Minimum Number of Flips to Make the Binary String Alternating
 * 
 * You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
 * Type-1: Remove the character at the start of the string s and append it to the end of the string.
 * Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
 * 
 * Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
 * 
 * The string is called alternating if no two adjacent characters are equal.
 * For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 * 
 * Example 1:
 * Input: s = "111000"
 * Output: 2
 * Explanation: Use the first operation two times to make s = "100011".
 * Then, use the second operation on the third and sixth elements to make s = "101010".
 * 
 * Example 2:
 * Input: s = "010"
 * Output: 0
 * Explanation: The string is already alternating.
 * 
 * Example 3:
 * Input: s = "1110"
 * Output: 1
 * Explanation: Use the second operation on the second element to make s = "1010".
 * 
 * Constraints:
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 */

#include <cassert>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minFlips(std::string s) {
        const int n = s.size();
        int diff0 = 0;
        
        for (int i = 0; i < n; ++i) {
            diff0 += (s[i] != "01"[i & 1]);
        }
        int diff1 = n - diff0;
        int min_flips = std::min(diff0, diff1);

        if ((n & 1) == 0) {
            return min_flips;
        }

        for (int i = 0; i < n; ++i) {
            std::swap(diff0, diff1);
            if (s[i] == '1') {
                ++diff0;
                --diff1;
            } else {
                --diff0;
                ++diff1;
            }

            min_flips = std::min({min_flips, diff0, diff1});
        }

        return min_flips;
    }
};

void Test1() {
    assert(Solution().minFlips("111000") == 2);
}

void Test2() {
    assert(Solution().minFlips("010") == 0);
}

void Test3() {
    assert(Solution().minFlips("1110") == 1);
}

void Test4() {
    assert(Solution().minFlips("11100") == 1);
}

void Test5() {
    assert(Solution().minFlips("110") == 0);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}