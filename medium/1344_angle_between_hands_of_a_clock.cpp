/**
 * 1344. Angle Between Hands of a Clock
 * https://leetcode.com/problems/angle-between-hands-of-a-clock/
 * 
 * Given two numbers, hour and minutes, return the smaller angle (in degrees) 
 * formed between the hour and the minute hand.
 * 
 * Answers within 10^-5 of the actual value will be accepted as correct.
 * 
 * Example 1:
 *     Input: hour = 12, minutes = 30
 *     Output: 165
 * 
 * Example 2:
 *     Input: hour = 3, minutes = 30
 *     Output: 75
 * 
 * Example 3:
 *     Input: hour = 3, minutes = 15
 *     Output: 7.5
 * 
 * Constraints:
 *     1 <= hour <= 12
 *     0 <= minutes <= 59
 */

#include <cassert>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        constexpr double kFullCircleAngle = 360.0;
        constexpr double kHoursPerClock = 12.0;
        constexpr double kMinutesPerHour = 60.0;

        // Базовые угловые сдвиги
        constexpr double kMinuteAngle = kFullCircleAngle / kMinutesPerHour;
        constexpr double kHourAngle = kFullCircleAngle / kHoursPerClock;

        // Смещение часовой стрелки за каждую прошедшую минуту в часе
        constexpr double kHourShiftPerMinute = kHourAngle / kMinutesPerHour;

        double minutes_angle = minutes * kMinuteAngle;
        double hours_angle = (hour % static_cast<int>(kHoursPerClock)) * kHourAngle 
                           + minutes * kHourShiftPerMinute;
            
        double angle_diff = std::abs(minutes_angle - hours_angle);
        
        // Возвращаем наименьший угол (по часовой или против часовой стрелки)
        return std::min(angle_diff, kFullCircleAngle - angle_diff);
    }
};

bool IsEqual(double a, double b) {
    return std::abs(a - b) <= 1e-5;
}

void Test1() {
    double result = Solution().angleClock(12, 30);
    double expected = 165.0;
    assert(IsEqual(result, expected));
}

void Test2() {
    double result = Solution().angleClock(3, 30);
    double expected = 75.0;
    assert(IsEqual(result, expected));
}

void Test3() {
    double result = Solution().angleClock(3, 15);
    double expected = 7.5;
    assert(IsEqual(result, expected));
}

void Test4_ZeroMinutes() {
    double result = Solution().angleClock(4, 0);
    double expected = 120.0;
    assert(IsEqual(result, expected));
}

void Test5_MaxAngle() {
    double result = Solution().angleClock(6, 0);
    double expected = 180.0;
    assert(IsEqual(result, expected));
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4_ZeroMinutes();
    Test5_MaxAngle();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}