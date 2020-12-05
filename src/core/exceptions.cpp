#include <unified/core/exceptions.hpp>

UNIFIED_BEGIN_NAMESPACE

initialization_failed::initialization_failed(const char *message) : _message(message) { }

const char *initialization_failed::what() const UNIFIED_NOEXCEPT {
    return _message;
}

UNIFIED_END_NAMESPACE
