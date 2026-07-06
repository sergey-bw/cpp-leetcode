/**
 * 1288. Remove Covered Intervals
 * https://leetcode.com/problems/remove-covered-intervals/
 * 
 * Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
 * remove all intervals that are covered by another interval in the list.
 * 
 * The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
 * 
 * Return the number of remaining intervals.
 * 
 * Example 1:
 *     Input: intervals = [[1,4],[3,6],[2,8]]
 *     Output: 2
 *     Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
 * 
 * Example 2:
 *     Input: intervals = [[1,4],[2,3]]
 *     Output: 1
 * 
 * Constraints:
 *     1 <= intervals.length <= 1000
 *     intervals[i].length == 2
 *     0 <= li < ri <= 10^5
 *     All the given intervals are unique.
 */

#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
                return std::pair{lhs[0], -lhs[1]} < std::pair{rhs[0], -rhs[1]};
            }
        );
        
        int count = 0;
        int max_right = 0;
        for (const auto& interval: intervals) {
            const int current_right = interval[1];
            if (current_right > max_right) {
                ++count;
                max_right = current_right;
            }
        }
        return count;
    }
};

void Test1() {
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    int result = Solution().removeCoveredIntervals(intervals);
    assert(result == 2);
}

void Test2() {
    vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    int result = Solution().removeCoveredIntervals(intervals);
    assert(result == 1);
}

void Test3_SameStart() {
    vector<vector<int>> intervals = {{1, 4}, {1, 5}, {1, 6}};
    int result = Solution().removeCoveredIntervals(intervals);
    // [1,4] and [1,5] are covered by [1,6]
    assert(result == 1);
}

void Test4_NoOverlap() {
    vector<vector<int>> intervals = {{1, 2}, {3, 4}, {5, 6}};
    int result = Solution().removeCoveredIntervals(intervals);
    assert(result == 3);
}

int main() {
    Test1();
    Test2();
    Test3_SameStart();
    Test4_NoOverlap();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}