#ifndef _UNIFIED_APPLICATION_WINDOW_ICONS_ICONS_HPP
#define _UNIFIED_APPLICATION_WINDOW_ICONS_ICONS_HPP

# include <unified/core/int_types.hpp>
# include <unified/core/string.hpp>

# include <initializer_list>

UNIFIED_BEGIN_NAMESPACE

class Icons
{
protected:

    struct glfw_images_wrapper;

public:

    Icons();
    Icons(const string &icon);
    Icons(std::initializer_list<string> icons);

    virtual ~Icons();

    void add_icon(const string &icon);

    u32 count() const;

    void *data();

protected:

    glfw_images_wrapper *_images;

};

UNIFIED_END_NAMESPACE

#endif
