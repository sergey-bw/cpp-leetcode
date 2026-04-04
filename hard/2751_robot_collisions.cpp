/**
 * 2751. Robot Collisions
 * 
 * There are n 1-indexed robots, each having a position on a line, health, and movement direction.
 * 
 * You are given 0-indexed integer arrays positions, healths, and a string directions
 * (directions[i] is either 'L' for left or 'R' for right). All integers in positions unique.
 * 
 * All robots start moving on the line simultaneously at the same speed in their given directions.
 * If two robots ever share the same position while moving, they will collide.
 * 
 * If two robots collide, the robot with lower health removed from the line,
 * and the health of the other robot decreases by one. The surviving robot continues in the same
 * direction it was going. If both robots have the same health, they are both removed from the line.
 * 
 * Your task is to determine the health of the robots that survive the collisions,
 * in the same order that the robots were given, i.e. final health of robot 1 (if survived),
 * final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
 * 
 * Return an array containing the health of the remaining robots (in the order they were given in the input),
 * after no further collisions can occur.
 * 
 * Note: The positions may be unsorted.
 * 
 * Example 1:
 * 
 *     10    15    9     17    2
 *     O->   O->   O->   O->   O->
 *     ---------------------------------->
 *     1     2     3     4     5
 *
 *     Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
 *     Output: [2,17,9,15,10]
 *     Explanation: No collision occurs in this example, since all robots are moving in the same direction.
 *     So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
 * 
 * Example 2:
 * 
 *     15    10     10    12
 *     O->   O->   <-O   <-O
 *     ---------------------------->
 *     2     3       5     6    
 * 
 *     Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
 *     Output: [14]
 *     Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide,
 *     and since both have the same health, they will be removed from the line. Next,
 *     robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed,
 *     and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].
 * 
 * Example 3:
 * 
 *     10     10     11     11
 *     O->   <-O     O->   <-O
 *     ---------------------------->
 *     1       2     5       6    
 * 
 *     Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
 *     Output: []
 *     Explanation: Robot 1 and robot 2 will collide and since both have the same health,
 *     they are both removed. Robot 3 and 4 will collide and since both have the same health,
 *     they are both removed. So, we return an empty array, [].
 *
 * Constraints:
 *     1 <= positions.length == healths.length == directions.length == n <= 10^5
 *     1 <= positions[i], healths[i] <= 10^9
 *     directions[i] == 'L' or directions[i] == 'R'
 *     All values in positions are distinct
 */

#include <cassert>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <stack>

class Solution {
public:
    std::vector<int> survivedRobotsHealths(const std::vector<int>& positions, std::vector<int>& healths, const std::string& directions)
    {
        const size_t n = positions.size();
        std::vector<size_t> sorted_indexes(n);
        std::iota(sorted_indexes.begin(), sorted_indexes.end(), 0);
        std::sort(sorted_indexes.begin(), sorted_indexes.end()
            , [&positions](const auto lhs, const auto rhs) {
                return positions[lhs] < positions[rhs];
        });

        std::stack<size_t> stack;
        for (const size_t index : sorted_indexes) {
            while (healths[index] > 0) {
                if (stack.empty()) {
                    stack.push(index);
                    break;
                }
                size_t prev_index = stack.top();
                if (directions[prev_index] == directions[index] || directions[prev_index] == 'L') {
                    stack.push(index);
                    break;
                }

                // Collisions
                if (healths[prev_index] == healths[index]) {
                    healths[prev_index] = healths[index] = 0;
                    stack.pop();
                    break;
                }

                if (healths[prev_index] > healths[index]) {
                    --healths[prev_index];
                    healths[index] = 0;
                    break;
                }

                --healths[index];
                healths[prev_index] = 0;
                stack.pop();
            }
        }

        std::vector<int> ans;
        ans.reserve(stack.size());
        for (size_t i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};

void Test1() {
    std::vector<int> positions = {5, 4, 3, 2, 1};
    std::vector<int> healths = {2, 17, 9, 15, 10};
    std::string directions = "RRRRR";

    std::vector<int> result = {2, 17, 9, 15, 10};
    assert(Solution().survivedRobotsHealths(positions, healths, directions) == result);
}

void Test2() {
    std::vector<int> positions = {3, 5, 2, 6};
    std::vector<int> healths = {10, 10, 15, 12};
    std::string directions = "RLRL";
    
    std::vector<int> result = {14};
    assert(Solution().survivedRobotsHealths(positions, healths, directions) == result);
}

void Test3() {
    std::vector<int> positions = {1, 2, 5, 6};
    std::vector<int> healths = {10, 10, 11, 11};
    std::string directions = "RLRL";
    
    std::vector<int> result = {};
    assert(Solution().survivedRobotsHealths(positions, healths, directions) == result);
}

void Test4() {
    std::vector<int> positions = {1, 5};
    std::vector<int> healths = {10, 50};
    std::string directions = "LL";
    
    std::vector<int> result = {10, 50};
    assert(Solution().survivedRobotsHealths(positions, healths, directions) == result);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}