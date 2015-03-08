#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>
#include <neb/fnd/camera/view/Ridealong.hpp>

#include <neb/fnd/plug/gfx/environ/Base.hpp>

typedef neb::fnd::environ::SceneDefault THIS;

std::weak_ptr<neb::fnd::camera::view::Ridealong>		THIS::create_view_ridealong(
		std::weak_ptr<neb::fnd::core::actor::base> actor)
{
	printf("%s\n", __PRETTY_FUNCTION__);
	//auto self(std::dynamic_pointer_cast<neb::gfx::environ::three>(shared_from_this()));

	typedef neb::fnd::camera::view::Ridealong T;
	
	std::shared_ptr<T> view(new T());
	view->actor_ = actor;
	view->init(this);

	view_ = view;

	return view;
}
void			THIS::release()
{
}
void			THIS::init(parent_t * const & p)
{
	setParent(p);

	auto app = get_fnd_app();

	if(app->G::has_object())
	G::make_object<THIS, int>(
			app->get_graphics_plugin(),
			neb::fnd::plug::gfx::environ::type::SCENE_DEFAULT);

	//neb::fnd::environ::SceneDefault::init(p);
	neb::fnd::environ::Base::init(p);

	// default projection camera
	createCameraPerspective();
}

