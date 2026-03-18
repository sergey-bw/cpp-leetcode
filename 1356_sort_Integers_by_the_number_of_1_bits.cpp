/**
 * 1356. Sort Integers by The Number of 1 Bits
 * 
 * You are given an integer array arr.
 * Sort the integers in the array in ascending order by
 * the number of 1's in their binary representation and
 * in case of two or more integers have the same number
 * of 1's you have to sort them in ascending order.
 * 
 * Return the array after sorting it.
 * 
 * Example 1:
 * Input: arr = [0,1,2,3,4,5,6,7,8]
 * Output: [0,1,2,4,8,3,5,6,7]
 * Explantion:
 * [0] is the only integer with 0 bits.
 * [1,2,4,8] all have 1 bit.
 * [3,5,6] have 2 bits.
 * [7] has 3 bits.
 * The sorted array by bits is [0,1,2,4,8,3,5,6,7]
 * 
 * Example 2:
 * Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
 * Output: [1,2,4,8,16,32,64,128,256,512,1024]
 * Explantion: All integers have 1 bit in the binary representation,
 * you should just sort them in ascending order.
 * 
 * Constraints:
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 10^4
 */

#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortByBits(std::vector<int>& arr) {
        std::vector<unsigned char> count_bits(*std::max_element(arr.begin(), arr.end()) + 1, 0);
        for (size_t i = 1; i < count_bits.size(); ++i) {
            // Подсчет бит со значением 1
            count_bits[i] = count_bits[i>>1] + static_cast<unsigned char>(i&1);
        }
        auto result = arr;
        sort(result.begin(), result.end(), [&count_bits](auto lhs, auto rhs) {
            return std::make_pair(count_bits[lhs], lhs) < std::make_pair(count_bits[rhs], rhs);
        });
        return result;
    }
};

void Test1() {
    std::vector<int> input{0,1,2,3,4,5,6,7,8};
    std::vector<int> expected{0,1,2,4,8,3,5,6,7};
    assert(Solution().sortByBits(input) == expected);
}

void Test2() {
    std::vector<int> input{1024,512,256,128,64,32,16,8,4,2,1};
    std::vector<int> expected{1,2,4,8,16,32,64,128,256,512,1024};
    assert(Solution().sortByBits(input) == expected);
}

int main() {
    Test1();
    Test2();
    return 0;
}