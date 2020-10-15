#include <exception>
#include <fmt/format.h>

#ifndef UNIFIED_CORE_EXCEPTIONS_HPP
#define UNIFIED_CORE_EXCEPTIONS_HPP

#define URE_INITIALIZATION_FAILED(content) \
    std::runtime_error(fmt::format("initialization of {} failed", content))

#endif