#include <neb/fnd/environ/SceneDefault.hpp>
#include <neb/fnd/camera/view/Ridealong.hpp>

typedef neb::fnd::environ::SceneDefault THIS;

std::weak_ptr<neb::fnd::camera::view::Ridealong>		THIS::create_view_ridealong(
		std::weak_ptr<neb::fnd::core::actor::base> actor)
{
	//auto self(std::dynamic_pointer_cast<neb::gfx::environ::three>(shared_from_this()));

	typedef neb::fnd::camera::view::Ridealong T;
	
	std::shared_ptr<T> view(new T());
	view->actor_ = actor;
	view->init(this);

	view_ = view;

	return view;
}

