#include <inttypes.hpp>

#ifndef UNIFIED_CORE_ASSERT_HPP
#define UNIFIED_CORE_ASSERT_HPP

namespace Unified
{
    void assert_failed(const char *file, u64 line, const char* message);
}

#define ASSERT_FAILED(condition, content) \
    ((condition) ? (void)0 : Unified::assert_failed(__FILE__, __LINE__, content)))

#endif