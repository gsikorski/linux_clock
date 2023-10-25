#pragma once

#include "linux_clock.hpp"

namespace linux_clock {

using thread_cpu_clock = linux_clock<CLOCK_THREAD_CPUTIME_ID>;

} // namespace linux_clock