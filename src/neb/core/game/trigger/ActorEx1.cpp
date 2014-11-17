#include <neb/core/util/cast.hpp>
#include <neb/core/app/__base.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/scene/base.hpp>
#include <neb/core/core/scene/util/parent.hpp>
#include <neb/core/game/game/base.hpp>
#include <neb/core/game/game/util/parent.hpp>
#include <neb/core/game/trigger/util/parent.hpp>
#include <neb/core/game/trigger/ActorEx1.hpp>

typedef neb::core::game::trigger::ActorEx1 THIS;

THIS::ActorEx1(std::shared_ptr<nc::game::trigger::util::parent> parent):
	gal::stl::child<nc::game::trigger::util::parent>(parent.get())
{
}
void				THIS::connect(std::shared_ptr<neb::core::core::actor::base> actor) {
	
	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));
	
	typedef boost::signals2::signal<void()> signal_type;

	actor->sig_release_.connect(
			signal_type::slot_type(
				&THIS::doSomething,
				self
				).track_foreign(self)
			);
}
void				THIS::doSomething()
{
	
	auto game = neb::is<parent_t, nc::game::game::base>(getParent());
	auto scene(game->scene_.lock());
	
	if(!scene) return;

	auto scene_parent = scene->getParent();
	
	scene_parent->nc::core::scene::util::parent::erase(scene->_M_index);
	
	// message
	auto app = neb::core::app::__base::global();
	if(app->console_) app->console_->operator<<("you won!");

	//scene->getParent()->erase(scene->i_);
	
//	auto gp(game->parent_.lock());
	
//	gp->erase(parent->i_);
	
}

