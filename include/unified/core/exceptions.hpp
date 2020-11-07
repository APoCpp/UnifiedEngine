#ifndef UNIFIED_CORE_EXCEPTIONS_HPP
#define UNIFIED_CORE_EXCEPTIONS_HPP

#include <unified/defines.hpp>
#include <exception>

UNIFIED_BEGIN_NAMESPACE

class initialization_failed : public std::exception
{
public:

    initialization_failed(char const *target);
    virtual ~initialization_failed() = default;

    virtual char const *what() const _UNIFIED_NOEXCEPT;

protected:

    char const *_target;

};

#define EXCEPTION_INITIALIZATION_FAILED(content) \
    initialization_failed(content)

UNIFIED_END_NAMESPACE

#endif
