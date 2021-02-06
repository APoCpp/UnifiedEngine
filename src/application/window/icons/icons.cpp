#include <unified/application/window/icons/icons.hpp>

# include <GLFW/glfw3.h>
# include <stb_image.h>
# include <vector>

UNIFIED_BEGIN_NAMESPACE

struct Icons::glfw_images_wrapper
{
    std::vector<GLFWimage> handle;
};

Icons::Icons() : _images(new glfw_images_wrapper) { }

Icons::Icons(const Unified::string &icons) : _images(new glfw_images_wrapper) {
    add_icon(icons);
}

Icons::Icons(std::initializer_list<string> icons) : _images(new glfw_images_wrapper) {
    for (const auto &icon : icons) {
        add_icon(icon);
    }
}

Icons::~Icons() {
    for (const auto &icon : _images->handle) {
        stbi_image_free(icon.pixels);
    }
    delete _images;
}

void Icons::add_icon(const Unified::string &icon) {
    GLFWimage image;
    image.pixels = stbi_load(icon.c_str(), &image.width, &image.height, 0, 4);
    _images->handle.push_back(image);
}

u32 Icons::count() const {
    return _images->handle.size();
}

void *Icons::data() {
    return _images->handle.data();
}

UNIFIED_END_NAMESPACE
