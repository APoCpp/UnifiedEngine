#include <unified/core/exceptions.hpp>

#include <string>
#include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

initialization_failed::initialization_failed(char const *target) : _target(target) { }

const char *initialization_failed::what() const _UNIFIED_NOEXCEPT {
    return _target;
}

UNIFIED_END_NAMESPACE
