#include <exception>
#include <iosfwd>

#ifndef UNIFIED_CORE_EXCEPTIONS_HPP
#define UNIFIED_CORE_EXCEPTIONS_HPP

namespace Unified
{
    class initialization_failed : public std::exception
    {
    public:

        initialization_failed(const char *target);
        virtual ~initialization_failed();

        virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;

    protected:

        std::string *_target;

    };
}

#define EXCEPTION_INITIALIZATION_FAILED(content) \
    Unified::initialization_failed(content)

#endif