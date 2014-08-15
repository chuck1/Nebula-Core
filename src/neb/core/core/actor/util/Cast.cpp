
#include <neb/core/actor/base.hpp>
#include <neb/core/actor/util/Cast.hh>

shared_ptr<neb::core::actor::base>		neb::core::actor::util::cast::isActorBase() {
	auto actor(dynamic_pointer_cast<neb::core::actor::base>(shared_from_this()));
	return actor;
}

