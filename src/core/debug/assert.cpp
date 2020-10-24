#include <unified/core/debug/assert.hpp>

#include <cstdio>
#include <exception>

UNIFIED_BEGIN_NAMESPACE

void assert_failed(const char *file, u64 line, const char* message) {
    std::fprintf(stderr, "%s:%llu: assertion failed:\n\t%s\n\t", file, line, message);
    std::terminate();
}

UNIFIED_END_NAMESPACE
