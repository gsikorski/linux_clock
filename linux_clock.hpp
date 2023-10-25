#pragma once

#include <chrono>
#include <time.h>

namespace linux_clock {

template <clockid_t ClockId>
struct linux_clock {
    using rep = typename std::chrono::high_resolution_clock::rep;
    using period = typename std::chrono::high_resolution_clock::period;
    using duration = typename std::chrono::high_resolution_clock::duration;
    using time_point = typename std::chrono::time_point<linux_clock<ClockId>>;
    static constexpr bool is_steady = true;
    static auto now() noexcept -> time_point {
        auto current_time = timespec {};
        if(0 != clock_gettime(ClockId, &current_time)) { return time_point {}; }
        return time_point {std::chrono::seconds(current_time.tv_sec) + std::chrono::nanoseconds(current_time.tv_nsec)};
    }
};

} // namespace linux_clock