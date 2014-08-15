#include <gal/log/log.hpp>

#include <neb/core/util/log.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/actor/util/parent.hpp>
#include <neb/core/core/scene/base.hpp>

neb::core::core::actor::util::parent::parent() {
}
neb::core::core::actor::util::parent::~parent() {
}
void							neb::core::core::actor::util::parent::init() {

}
void							neb::core::core::actor::util::parent::release() {

}
sp::shared_ptr<neb::core::core::scene::base>		neb::core::core::actor::util::parent::getScene() {

	LOG(lg, neb::core::core::actor::sl, debug) << __FUNCSIG__;

	auto scene(::std::dynamic_pointer_cast<neb::core::core::scene::base>(shared_from_this()));

	if(scene) return scene;

	auto actor(::std::dynamic_pointer_cast<neb::core::core::actor::base>(shared_from_this()));

	if(!actor) throw 0;

	return actor->getScene();
}

