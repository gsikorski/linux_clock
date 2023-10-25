#pragma once

#include "linux_clock.hpp"

namespace linux_clock {

using monotonic_clock = linux_clock<CLOCK_MONOTONIC>;

} // namespace linux_clock