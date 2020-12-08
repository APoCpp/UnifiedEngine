#ifndef _UNIFIED_CORE_EXCEPTIONS_HPP
#define _UNIFIED_CORE_EXCEPTIONS_HPP

# include <unified/defines.hpp>
# include <exception>

# define GENERATE_EXCEPTION_CLASS(class_name) \
    class class_name : public std::exception \
    { \
    public: \
        class_name(const char *message) : _message(message) { } \
        virtual const char *what() const UNIFIED_NOEXCEPT { \
            return _message; \
        } \
    protected: \
        const char *_message; \
    } \

UNIFIED_BEGIN_NAMESPACE

namespace Exceptions
{

    GENERATE_EXCEPTION_CLASS(initialization_failed);
    GENERATE_EXCEPTION_CLASS(misbehavior);

}

UNIFIED_END_NAMESPACE

#endif
