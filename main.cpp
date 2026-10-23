#include "CF/1866A_ambitious_kid.hpp"

#include <iostream>
#include <sys/resource.h>
#include <sys/time.h>

namespace {
double tv_ms(const timeval& tv) {
    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    struct rusage before{}, after{};
    getrusage(RUSAGE_SELF, &before);
    solution();
    getrusage(RUSAGE_SELF, &after);

    const double cpu_ms = (tv_ms(after.ru_utime) - tv_ms(before.ru_utime)) +
                          (tv_ms(after.ru_stime) - tv_ms(before.ru_stime));
    std::cerr << "\n\n[cf] Time: " << cpu_ms << " ms | Memory: " << after.ru_maxrss
              << " KB\n";
    return 0;
}
