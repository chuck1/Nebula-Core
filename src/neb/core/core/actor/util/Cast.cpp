
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/actor/util/Cast.hpp>

std::shared_ptr<neb::fnd::core::actor::base>		neb::fnd::core::actor::util::Cast::is_fnd_actor_base()
{
	auto actor(dynamic_pointer_cast<neb::fnd::core::actor::base>(shared_from_this()));
	return actor;
}

