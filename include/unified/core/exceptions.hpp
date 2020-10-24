#include <unified/defines.hpp>

#ifndef UNIFIED_CORE_EXCEPTIONS_HPP
#define UNIFIED_CORE_EXCEPTIONS_HPP

#include <defines.hpp>
#include <exception>

UNIFIED_BEGIN_NAMESPACE

class initialization_failed : public std::exception
{
public:

    initialization_failed(const char *target);
    virtual ~initialization_failed() = default;

    virtual const char *what() const _OSL_NOEXCEPT;

protected:

    const char *_target;

};

#define EXCEPTION_INITIALIZATION_FAILED(content) \
    Unified::initialization_failed(content)

UNIFIED_END_NAMESPACE

#endif
