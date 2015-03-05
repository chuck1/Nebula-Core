#include <neb/fnd/util/cast.hpp>
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/core/scene/util/parent.hpp>
#include <neb/fnd/game/map/base.hpp>
#include <neb/fnd/game/game/util/parent.hpp>
#include <neb/fnd/game/trigger/util/parent.hpp>
#include <neb/fnd/game/trigger/ActorEx1.hpp>

typedef neb::fnd::game::trigger::ActorEx1 THIS;

THIS::ActorEx1(std::shared_ptr<neb::fnd::game::trigger::util::parent> parent):
	gal::stl::child<neb::fnd::game::trigger::util::parent>(parent.get())
{
}
void			THIS::connect(std::shared_ptr<neb::fnd::core::actor::base> actor) {
	
	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));
	
	typedef boost::signals2::signal<void()> signal_type;

	actor->sig_release_.connect(
			signal_type::slot_type(
				&THIS::doSomething,
				self
				).track_foreign(self)
			);
}
void			THIS::doSomething()
{
	auto map = getParent()->is_fnd_game_map_base();

	auto scene = map->get_scene();
	
	auto scene_parent = scene->getParent();
	
	scene_parent->neb::fnd::core::scene::util::parent::erase(scene->get_index());
	
	// message
	//auto app = neb::fnd::app::Base::global();
	auto app = get_fnd_app();
	
	if(app->console_) app->console_->operator<<("you won!");
	
	//scene->getParent()->erase(scene->i_);
	
//	auto gp(game->parent_.lock());
	
//	gp->erase(parent->i_);
	
}

