
#include <neb/fnd/core/actor/Base.hpp>

#include <neb/fnd/net/msg/actor/Create.hpp>

void		neb::net::msg::actor::Create::load(std::shared_ptr<neb::fnd::core::actor::base> actor)
{
	assert(actor);

	parent_i_ = actor->getParent()->get_index();
	
	i_ = actor->get_index();
	
	wrapper_.ptr_ = actor;
}





