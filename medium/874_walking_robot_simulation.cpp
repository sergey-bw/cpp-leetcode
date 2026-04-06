/**
 * 874. Walking Robot Simulation
 * https://leetcode.com/problems/walking-robot-simulation
 * 
 * A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:
 *     -2: Turn left 90 degrees.
 *     -1: Turn right 90 degrees.
 *     1 <= k <= 9: Move forward k units, one unit at a time.
 * 
 * Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.
 * Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).
 * 
 * Note:
 *     1. There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
 *     2. North means +Y direction.
 *     3. East means +X direction.
 *     4. South means -Y direction.
 *     5. West means -X direction.
 * 
 * Example 1:
 *     Input: commands = [4,-1,3], obstacles = []
 *     Output: 25
 *     Explanation: The robot starts at (0, 0):
 *         1. Move north 4 units to (0, 4).
 *         2. Turn right.
 *         3. Move east 3 units to (3, 4).
 *         The furthest point the robot ever gets from the origin is (3, 4), which squared is 3^2 + 4^2 = 25 units away.
 * 
 * Example 2:
 *     Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 *     Output: 65
 *     Explanation: The robot starts at (0, 0):
 *         1. Move north 4 units to (0, 4).
 *         2. Turn right.
 *         3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
 *         4. Turn left.
 *         5. Move north 4 units to (1, 8).
 *         The furthest point the robot ever gets from the origin is (1, 8), which squared is 1^2 + 8^2 = 65 units away.
 * 
 * Example 3:
 *     Input: commands = [6,-1,-1,6], obstacles = [[0,0]]
 *     Output: 36
 *     Explanation: The robot starts at (0, 0):
 *         1. Move north 6 units to (0, 6).
 *         2. Turn right.
 *         3. Turn right.
 *         4. Move south 5 units and get blocked by the obstacle at (0,0), robot is at (0, 1).
 *         The furthest point the robot ever gets from the origin is (0, 6), which squared is 62 = 36 units away.
 * 
 * Constraints:
 *     1 <= commands.length <= 10^4
 *     commands[i] is either -2, -1, or an integer in the range [1, 9].
 *     0 <= obstacles.length <= 10^4
 *     -3 * 10^4 <= xi, yi <= 3 * 10^4
 *     The answer is guaranteed to be less than 2^31.
 */

#include <cassert>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int robotSim(const std::vector<int>& commands, const std::vector<std::vector<int>>& obstacles) {
        const std::unordered_set<Point, PointHasher> obstacle_set = [&](){
            std::unordered_set<Point, PointHasher> result;
            result.reserve(obstacles.size());
            for (const auto& obs : obstacles) {
                result.emplace(obs);
            }
            return result;
        }();

        const Point kDirections[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int max_dist = 0;
        int direction_idx = 0;
        Point current_position{0,0};
        for (const int command : commands) {
            if (command < 0) {
                direction_idx = (direction_idx + (command == -1 ? 1 : 3)) % 4;
                continue;
            }

            for (int i = 0; i < command; ++i) {
                Point next_position = current_position + kDirections[direction_idx];
                if (obstacle_set.count(next_position) != 0) {
                    break;
                }
                current_position = next_position;
                max_dist = std::max(max_dist, current_position.getDistanceSquared());
            }
        }
        return max_dist;
    }

private:
    struct Point {
        int x = 0;
        int y = 0;

        Point(int x, int y) : x(x), y(y) {}

        explicit Point(const std::vector<int>& point) : x(point[0]), y(point[1]) {}

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }

        Point operator+(const Point& other) const {
            return {x + other.x, y + other.y};
        }

        int getDistanceSquared() const {
            return x * x + y * y;
        }
    };

    struct PointHasher {
        std::size_t operator()(const Point& p) const {
            return ((std::size_t)(p.x + 30000) << 32) ^ (p.y + 30000);
        }
    };
};

void Test1() {
    std::vector<std::vector<int>> obstacles = {};
    std::vector<int> commands = {4, -1, 3};
    assert(Solution().robotSim(commands, obstacles) == 25);
}

void Test2() {
    std::vector<std::vector<int>> obstacles = {{2, 4}};
    std::vector<int> commands = {4, -1, 4, -2, 4};
    assert(Solution().robotSim(commands, obstacles) == 65);
}

void Test3() {
    std::vector<std::vector<int>> obstacles = {{0, 0}};
    std::vector<int> commands = {6, -1, -1, 6};
    assert(Solution().robotSim(commands, obstacles) == 36);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}