# linux_clock
Header-only simple implementation of Linux standard clocks

Example of usage:
```cpp
#include <print>

auto main() -> int {
    const auto mono = linux_clock::monotonic_clock::now().time_since_epoch();
    const auto proc = linux_clock::process_cpu_clock::now().time_since_epoch();
    const auto real = linux_clock::realtime_clock::now().time_since_epoch();
    const auto thrd = linux_clock::thread_cpu_clock::now().time_since_epoch();
    std::println("Monotonic clock time: {}", mono);
    std::println("Process clock time:   {}", proc);
    std::println("Realtime clock time:  {}", real);
    std::println("Thread clock time:    {}", thrd);
}
```

https://godbolt.org/z/q9Ez9j1EK
