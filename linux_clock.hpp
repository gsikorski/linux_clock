#pragma once

#include <chrono>
#include <time.h>

namespace linux_clock {

template <clockid_t ClockId, bool IsSteady = true>
struct linux_clock {
    using duration = typename std::chrono::nanoseconds;
    using rep = typename duration::rep;
    using period = typename duration::period;
    using time_point = typename std::chrono::time_point<linux_clock<ClockId>>;
    static constexpr bool is_steady = IsSteady;
    static auto now() noexcept -> time_point {
        auto current_time = timespec {};
        if(0 != clock_gettime(ClockId, &current_time)) { return time_point {}; }
        return time_point {std::chrono::seconds(current_time.tv_sec) + std::chrono::nanoseconds(current_time.tv_nsec)};
    }
};

} // namespace linux_clock
