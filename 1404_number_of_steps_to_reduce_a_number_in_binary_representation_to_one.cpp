/**
 * 1404. Number of Steps to Reduce a Number in Binary Representation to One
 * 
 * Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
 * If the current number is even, you have to divide it by 2.
 * If the current number is odd, you have to add 1 to it.
 * 
 * It is guaranteed that you can always reach one for all test cases.
 * 
 * Example 1:
 * Input: s = "1101"
 * Output: 6
 * Explanation: "1101" corressponds to number 13 in their decimal representation.
 * Step 1) 13 is odd, add 1 and obtain 14. 
 * Step 2) 14 is even, divide by 2 and obtain 7.
 * Step 3) 7 is odd, add 1 and obtain 8.
 * Step 4) 8 is even, divide by 2 and obtain 4.  
 * Step 5) 4 is even, divide by 2 and obtain 2. 
 * Step 6) 2 is even, divide by 2 and obtain 1.
 * 
 * Example 2:
 * Input: s = "10"
 * Output: 1
 * Explanation: "10" corresponds to number 2 in their decimal representation.
 * Step 1) 2 is even, divide by 2 and obtain 1. 
 * 
 * Example 3:
 * Input: s = "1"
 * Output: 0
 * 
 * Constraints:
 * 1 <= s.length <= 500
 * s consists of characters '0' or '1'
 * s[0] == '1'
 */

#include <cassert>
#include <string>

class Solution {
public:
    int numSteps(std::string s) {
        if (s.empty() || s == "1") {
            return 0;
        }
        int steps = 0;
        int carry = 0;
        for (size_t i = s.length() - 1; i > 0; --i) {
            if (((s[i] - '0' + carry) & 1) == 0) {
                ++steps;
            } else {
                steps += 2;
                carry = 1;
            }
        }
        return steps + carry;
    }
};

void Test1() {
    using namespace std::literals;
    assert(Solution().numSteps("1101"s) == 6);
}

void Test2() {
    using namespace std::literals;
    assert(Solution().numSteps("10"s) == 1);
}

void Test3() {
    using namespace std::literals;
    assert(Solution().numSteps("1"s) == 0);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}