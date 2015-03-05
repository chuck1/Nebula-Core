#include <neb/fnd/core/shape/util/decl.hpp>
#include <neb/fnd/core/shape/util/cast.hpp>
#include <neb/fnd/core/shape/base.hpp>

typedef neb::fnd::core::shape::util::cast THIS;

std::shared_ptr<neb::fnd::core::shape::base>		THIS::isShapeBase()
{
        return std::dynamic_pointer_cast<neb::fnd::core::shape::base>(shared_from_this());
}


