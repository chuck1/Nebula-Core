#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/actor/rigidactor/Base.hpp>
#include <neb/fnd/game/spawn/util/parent.hpp>

typedef neb::fnd::game::spawn::util::parent THIS;

THIS::parent()
{
}
THIS::~parent()
{
}
void		THIS::init()
{
}
void		THIS::spawn_actor(std::shared_ptr<neb::fnd::core::actor::base> actor)
{
	auto s = front();
	assert(s);

	auto ra = actor->is_fnd_actor_rigidactor_base();

	ra->set_pose_global(s->pose_);
}
std::weak_ptr<neb::fnd::game::spawn::base>		THIS::create_spawn(neb::fnd::math::pose pose)
{
	typedef neb::fnd::game::spawn::base T;
	std::shared_ptr<T> spawn(new T);
	
	neb::fnd::game::spawn::util::parent::insert(spawn);
	
	spawn->pose_ = pose;

	return spawn;
}

