#ifndef UNIFIED_CORE_DEBUG_ASSERT_HPP
#define UNIFIED_CORE_DEBUG_ASSERT_HPP

#include <unified/defines.hpp>
#include <inttypes.hpp>

UNIFIED_BEGIN_NAMESPACE

void assert_failed(const char *file, u64 line, const char* message);

#define ASSERT_FAILED(condition, content) \
    ((condition) ? (void)0 : Unified::assert_failed(__FILE__, __LINE__, content)))

UNIFIED_END_NAMESPACE

#endif
