#include <unified/core/exceptions.hpp>

#include <string>
#include <fmt/format.h>

Unified::initialization_failed::initialization_failed(const char *target) { 
    _target = new std::string(
        fmt::format("initialization of {} failed", target)
    );
}

Unified::initialization_failed::~initialization_failed() {
    delete _target;
}

const char *Unified::initialization_failed::what() const _OSL_NOEXCEPT {
    return _target->c_str();
}