/**
 * 1461. Check If a String Contains All Binary Codes of Size K
 * https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k
 * 
 * Check If a String Contains All Binary Codes of Size K
 * 
 * Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
 *
 * Example 1:
 * Input: s = "00110110", k = 2
 * Output: true
 * Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
 * 
 * Example 2:
 * Input: s = "0110", k = 1
 * Output: true
 * Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
 * 
 * Example 3:
 * Input: s = "0110", k = 2
 * Output: false
 * Explanation: The binary code "00" is of length 2 and does not exist in the array.
 *  
 * Constraints:
 * 1 <= s.length <= 5 * 10^5
 * s[i] is either '0' or '1'.
 * 1 <= k <= 20
 */

#include <cassert>
#include <string>
#include <vector>

class Solution {
public:
    bool hasAllCodes(const std::string& s, int k) {
        size_t substr_count = static_cast<size_t>(1) << k; 
        if (s.length() < static_cast<size_t>(k) || s.length() - k + 1 < substr_count) {
            return false;
        }
        
        std::vector<char> binary_codes(substr_count, 0);
        size_t x = 0;
        size_t found_count = 0;
        size_t bit_mask = (static_cast<size_t>(1) << k) - 1;
        size_t start = static_cast<size_t>(k) - 1;
        for (size_t i = 0; i < s.length(); ++i) {
            x = (x << 1) | (s[i] - '0');
            x = x & bit_mask;
            if (i >= start && !binary_codes[x]) {
                binary_codes[x] = 1;
                ++found_count;
                if (found_count == substr_count) {
                    return true;
                }
            }
        }
        return false;
    }
};

void Test1() {
    assert(Solution().hasAllCodes("00110110", 2) == true);
}

void Test2() {
    assert(Solution().hasAllCodes("0110", 1) == true);
}

void Test3() {
    assert(Solution().hasAllCodes("0110", 2) == false);
}

void Test4() {
    assert(Solution().hasAllCodes("00110", 2) == true);
}

void Test5() {
    assert(Solution().hasAllCodes("01", 1) == true);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}