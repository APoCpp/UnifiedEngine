#include <inttypes.hpp>

#ifndef UNIFIED_CORE_ASSERT_HPP
#define UNIFIED_CORE_ASSERT_HPP

namespace Unified
{
    void assert_fail(const char *file, u64 line, const char* message);
}

#endif