
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/actor/rigidactor/Base.hpp>
#include <neb/fnd/core/actor/rigidbody/Base.hpp>
#include <neb/fnd/core/actor/util/Cast.hpp>

typedef neb::fnd::core::actor::base T;
std::shared_ptr<T>		neb::fnd::core::actor::util::Cast::is_fnd_actor_base()
{
	auto actor(std::dynamic_pointer_cast<T>(shared_from_this()));
	return actor;
}
typedef neb::fnd::core::actor::rigidactor::base T1;
std::shared_ptr<T1>		neb::fnd::core::actor::util::Cast::is_fnd_actor_rigidactor_base()
{
	auto actor(dynamic_pointer_cast<T1>(shared_from_this()));
	return actor;
}
typedef neb::fnd::core::actor::rigidbody::base T2;
std::shared_ptr<T2>		neb::fnd::core::actor::util::Cast::is_fnd_actor_rigidbody_base()
{
	auto actor(dynamic_pointer_cast<T2>(shared_from_this()));
	return actor;
}

