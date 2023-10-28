#pragma once

#include "linux_clock.hpp"

namespace linux_clock {

using realtime_clock = linux_clock<CLOCK_REALTIME, false>;

} // namespace linux_clock
