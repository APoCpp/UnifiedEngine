#include <unified/application/layer.hpp>

UNIFIED_BEGIN_NAMESPACE

Layer *Layer::set_application_context(Application *application) {
    this->application = application;
    return this;
}

UNIFIED_END_NAMESPACE
