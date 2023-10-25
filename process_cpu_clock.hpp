#pragma once

#include "linux_clock.hpp"

namespace linux_clock {

using process_cpu_clock = linux_clock<CLOCK_PROCESS_CPUTIME_ID>;

} // namespace linux_clock