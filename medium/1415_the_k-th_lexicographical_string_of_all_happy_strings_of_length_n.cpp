/**
 * 1415. The k-th Lexicographical String of All Happy Strings of Length n
 * https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
 * 
 * 
 * A happy string is a string that:
 * 1) consists only of letters of the set ['a', 'b', 'c'].
 * 2) s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
 * 
 * For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa",
 * "baa" and "ababbc" are not happy strings.
 * 
 * Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
 * 
 * Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
 * 
 * Example 1:
 * Input: n = 1, k = 3
 * Output: "c"
 * Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
 * 
 * Example 2:
 * Input: n = 1, k = 4
 * Output: ""
 * Explanation: There are only 3 happy strings of length 1.
 * 
 * Example 3:
 * Input: n = 3, k = 9
 * Output: "cab"
 * Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"].
 * You will find the 9th string = "cab"
 * 
 * Constraints:
 * 1 <= n <= 10
 * 1 <= k <= 100
 */

#include <cassert>
#include <string>

class Solution {
public:
    std::string getHappyString(int n, int k) {
        int groupSize = 1 << (n - 1); 
        
        if (k > 3 * groupSize) {
            return "";
        }

        constexpr char NEXT[3][2] = {
            {'b', 'c'}, // prev=0 ('a')
            {'a', 'c'}, // prev=1 ('b')
            {'a', 'b'}  // prev=2 ('c')
        };

        std::string ans(n, ' ');
        --k; 
        
        ans[0] = 'a' + (k / groupSize);
        
        for (int i = 1; i < n; ++i) {
            int bit = (k >> (n - i - 1)) & 1;
            ans[i] = NEXT[ans[i - 1] - 'a'][bit];
        }
        
        return ans;
    }
};

void Test1() {
    assert(Solution().getHappyString(1, 3) == "c");
}

void Test2() {
    assert(Solution().getHappyString(1, 4) == "");
}

void Test3() {
    assert(Solution().getHappyString(3, 9) == "cab");
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}