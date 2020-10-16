#include <unified/core/debug/assert.hpp>

#include <cstdio>
#include <exception>

void Unified::assert_fail(const char *file, u64 line, const char* message) {
    std::fprintf(stderr, "%s:%llu: assertion failed:\n\t%s\n\t", file, line, message);
    std::terminate();
}