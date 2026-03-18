#pragma once

/**
 * RAII-таймер
 * Используется для профилировки участков кода
 * 
 * Пример использования:
 * ...
 * {
 *     LOG_DURATION("SomeFunction()"s);
 *     SomeFunction();
 * }
 * ...
 */
#include <chrono>
#include <iostream>
#include <string>

class LogDuration {
public:
    using Clock = std::chrono::steady_clock;

    explicit LogDuration(const char* test_name)
        : test_name_(test_name)
    {
    }

    explicit LogDuration(const std::string& test_name)
        : test_name_(test_name)
    {
    }

    explicit LogDuration(std::string&& test_name)
        : test_name_(std::move(test_name))
    {
    }

    ~LogDuration() noexcept {
        using namespace std::chrono;
        using namespace std::literals;

        const auto end_time = Clock::now();
        const auto dur = end_time - start_time_;
        std::cerr << test_name_ << ": "s << duration_cast<milliseconds>(dur).count() << " ms"s << std::endl;
    }

private:
    const Clock::time_point start_time_ = Clock::now();
    const std::string test_name_;
};

#define PROFILE_CONCAT_INTERNAL(X, Y) X ## Y
#define PROFILE_CONCAT(X, Y) PROFILE_CONCAT_INTERNAL(X, Y)
#define UNIQUE_VAR_NAME_PROFILE PROFILE_CONCAT(profileGuard, __LINE__)
#define LOG_DURATION(x) LogDuration UNIQUE_VAR_NAME_PROFILE(x)