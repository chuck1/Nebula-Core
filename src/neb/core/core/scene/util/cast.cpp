
#include <neb/fnd/core/scene/base.hpp>
#include <neb/fnd/core/scene/util/cast.hpp>

shared_ptr<neb::fnd::core::scene::base>		neb::fnd::core::scene::util::cast::isSceneBase() {
	auto scene(dynamic_pointer_cast<neb::fnd::core::scene::base>(shared_from_this()));
	return scene;
}

