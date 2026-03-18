/**
 * 1680. Concatenation of Consecutive Binary Numbers
 * 
 * Given an integer n, return the decimal value of the binary string formed
 * by concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.
 *
 * Example 1:
 * Input: n = 1
 * Output: 1
 * Explanation: "1" in binary corresponds to the decimal value 1.
 * 
 * Example 2:
 * Input: n = 3
 * Output: 27
 * Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
 * After concatenating them, we have "11011", which corresponds to the decimal value 27.
 * 
 * Example 3:
 * Input: n = 12
 * Output: 505379714
 * Explanation: The concatenation results in "1101110010111011110001001101010111100".
 * The decimal value of that is 118505380540.
 * After modulo 109 + 7, the result is 505379714.
 * 
 * Constraints:
 * 1 <= n <= 10^5
 */

#include <cassert>
#include <cstdint>

constexpr uint64_t MOD = 1000000007;

class Solution {
public:
    int concatenatedBinary(int n) {
        uint64_t res = 0;
        int count_bit = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++count_bit;
            }
            res = ((res << count_bit) | i) % MOD;
        }
        return res;
    }
};

void Test1() {
    assert(Solution().concatenatedBinary(1) == 1);
}

void Test2() {
    assert(Solution().concatenatedBinary(3) == 27);
}

void Test3() {
    assert(Solution().concatenatedBinary(12) == 505379714);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}