#ifndef _UNIFIED_CORE_EXCEPTIONS_HPP
#define _UNIFIED_CORE_EXCEPTIONS_HPP

# include <unified/defines.hpp>
# include <exception>

UNIFIED_BEGIN_NAMESPACE

class initialization_failed : public std::exception
{
public:

    initialization_failed(const char *message);
    virtual ~initialization_failed();

    virtual const char *what() const UNIFIED_NOEXCEPT;

protected:

    const char *_message;

};

UNIFIED_END_NAMESPACE

# define EXCEPTION_INITIALIZATION_FAILED(content) \
     initialization_failed(content)

#endif
