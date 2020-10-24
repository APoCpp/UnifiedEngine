#include <unified/core/exceptions.hpp>

#include <string>
#include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

initialization_failed::initialization_failed(const char *target) : _target(target) { }

const char *initialization_failed::what() const _OSL_NOEXCEPT {
    return _target;
}

UNIFIED_END_NAMESPACE
