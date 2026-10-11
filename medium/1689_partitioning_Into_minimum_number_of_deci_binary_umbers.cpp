/**
 * 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
 * https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
 * 
 * A decimal number is called deci-binary if each of its digits is
 * either 0 or 1 without any leading zeros. For example, 101 and 1100
 * are deci-binary, while 112 and 3001 are not.
 * 
 * Given a string n that represents a positive decimal integer,
 * return the minimum number of positive deci-binary numbers
 * needed so that they sum up to n.
 * 
 * Example 1:
 * Input: n = "32"
 * Output: 3
 * Explanation: 10 + 11 + 11 = 32
 * 
 * Example 2:
 * Input: n = "82734"
 * Output: 8
 * 
 * Example 3:
 * Input: n = "27346209830709182346"
 * Output: 9
 * 
 * Constraints:
 * 1 <= n.length <= 10^5
 * n consists of only digits.
 * n does not contain any leading zeros and represents a positive integer.
 */

#include <cassert>
#include <string>
#include <algorithm>

class Solution {
public:
    int minPartitions(const std::string& n) {
        // n.length() > 0 по условию
        return *std::max_element(n.cbegin(), n.cend()) - '0';
    }
};

void Test1() {
    assert(Solution().minPartitions("32") == 3);
}

void Test2() {
    assert(Solution().minPartitions("82734") == 8);
}

void Test3() {
    assert(Solution().minPartitions("27346209830709182346") == 9);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}